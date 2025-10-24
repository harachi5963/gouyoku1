#include "Door.h"
#include "../../Common/AnimationController.h"
#include "../../../Input/InputManager.h"

Door::Door()
{
}

Door::~Door()
{
}

void Door::InitLoad(void)
{
	modelId_ = MV1LoadModel("Data/object/Vending machine/Vending machine.mv1");

	//���Ȕ��s
	MV1SetMaterialAmbColor(modelId_, 0, EMI_COLOR);
	MV1SetMaterialDifColor(modelId_, 0, EMI_COLOR);

	// ���f���A�j���[�V��������̏�����
	animationController_ = new AnimationController(modelId_);

}

void Door::InitTransform(void)
{
	pos_ = { 10.0f,0.0f,0.0f };
	scale_ = { 1.0f,1.0f,1.0f };
	angle_ = { 0.0f,0.0f,0.0f };
}

void Door::InitAnimation(void)
{
	// �A�j���[�V�����̒ǉ�
	animationController_->AddInFbx(
		static_cast<int>(ANIM_TYPE::OPEN), 0.5f, 0);
}

void Door::InitPost(void)
{
	tag_ = TAG::DOOR;
	isCollision_ = true;
	sphereRadius_ = 300.0f;
}

void Door::Update(void)
{
	ActorBase::Update();

	// �A�j���[�V�����̍X�V
	animationController_->Update();

	//{
	//	// �����A�j���[�V�����̍Đ�
	//	animationController_->Play(static_cast<int>(ANIM_TYPE::OPEN), false);
	//}
}

void Door::Draw(void)
{
	ActorBase::Draw();
}

void Door::Release(void)
{
	ActorBase::Release();
}
