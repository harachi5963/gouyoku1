#include "Basketball.h"

Basketball::Basketball()
{
}

Basketball::~Basketball()
{
}



void Basketball::InitLoad(void)
{
	tag_ = TAG::IHEN_OBJECT;
	modelId_ = MV1LoadModel("Data/object/Ball/basketball.mv1");
}

void Basketball::InitTransform(void)
{
	pos_ = { 100.0f,30.0f,0.0f };
	scale_ = { 0.32f,0.32f,0.32f };
	angle_ = { 0.0f,0.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);
}

void Basketball::InitAnimation(void)
{
}

void Basketball::InitPost(void)
{
	isCollision_ = true;
	sphereRadius_ = 20.0f;
}

void Basketball::Update(void)
{
	ActorBase::Update();
}

void Basketball::Draw(void)
{
	ActorBase::Draw();
}

void Basketball::Release(void)
{
	ActorBase::Release();
}
