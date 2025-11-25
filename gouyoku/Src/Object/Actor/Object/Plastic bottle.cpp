#include "Plastic bottle.h"

Plasticbottle::Plasticbottle()
{
}

Plasticbottle::~Plasticbottle()
{
}

void Plasticbottle::Update(void)
{
	ActorBase::Update();
}

void Plasticbottle::Draw(void)
{
	ActorBase::Draw();
}

void Plasticbottle::Release(void)
{
	ActorBase::Release();
}

void Plasticbottle::InitLoad(void)
{
	tag_ = TAG::IHEN_OBJECT;
	modelId_ = MV1LoadModel("Data/object/Plastic bottle/pettobotoru.mv1");
}

void Plasticbottle::InitTransform(void)
{
	pos_ = { 1313.087524f,100.0f,-310.227478f };
	scale_ = { 0.15f,0.15f,0.15f };
	angle_ = { 0.0f,140.0f * DX_PI_F / 180.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);

	MV1SetRotationXYZ(modelId_, angle_);
}

void Plasticbottle::InitAnimation(void)
{
}

void Plasticbottle::InitPost(void)
{
	isCollision_ = true;
	sphereRadius_ = 30.0f;
}
