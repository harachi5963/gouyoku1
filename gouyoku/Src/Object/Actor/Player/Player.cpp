#include "Player.h"

#include "../../../Application.h"
#include "../../../Input/InputManager.h"
#include "../../../Utility/AsoUtility.h"
#include "../../../Utility/MatrixUtility.h"
#include "../../Common/AnimationController.h"

#include "../../../Camera/Camera.h"
#include "../../../Audio/AudioManager.h"

Player::Player(Camera* camera)
{
	camera_ = camera;
}

Player::~Player(void)
{
}

void Player::InitLoad(void)
{
	// モデルの読み込み
	modelId_ = MV1LoadModel((Application::PATH_MODEL + "Player/Player.mv1").c_str());

	// モデルの上側にポイントタイプのライトを作成
	LightHandle = CreatePointLightHandle(
		VGet(320.0f, 1500.0f, 600.0f),
		10000.0f,
		0.3f,
		0.002f,
		0.0f);

	SetLightPositionHandle(LightHandle, pos_);
}

void Player::InitTransform(void)
{
	// モデルの角度
	angle_ = { 0.0f, 0.0f, 0.0f };
	localAngle_ = { 0.0f, AsoUtility::Deg2RadF(180.0f), 0.0f };

	// 角度から方向に変換する
	moveDir_ = { sinf(angle_.y), 0.0f, cosf(angle_.y) };
	preInputDir_ = moveDir_;

	// 行列の合成(子, 親と指定すると親⇒子の順に適用される)
	MATRIX mat = MatrixUtility::Multiplication(localAngle_, angle_);

	// 回転行列をモデルに反映
	MV1SetRotationMatrix(modelId_, mat);

	// モデルの位置設定
	pos_ = {-2117.643555f,0.000185f,-697.131470f};
	MV1SetPosition(modelId_, pos_);
}

void Player::InitAnimation(void)
{
	// モデルアニメーション制御の初期化
	animationController_ = new AnimationController(modelId_);

	// アニメーションの追加
	animationController_->Add(
		static_cast<int>(ANIM_TYPE::IDLE), 0.5f, Application::PATH_MODEL + "Player/Idle.mv1");
	animationController_->Add(
		static_cast<int>(ANIM_TYPE::WALK), 0.5f, Application::PATH_MODEL + "Player/Walk.mv1");
	animationController_->Add(
		static_cast<int>(ANIM_TYPE::RUN), 1.5f, Application::PATH_MODEL + "Player/Walk.mv1");

	// 初期アニメーションの再生
	animationController_->Play(static_cast<int>(ANIM_TYPE::IDLE));
}

void Player::InitPost(void)
{
	// タグの設定
	tag_ = TAG::PLAYER;

	// 当たり判定を作成
	startCapsulePos_ = { 0.0f,150,0.0f };
	endCapsulePos_ = { 0.0f,0.0f,0.0f };
	capsuleRadius_ = 20.0f;

	sphereRadius_ = 20.0f;

	isGravity_ = true;

	// 当たり判定を取るか
	isCollision_ = true;

}

void Player::Update(void)
{
	ActorBase::Update();

	// アニメーションの更新
	animationController_->Update();
	SetLightPositionHandle(LightHandle, pos_);
}

void Player::Draw(void)
{
	ActorBase::Draw();
	//DrawFormatString(
	//	0, 50, 0xffffff,
		//"キャラ座標　 ：(%f, %f, %f)",
		//pos_.x,
		//pos_.y,
		//pos_.z
	//);

	//DrawSphere3D(VAdd(startCapsulePos_, pos_), capsuleRadius_, 16, 0xff0000, 0xff0000, true);
	//DrawSphere3D(VAdd(endCapsulePos_, pos_), capsuleRadius_, 16, 0xff0000, 0xff0000, true);
}

void Player::Release(void)
{
	ActorBase::Release();

	// ライトハンドルの削除
	DeleteLightHandle(LightHandle);
}

void Player::Move(void)
{
	// カメラ角度を取得
	VECTOR cameraAngles = camera_->GetAngle();

	// 移動量
	VECTOR dir = AsoUtility::VECTOR_ZERO;

	// ゲームパッドが接続数で処理を分ける
	if (GetJoypadNum() == 0)
	{
		// WASDで移動する
		if (InputManager::GetInstance()->IsNew(KEY_INPUT_W)) { dir = { 0.0f, 0.0f, 1.0f }; }
		if (InputManager::GetInstance()->IsNew(KEY_INPUT_A)) { dir = { -1.0f, 0.0f, 0.0f }; }
		if (InputManager::GetInstance()->IsNew(KEY_INPUT_S)) { dir = { 0.0f, 0.0f, -1.0f }; }
		if (InputManager::GetInstance()->IsNew(KEY_INPUT_D)) { dir = { 1.0f, 0.0f, 0.0f }; }
	}
	else
	{
		// 接続されているゲームパッド１の情報を取得
		InputManager::JOYPAD_IN_STATE padState =
			InputManager::GetInstance()->GetJPadInputState(InputManager::JOYPAD_NO::PAD1);

		// アナログキーの入力値から方向を取得
		dir = InputManager::GetInstance()->GetDirectionXZAKey(padState.AKeyLX, padState.AKeyLY);

	}

	if (!AsoUtility::EqualsVZero(dir))
	{
		AudioManager::GetInstance()->PlaySE(SoundID::SE_WORK);

		// 入力値の補間
		const float SMOOTH = 0.25f; // 小さいほど慣性が強い
		dir.x = preInputDir_.x + (dir.x - preInputDir_.x) * SMOOTH;
		dir.z = preInputDir_.z + (dir.z - preInputDir_.z) * SMOOTH;
		preInputDir_ = dir;

		// 正規化
		dir = VNorm(dir);

		// XYZの回転行列
		// XZ平面移動にする場合は、XZの回転を考慮しないようにする
		MATRIX mat = MGetIdent();
		mat = MMult(mat, MGetRotY(cameraAngles.y));

		// 回転行列を使用して、ベクトルを回転させる
		moveDir_ = VTransform(dir, mat);

		// 走り
		if (InputManager::GetInstance()->IsNew(KEY_INPUT_LSHIFT))
		{
			// 方向×スピードで移動量を作って、座標に足して移動
			pos_ = VAdd(pos_, VScale(moveDir_, RUN_POW));

			// 歩くアニメーションの再生
			animationController_->Play(static_cast<int>(ANIM_TYPE::RUN));
		}
		else
		{
			// 方向×スピードで移動量を作って、座標に足して移動
			pos_ = VAdd(pos_, VScale(moveDir_, MOVE_POW));

			// 歩くアニメーションの再生
			animationController_->Play(static_cast<int>(ANIM_TYPE::WALK));
		}
	}
	else
	{
		// 待機アニメーションの再生
		animationController_->Play(static_cast<int>(ANIM_TYPE::IDLE));
	}
}
