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
	pos_ = { 10.0f,0.0f,0.0f };
	scale_ = { 1.0f,1.0f,1.0f };
	angle_ = { 0.0f,0.0f,0.0f };
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
