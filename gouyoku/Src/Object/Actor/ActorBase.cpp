#include "../../Application.h"
#include "../../Utility/AsoUtility.h"
#include "../../Utility/MatrixUtility.h"
#include "../Common/AnimationController.h"
#include "ActorBase.h"

ActorBase::ActorBase(void)
{ 
	animationController_ = nullptr;

	animType_ = 0;

	modelId_ = -1;
	pos_ = { 0.0f,0.0f,0.0f };
	angle_ = { 0.0f,0.0f,0.0f };
	localAngle_ = { 0.0f,0.0f,0.0f };
	scale_ = { 0.0f,0.0f,0.0f };

	startCapsulePos_ = { 0.0f,0.0f,0.0f };
	endCapsulePos_ = { 0.0f,0.0f,0.0f };
	capsuleRadius_ = 0.0f;

	preInputDir_ = { 0.0f,0.0f,0.0f };

	moveDir_ = { 0.0f,0.0f,0.0f };
	jumpPow_ = 0.0f;
	isCollision_ = false;
}

ActorBase::~ActorBase(void)
{
}

void ActorBase::Init(void)
{
	// Transform������
	InitTransform();

	// �A�j���[�V�����̏�����
	InitAnimation();

	// ��������̌ʏ���
	InitPost();
}

void ActorBase::Load(void)
{
	// ���\�[�X���[�h
	InitLoad();
}

void ActorBase::LoadEnd(void)
{
	// ������
	Init();
}

void ActorBase::Update(void)
{
	// �v���C���[�̒x����]����
	DelayRotate();

	// �s��̍���(�q, �e�Ǝw�肷��Ɛe�ˎq�̏��ɓK�p�����)
	MATRIX mat = MatrixUtility::Multiplication(localAngle_, angle_);

	// ��]�s������f���ɔ��f
	MV1SetRotationMatrix(modelId_, mat);

	// �v���C���[�̈ړ�����
	Move();

	// �d��(�����x�𑬓x�ɉ��Z���Ă���)
	jumpPow_ -= 0.8f;

	// �v���C���[�̍��W�Ɉړ���(���x�A�W�����v��)�����Z����
	pos_.y += jumpPow_;

	// ���f���ɍ��W��ݒ肷��
	MV1SetPosition(modelId_, pos_);

	// �A�j���[�V�����̍X�V
	animationController_->Update();
}

void ActorBase::Draw(void)
{
	MV1DrawModel(modelId_);

	DrawSphere3D(
		VAdd(pos_,startCapsulePos_),
		capsuleRadius_,
		16,
		0x00ff00,
		0x00ff00,
		false
	);

	DrawSphere3D(
		VAdd(pos_, endCapsulePos_),
		capsuleRadius_,
		16,
		0x00ff00,
		0x00ff00,
		false
	);
}

void ActorBase::Release(void)
{
	MV1DeleteModel(modelId_);
	delete animationController_;
}

void ActorBase::CollisionStage(const VECTOR& pos)
{
	// �Փ˔���Ɏw����W�ɉ����߂�
	pos_ = pos;
	jumpPow_ = 0.0f;
}

void ActorBase::Move(void)
{
}

void ActorBase::DelayRotate(void)
{
	// �ړ���������p�x�ɕϊ�����
	float goal = atan2f(moveDir_.x, moveDir_.z);

	// ��ɍŒZ�o�H�ŕ��
	angle_.y = AsoUtility::LerpAngle(angle_.y, goal, 0.2f);
}
