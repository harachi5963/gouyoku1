#include "GameScene.h"

#include <DxLib.h>

#include "../../Application.h"
#include "../../Camera/Camera.h"

#include "../../Object/Actor/ActorBase.h"
#include "../../Object/Actor/Player/Player.h"
#include "../../Object/Actor/Enemy/Enemy.h"
#include "../../Object/Actor/Object/Pc.h"
#include "../../Object/Actor/Stage/Stage.h"
#include "../../Object/Actor/Object/VendingMachine.h"
#include "../../Object/Actor/Object/Basketball.h"
#include "../../Object/Actor/Object/Soccerball.h"
#include "../../Object/Actor/Object/Tenisuball.h"
#include "../../Object/Actor/Object/Volleyball.h"
#include "../../Object/Actor/Object/Door.h"
#include "../../Object/Actor/Object/Door2.h"
#include "../../Object/Actor/Object/Tirasi.h"
#include "../../Object/Actor/Object/Calender.h"
#include "../../Object/Actor/Object/Desuku.h"
#include "../../Object/Actor/Object/Chair.h"
#include "../../Object/Actor/Object/Kasatate/Kasatate.h"
#include "../../Object/Actor/Object/Projector.h"
#include "../../Object/Actor/Object/Tokei.h"

#include "../../Utility/AsoUtility.h"
#include "../../Input/InputManager.h"
#include "../SceneManager.h"
#include "../../Audio/AudioManager.h"

GameScene::GameScene(void)
{
}

GameScene::~GameScene(void)
{
}

void GameScene::Init(void)
{
	// カメラの初期化
	camera_->Init();

	// ステージ初期化
	stage_->Init();

	// 全てのアクターを初期化
	for (auto actor : allActor_)
	{
		// 初期化
		actor->Init();
	}
}

void GameScene::Load(void)
{
	// 生成処理
	camera_ = new Camera();						// カメラの生成
	stage_ = new Stage();						// ステージの生成

	// アクターの生成
	ActorBase* player_ = new Player(camera_);	// プレイヤーの生成
	ActorBase* vendingMachine = new VendingMachine();	// 自販機を生成
	ActorBase* door = new Door();						// ドアを生成
	ActorBase* door2 = new Door2();						// ドアを生成
	ActorBase* basketball = new Basketball();						// ドアを生成
	ActorBase* soccerball = new Soccerball();						// ドアを生成
	ActorBase* tenisuball = new Tenisuball();						// ドアを生成
	ActorBase* volleyball = new Volleyball();						// ドアを生成
	ActorBase* pc = new Pc();										// ドアを生成
	ActorBase* tirasi = new Tirasi();								// チラシを生成
	ActorBase* kasatate = new Kasatate();
	ActorBase* projector = new Projector();							//プロジェクター
	ActorBase* tokei = new Tokei();

	Calender* calender = new Calender();

	//机を生成
	Desuku* desuku1 = new Desuku();
	desuku1->SetDesuku(
		"Data/object/Desuku/desuku.mv1",
		{ 1195.352173f,0.000122f,-340.0f },
		{ 5.0f, 2.5f, 3.5f },
		{ 0.0f,300.0f,0.0f }
	);

	//机を生成
	Desuku* desuku2 = new Desuku();
	desuku2->SetDesuku(
		"Data/object/Desuku/desuku.mv1",
		{ 895.352173f,0.000122f,-340.0f },
		{ 5.5f, 2.5f, 3.5f },
	    { 0.0f,300.0f,0.0f }
	);
	//机を生成
	Desuku* desuku3 = new Desuku();
	desuku3->SetDesuku(
		"Data/object/Desuku/desuku.mv1",
		{ 595.352173f,0.000122f,-340.0f },
		{ 5.0f, 2.5f, 3.5f },
		{ 0.0f,300.0f,0.0f }
	);
	//椅子を生成
	Chair* chair1 = new Chair();
	chair1->SetChair(
		"Data/object/Chair/Chair2.mv1",
		{ 710.069336f,0.000103f,-240.8284 },
		{ 1.7f,1.7f,1.7f },
		{ 0.0f,0.0f,0.0f }
	);
	//椅子を生成
	Chair* chair2 = new Chair();
	chair2->SetChair(
		"Data/object/Chair/Chair2.mv1",
		{ 810.069336f,0.000103f,-240.8284 },
		{ 1.7f,1.7f,1.7f },
		{ 0.0f,0.0f,0.0f }
	);
	//椅子を生成
	Chair* chair3 = new Chair();
	chair3->SetChair(
		"Data/object/Chair/Chair2.mv1",
		{ 810.069336f,0.000103f,-240.8284 },
		{ 1.7f,1.7f,1.7f },
		{ 0.0f,0.0f,0.0f }
	);
	// アクター配列に入れる
	allActor_.push_back(player_);
	allActor_.push_back(vendingMachine);
	allActor_.push_back(door);
	allActor_.push_back(door2);
	allActor_.push_back(basketball);
	allActor_.push_back(soccerball);
	allActor_.push_back(tenisuball);
	allActor_.push_back(volleyball);
	allActor_.push_back(pc);
	allActor_.push_back(tirasi);
	allActor_.push_back(calender);
	allActor_.push_back(kasatate);
	allActor_.push_back(projector);
	allActor_.push_back(tokei);
	allActor_.push_back(desuku1);
	allActor_.push_back(desuku2);
	allActor_.push_back(desuku3);
	allActor_.push_back(chair1);
	allActor_.push_back(chair2);
	allActor_.push_back(chair3);


	// カメラモード変更
	camera_->SetFollow(player_);
	camera_->ChangeMode(Camera::MODE::FOLLOW);

	// ステージの読み込み
	stage_->Load();

	// 全てのアクターを読み込み
	for (auto actor : allActor_)
	{
		// 読み込み
		actor->Load();
	}

	AudioManager::GetInstance()->LoadSceneSound(LoadScene::GAME);
}

