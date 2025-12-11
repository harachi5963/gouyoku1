#include "VendingMachine.h"
#include "../../Common/AnimationController.h"
#include "../../../Input/InputManager.h"

VendingMachine::VendingMachine()
{
}

VendingMachine::~VendingMachine()
{
}

void VendingMachine::InitLoad(void)
{
	modelId_ = MV1LoadModel("Data/object/Vending machine/Vending machine.mv1");
	ihenModelId_ = MV1LoadModel("Data/object/Vending machine/Vending machine1.mv1");
}

void VendingMachine::InitTransform(void)
{
	pos_ = { -1110.0f,0.006f,-960.381592f };
	scale_ = { 0.7f,0.7f,0.7f };
	angle_ = { 0.0f,90.0f * DX_PI_F / 180.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);
	MV1SetRotationXYZ(modelId_, angle_);
	
}

void VendingMachine::InitAnimation(void)
{
}

void VendingMachine::InitPost(void)
{
	tag_ = TAG::IHEN_OBJECT;
	isCollision_ = true;
	sphereRadius_ = 300.0f;
}

void VendingMachine::Update(void)
{
	ActorBase::Update();
}

void VendingMachine::Draw(void)
{
	ActorBase::Draw();
}

void VendingMachine::Release(void)
{
	ActorBase::Release();
}
