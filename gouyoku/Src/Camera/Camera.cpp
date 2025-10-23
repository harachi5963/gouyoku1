#include "Camera.h"

#include "../Utility/AsoUtility.h"
#include "../Input/InputManager.h"

#include "../Object/Actor/ActorBase.h"

Camera::Camera(void)
{
	// DxLib�̏����ݒ�ł́A
	// �J�����̈ʒu�� x = 320.0f, y = 240.0f, z = (��ʂ̃T�C�Y�ɂ���ĕω�)�A
	// �����_�̈ʒu�� x = 320.0f, y = 240.0f, z = 1.0f
	// �J�����̏������ x = 0.0f, y = 1.0f, z = 0.0f
	// �E��ʒu����Z���̃v���X����������悤�ȃJ����
}

Camera::~Camera(void)
{
}

void Camera::Init(void)
{
	// �J�����̏����ʒu
	pos_ = DERFAULT_POS;

	// �J�����̏����p�x
	angle_ = DERFAULT_ANGLES;
}

void Camera::Update(void)
{
}

void Camera::SetBeforeDraw(void)
{
	// �N���b�v������ݒ肷��(SetDrawScreen�Ń��Z�b�g�����)
	SetCameraNearFar(VIEW_NEAR, VIEW_FAR);

	switch (mode_)
	{
	case Camera::MODE::FIXED_POINT:
		SetBeforeDrawFixedPoint();
		break;
	case Camera::MODE::FREE:
		SetBeforeDrawFree();
		break;
	case Camera::MODE::FOLLOW:
		SetBeforeDrawFollow();
		break;
	}
}

void Camera::SetBeforeDrawFixedPoint(void)
{
	// �J�����̐ݒ�(�ʒu�Ɗp�x�ɂ�鐧��)
	SetCameraPositionAndAngle(
		pos_,
		angle_.x,
		angle_.y,
		angle_.z
	);
}

void Camera::SetBeforeDrawFree(void)
{
	// �Q�[���p�b�h���ڑ����ŏ����𕪂���
	if (GetJoypadNum() == 0)
	{
		// ������]�ɂ��XYZ�̈ړ�
		MoveXYZDirection();
	}
	else
	{
		// ������]�ɂ��XYZ�̈ړ�(�Q�[���p�b�h)
		MoveXYZDirectionPad();
	}

	// �J�����̐ݒ�(�ʒu�Ɗp�x�ɂ�鐧��)
	SetCameraPositionAndAngle(
		pos_,
		angle_.x,
		angle_.y,
		angle_.z
	);
}

void Camera::DrawDebug(void)
{

	DrawFormatString(
		0, 10, 0xffffff,
		"�J�������W�@ �F(%.1f, %.1f, %.1f)",
		pos_.x, pos_.y, pos_.z
	);
	DrawFormatString(
		0, 30, 0xffffff,
		"�J�����p�x�@ �F(%.1f, %.1f, %.1f)",
		AsoUtility::Rad2DegF(angle_.x),
		AsoUtility::Rad2DegF(angle_.y),
		AsoUtility::Rad2DegF(angle_.z)
	);

	DrawSphere3D(targetPos_, 20.0f, 10, 0xff0000, 0xff0000, true);

}

void Camera::SetBeforeDrawFollow(void)
{

	if (GetJoypadNum() == 0)
	{
		// ������]�ɂ��XYZ�̈ړ�
		MoveXYZDirection();
	}
	else
	{
		// ������]�ɂ��XYZ�̈ړ�(�Q�[���p�b�h)
		MoveXYZDirectionPad();
	}

	// �J�����̉�]�s����쐬
	MATRIX mat = MGetIdent();
	mat = MMult(mat, MGetRotX(angle_.x));
	mat = MMult(mat, MGetRotY(angle_.y));
	//mat = MMult(mat, MGetRotZ(angles_.z));
	
	// �J�����̉�]�s��(X����)���쐬
	MATRIX matY = MGetIdent();
	//mat = MMult(mat, MGetRotX(angles_.x));
	matY = MMult(matY, MGetRotY(angle_.y));
	//mat = MMult(mat, MGetRotZ(angles_.z));

	// �����_�̈ړ�
	VECTOR followPos = follow_->GetPos();
	//VECTOR targetLocalRotPos = VTransform(FOLLOW_TARGET_LOCAL_POS, matY);
	VECTOR targetLocalRotPos = VTransform(FOLLOW_TARGET_LOCAL_POS, mat);
	targetPos_ = VAdd(followPos, targetLocalRotPos);

	// �J�����̈ړ�
	// ���΍��W����]�����āA��]��̑��΍��W���擾����
	VECTOR cameraLocalRotPos = VTransform(FOLLOW_CAMERA_LOCAL_POS, mat);

	// ���΍��W���烏�[���h���W�ɒ����āA�J�������W�Ƃ���
	pos_ = VAdd(followPos, cameraLocalRotPos);

	// �J�����̏�������v�Z
	VECTOR up = VTransform(AsoUtility::DIR_U, mat);

	// �J�����̐ݒ�(�ʒu�ƒ����_�ɂ�鐧��)
	SetCameraPositionAndTargetAndUpVec(
		pos_,
		targetPos_,
		up
	);
}

void Camera::Release(void)
{
}

void Camera::ChangeMode(MODE mode)
{
	// �J�������[�h�̕ύX
	mode_ = mode;

	// �ύX���̏���������
	switch (mode_)
	{
	case Camera::MODE::FIXED_POINT:
		break;
	case Camera::MODE::FREE:
		break;
	case Camera::MODE::FOLLOW:
		break;
	}
}

void Camera::SetFollow(ActorBase* follow)
{
	follow_ = follow;
}

void Camera::MoveXYZDirection(void)
{
	// ���L�[�ŃJ�����̊p�x��ς���
	float rotPow = 1.0f * DX_PI_F / 180.0f;
	if (InputManager::GetInstance()->IsNew(KEY_INPUT_DOWN))	{ angle_.x += rotPow; }
	if (InputManager::GetInstance()->IsNew(KEY_INPUT_UP))	{ angle_.x -= rotPow; }
	if (InputManager::GetInstance()->IsNew(KEY_INPUT_RIGHT)) { angle_.y += rotPow; }
	if (InputManager::GetInstance()->IsNew(KEY_INPUT_LEFT))	{ angle_.y -= rotPow; }
}

void Camera::MoveXYZDirectionPad(void)
{
	// �ڑ�����Ă���Q�[���p�b�h�P�̏����擾
	InputManager::JOYPAD_IN_STATE padState = 
		InputManager::GetInstance()->GetJPadInputState(InputManager::JOYPAD_NO::PAD1);

	VECTOR dir = AsoUtility::VECTOR_ZERO;


	const float ROT_POW_DEG = 2.0f;
	const float rotPow = ROT_POW_DEG * DX_PI_F / 180.0f;

	// �E�X�e�B�b�N�̌X��
	dir = InputManager::GetInstance()->GetDirectionXZAKey(padState.AKeyRX, padState.AKeyRY);

	// �E�X�e�B�b�N���E�̌X��
	angle_.y += dir.x * rotPow;

	// �E�X�e�B�b�N�㉺�̌X��
	angle_.x += dir.z * rotPow;
}
