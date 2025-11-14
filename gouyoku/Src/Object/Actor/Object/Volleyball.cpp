#include "Volleyball.h"

Volleyball::Volleyball()
{
}

Volleyball::~Volleyball()
{
}



void Volleyball::InitLoad(void)
{
	tag_ = TAG::IHEN_OBJECT;
	//modelId_ = MV1LoadModel("Data/object/Ball/volleyball_1.mv1");
}

void Volleyball::InitTransform(void)
{
	pos_ = { 100.0f,30.0f,0.0f };
	scale_ = { 0.3f,0.3f,0.3f };
	angle_ = { 0.0f,0.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);
}

void Volleyball::InitAnimation(void)
{
}

void Volleyball::InitPost(void)
{
	isCollision_ = true;
	sphereRadius_ = 20.0f;
}

void Volleyball::Update(void)
{
	ActorBase::Update();
}

void Volleyball::Draw(void)
{
	ActorBase::Draw();
}

void Volleyball::Release(void)
{
	ActorBase::Release();
}
