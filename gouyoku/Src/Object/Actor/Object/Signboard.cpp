#include "Signboard.h"
#include "../../Common/AnimationController.h"
#include "../../../Input/InputManager.h"

Signboard::Signboard()
{
}

Signboard::~Signboard()
{
}

void Signboard::Update(void)
{
	ActorBase::Update();
}

void Signboard::Draw(void)
{
	ActorBase::Draw();
}

void Signboard::Release(void)
{
	ActorBase::Release();
}

void Signboard::InitLoad(void)
{
	modelId_ = MV1LoadModel("Data/object/signboard/signboard.mv1");
}

void Signboard::InitTransform(void)
{
	pos_ = { -463.0f,155.0f,-380.0f };
	scale_ = { 1.2f,1.2f,1.2f };
	angle_ = { 0.0f,0.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);
}

void Signboard::InitAnimation(void)
{
}

void Signboard::InitPost(void)
{
	tag_ = TAG::IHEN_OBJECT;
	isCollision_ = true;
	sphereRadius_ = 300.0f;
}
