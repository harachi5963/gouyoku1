#include "Pc.h"
#include "../../Common/AnimationController.h"
#include "../../../Input/InputManager.h"

Pc::Pc()
{
}

Pc::~Pc()
{
}

void Pc::InitLoad(void)
{
	modelId_ = MV1LoadModel("Data/object/PC/PC.mv1");
	ihenModelId_ = MV1LoadModel("Data/object/PC/I_PC.mv1");
}

void Pc::InitTransform(void)
{
	pos_ = { 916.0f,0.0f,-10.0f };
	scale_ = { 0.5f,0.5f,0.5f };
	angle_ = { 0.0f,300.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);
}

void Pc::InitAnimation(void)
{
}

void Pc::InitPost(void)
{
	tag_ = TAG::IHEN_OBJECT;
	isCollision_ = true;
	sphereRadius_ = 300.0f;
}

void Pc::Update(void)
{
	ActorBase::Update();
}

void Pc::Draw(void)
{
	ActorBase::Draw();
}

void Pc::Release(void)
{
	ActorBase::Release();
}
