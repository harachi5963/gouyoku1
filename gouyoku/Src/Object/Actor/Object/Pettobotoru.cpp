#include "Pettobotoru.h"

Pettobotoru::Pettobotoru()
{
}

Pettobotoru::~Pettobotoru()
{
}

void Pettobotoru::Update(void)
{
	ActorBase::Update();
}

void Pettobotoru::Draw(void)
{
	ActorBase::Draw();

}

void Pettobotoru::Release(void)
{
	ActorBase::Release();

}

void Pettobotoru::InitLoad(void)
{
	tag_ = TAG::IHEN_OBJECT;
	modelId_ = MV1LoadModel("Data/object/Pettobotoru/pettobotoru.mv1");
}

void Pettobotoru::InitTransform(void)
{
	pos_ = { 100.0f,30.0f,0.0f };
	scale_ = { 0.25f,0.25f,0.25f };
	angle_ = { 0.0f,0.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);

	

}

void Pettobotoru::InitAnimation(void)
{
}

void Pettobotoru::InitPost(void)
{
	isCollision_ = true;
	sphereRadius_ = 30.0f;
}