void GameScene::LoadEnd(void)
{
	// カメラの初期化
	camera_->Init();

	// ステージ初期化
	stage_->LoadEnd();

	// 全てのアクターを読み込み後
	for (auto actor : allActor_)
	{
		// 読み込み
		actor->LoadEnd();
	}

	AudioManager::GetInstance()->PlayBGM(SoundID::BGM_BATTLE);
}

void GameScene::Update(void)
{
	// カメラの更新
	camera_->Update();

	// ステージ更新
	stage_->Update();

	// 全てのアクターを回す
	for (auto actor : allActor_)
	{
		// 更新処理
		actor->Update();

		// 当たり判定を取るか？
		if (actor->GetisCollision())
		{
			// 当たり判定
			FieldCollision(actor);
			WallCollision(actor);
		}
	}

	// ドアとの当たり判定
	isDoorCollision();
}

void GameScene::Draw(void)
{
	// カメラの描画更新
	camera_->SetBeforeDraw();

	// ステージ描画
	stage_->Draw();


	// 全てのアクターを回す
	for (auto actor : allActor_)
	{
		// 更新処理
		actor->Draw();
	}
}

void GameScene::Release(void)
{
	// ステージ解放
	stage_->Release();
	delete stage_;


	// 全てのアクターを回す
	for (auto actor : allActor_)
	{
		// 更新処理
		actor->Release();
		delete actor;
	}

	// 配列をクリア
	allActor_.clear();
	AudioManager::GetInstance()->DeleteSceneSound(LoadScene::GAME);
}

void GameScene::isDoorCollision(void)
{
	// プレイヤーの座標保持用
	ActorBase* player = nullptr;

	// カレンダー保持用
	Calender* calender = nullptr;

	// 全てのオブジェクトを回す
	for (auto actor : allActor_)
	{
		// プレイヤーだったら
		if (actor->GetTag() == ActorBase::TAG::PLAYER)
		{
			player = actor;
		}
	}

	// 全てのオブジェクトを回す
	for (auto actor : allActor_)
	{
		// プレイヤーだったら
		if (actor->GetTag() == ActorBase::TAG::CALENDER)
		{
			calender = dynamic_cast<Calender*>(actor);
		}
	}

	// 全てのオブジェクトを回す
	for (auto actor : allActor_)
	{
		// ドアじゃないなら判定しない
		if (actor->GetTag() != ActorBase::TAG::DOOR)
		{
			// ドアじゃないのでこのオブジェクトをスキップ
			continue;
		}

		// オブジェクトとカメラが接触しているか？
		if (AsoUtility::IsHitSpheres(
			actor->GetPos(),
			actor->GetSphereRadius(),
			player->GetPos(),
			player->GetSphereRadius()
		))
		{
			// キーが押されているか？
			if (InputManager::GetInstance()->IsTrgDown(KEY_INPUT_F))
			{
				// カメラを初期位置に
				player->Init();

				// ドアを開いた
				isDoorOpen();

				calender->SetCalender(Calender::CALENDER::FEB);
			}

			//スペースキーが押されたら
			if (InputManager::GetInstance()->IsTrgUp(KEY_INPUT_SPACE))
			{
				//ゲームシーンへ
				SceneManager::GetInstance()->ChangeScene(SceneManager::SCENE_ID::CLEAR);
				return;
			}
		}
	}
}

