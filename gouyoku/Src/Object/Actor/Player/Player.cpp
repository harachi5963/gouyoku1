#include "Player.h"

#include "../../../Application.h"
#include "../../../Input/InputManager.h"
#include "../../../Utility/AsoUtility.h"
#include "../../../Utility/MatrixUtility.h"
#include "../../Common/AnimationController.h"

#include "../../../Camera/Camera.h"

Player::Player(Camera* camera)
{
	camera_ = camera;
}

Player::~Player(void)
{
}

void Player::InitLoad(void)
{
	// ���f���̓ǂݍ���
	modelId_ = MV1LoadModel((Application::PATH_MODEL + "Player/Player.mv1").c_str());
}

void Player::InitTransform(void)
{
	// ���f���̊p�x
	angle_ = { 0.0f, 0.0f, 0.0f };
	localAngle_ = { 0.0f, AsoUtility::Deg2RadF(180.0f), 0.0f };

	// �p�x��������ɕϊ�����
	moveDir_ = { sinf(angle_.y), 0.0f, cosf(angle_.y) };
	preInputDir_ = moveDir_;

	// �s��̍���(�q, �e�Ǝw�肷��Ɛe�ˎq�̏��ɓK�p�����)
	MATRIX mat = MatrixUtility::Multiplication(localAngle_, angle_);

	// ��]�s������f���ɔ��f
	MV1SetRotationMatrix(modelId_, mat);

	// ���f���̈ʒu�ݒ�
	pos_ = AsoUtility::VECTOR_ZERO;
	MV1SetPosition(modelId_, pos_);
}

void Player::InitAnimation(void)
{
	// ���f���A�j���[�V��������̏�����
	animationController_ = new AnimationController(modelId_);

	// �A�j���[�V�����̒ǉ�
	animationController_->Add(
		static_cast<int>(ANIM_TYPE::IDLE), 0.5f, Application::PATH_MODEL + "Player/Idle.mv1");
	animationController_->Add(
		static_cast<int>(ANIM_TYPE::WALK), 0.5f, Application::PATH_MODEL + "Player/Walk.mv1");
	animationController_->Add(
		static_cast<int>(ANIM_TYPE::RUN), 1.5f, Application::PATH_MODEL + "Player/Walk.mv1");

	// �����A�j���[�V�����̍Đ�
	animationController_->Play(static_cast<int>(ANIM_TYPE::IDLE));
}

void Player::InitPost(void)
{
	// �^�O�̐ݒ�
	tag_ = TAG::PLAYER;

	// �����蔻����쐬
	startCapsulePos_ = { 0.0f,110,0.0f };
	endCapsulePos_ = { 0.0f,30.0f,0.0f };
	capsuleRadius_ = 20.0f;

	sphereRadius_ = 20.0f;

	isGravity_ = true;

	// �����蔻�����邩
	isCollision_ = true;

}

void Player::Update(void)
{
	ActorBase::Update();

	// �A�j���[�V�����̍X�V
	animationController_->Update();
}

void Player::Draw(void)
{
	ActorBase::Draw();
	DrawFormatString(
		0, 50, 0xffffff,
		"�L�������W�@ �F(%f, %f, %f)",
		pos_.x,
		pos_.y,
		pos_.z
	);
}

void Player::Release(void)
{
	ActorBase::Release();
}

void Player::Move(void)
{
	// �J�����p�x���擾
	VECTOR cameraAngles = camera_->GetAngle();

	// �ړ���
	VECTOR dir = AsoUtility::VECTOR_ZERO;

	// �Q�[���p�b�h���ڑ����ŏ����𕪂���
	if (GetJoypadNum() == 0)
	{
		// WASD�ňړ�����
		if (InputManager::GetInstance()->IsNew(KEY_INPUT_W)) { dir = { 0.0f, 0.0f, 1.0f }; }
		if (InputManager::GetInstance()->IsNew(KEY_INPUT_A)) { dir = { -1.0f, 0.0f, 0.0f }; }
		if (InputManager::GetInstance()->IsNew(KEY_INPUT_S)) { dir = { 0.0f, 0.0f, -1.0f }; }
		if (InputManager::GetInstance()->IsNew(KEY_INPUT_D)) { dir = { 1.0f, 0.0f, 0.0f }; }
	}
	else
	{
		// �ڑ�����Ă���Q�[���p�b�h�P�̏����擾
		InputManager::JOYPAD_IN_STATE padState =
			InputManager::GetInstance()->GetJPadInputState(InputManager::JOYPAD_NO::PAD1);

		// �A�i���O�L�[�̓��͒l����������擾
		dir = InputManager::GetInstance()->GetDirectionXZAKey(padState.AKeyLX, padState.AKeyLY);

	}

	if (!AsoUtility::EqualsVZero(dir))
	{
		// ���͒l�̕��
		const float SMOOTH = 0.25f; // �������قǊ���������
		dir.x = preInputDir_.x + (dir.x - preInputDir_.x) * SMOOTH;
		dir.z = preInputDir_.z + (dir.z - preInputDir_.z) * SMOOTH;
		preInputDir_ = dir;

		// ���K��
		dir = VNorm(dir);

		// XYZ�̉�]�s��
		// XZ���ʈړ��ɂ���ꍇ�́AXZ�̉�]���l�����Ȃ��悤�ɂ���
		MATRIX mat = MGetIdent();
		mat = MMult(mat, MGetRotY(cameraAngles.y));

		// ��]�s����g�p���āA�x�N�g������]������
		moveDir_ = VTransform(dir, mat);

		// ����
		if (InputManager::GetInstance()->IsNew(KEY_INPUT_LSHIFT))
		{
			// �����~�X�s�[�h�ňړ��ʂ�����āA���W�ɑ����Ĉړ�
			pos_ = VAdd(pos_, VScale(moveDir_, RUN_POW));

			// �����A�j���[�V�����̍Đ�
			animationController_->Play(static_cast<int>(ANIM_TYPE::RUN));
		}
		else
		{
			// �����~�X�s�[�h�ňړ��ʂ�����āA���W�ɑ����Ĉړ�
			pos_ = VAdd(pos_, VScale(moveDir_, MOVE_POW));

			// �����A�j���[�V�����̍Đ�
			animationController_->Play(static_cast<int>(ANIM_TYPE::WALK));
		}
	}
	else
	{
		// �ҋ@�A�j���[�V�����̍Đ�
		animationController_->Play(static_cast<int>(ANIM_TYPE::IDLE));
	}
}