void GameScene::isDoorOpen(void)
{
	//異変の数検索用
	int ihenNum = 0;

	// 全てのオブジェクトを回す
	for (auto actor : allActor_)
	{
		if (actor->GetTag() != ActorBase::TAG::IHEN_OBJECT)
		{
			// 異変オブジェクトじゃないのでスキップ
			continue;
		}
		ihenNum++;
		// 異変オブジェクトを発見
		/*actor->SetIhen(true);*/
	}

	int ihenact = GetRand(ihenNum - 1);
	ihenNum = 0;
	for (auto actor : allActor_)
	{
		if (actor->GetTag() != ActorBase::TAG::IHEN_OBJECT)
		{
			// 異変オブジェクトじゃないのでスキップ
			continue;
		}
		ihenNum++;
		if (ihenNum == ihenact)
		{
			actor->SetIhen(true);
		}
		// 異変オブジェクトを発見
		/*actor->SetIhen(true);*/
	}
}

// ステージの床とプレイヤーの衝突
void GameScene::FieldCollision(ActorBase* actor)
{
	// 座標を所得
	VECTOR actorPos = actor->GetPos();

	// 線分の上座標
	VECTOR startPos = actorPos;
	startPos.y = actorPos.y + 10.0f;

	// 線分の下座標
	VECTOR endPos = actorPos;
	endPos.y = actorPos.y - 10.0f;

	// ステージのモデルを取得
	int modelId = stage_->GetModelId();

	// 線分とモデルの衝突判定
	MV1_COLL_RESULT_POLY res =
		MV1CollCheck_Line(modelId, -1, startPos, endPos);

	// ステージに当たっているか？
	if (res.HitFlag)
	{
		// 当たった場所に戻す
		actor->CollisionStage(res.HitPosition);
	}
}

void GameScene::WallCollision(ActorBase* actor)
{
	// 座標を取得
	VECTOR pos = actor->GetPos();

	// カプセルの座標
	VECTOR capStartPos = VAdd(pos, actor->GetStartCapsulePos());
	VECTOR capEndPos = VAdd(pos, actor->GetEndCapsulePos());

	// カプセルとの当たり判定
	auto hits = MV1CollCheck_Capsule
	(
		stage_->GetModelId(),			// ステージのモデルID
		-1,								// ステージ全てのポリゴンを指定
		capStartPos,					// カプセルの上
		capEndPos,						// カプセルの下
		actor->GetCapsuleRadius()		// カプセルの半径
	);

	// 衝突したポリゴン全ての検索
	for (int i = 0; i < hits.HitNum; i++)
	{
		// ポリゴンを1枚に分割
		auto hit = hits.Dim[i];

		// ポリゴン検索を制限(全てを検索すると重いので)
		for (int tryCnt = 0; tryCnt < 10; tryCnt++)
		{
			// 最初の衝突判定で検出した衝突ポリゴン1枚と衝突判定を取る
			int pHit = HitCheck_Capsule_Triangle
			(
				capStartPos,					// カプセルの上
				capEndPos,						// カプセルの下
				actor->GetCapsuleRadius(),		// カプセルの半径
				hit.Position[0],				// ポリゴン1
				hit.Position[1],				// ポリゴン2
				hit.Position[2]					// ポリゴン3
			);

			// カプセルとポリゴンが当たっていた
			if (pHit)
			{
				// 当たっていたので座標をポリゴンの法線方向に移動させる
				pos = VAdd(pos, VScale(hit.Normal, 1.0f));

				// 球体の座標も移動させる
				capStartPos = VAdd(capStartPos, VScale(hit.Normal, 1.0f));
				capEndPos = VAdd(capEndPos, VScale(hit.Normal, 1.0f));

				// 複数当たっている可能性があるので再検索
				continue;
			}
		}
	}
	// 検出したポリゴン情報の後始末
	MV1CollResultPolyDimTerminate(hits);

	// 計算した場所にアクターを戻す
	actor->CollisionStage(pos);
}
