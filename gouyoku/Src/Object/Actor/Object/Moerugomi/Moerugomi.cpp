#include "Moerugomi.h"

Moerugomi::Moerugomi()
{
}

Moerugomi::~Moerugomi()
{
}

void Moerugomi::Update(void)
{
	ActorBase::Update();
}

void Moerugomi::Draw(void)
{
	ActorBase::Draw();
}

void Moerugomi::Release(void)
{
	ActorBase::Release();
}

void Moerugomi::InitLoad(void)
{
	tag_ = TAG::IHEN_OBJECT;
	ihenModelId_ = MV1LoadModel("Data/object/Moerugomi/Moerugomi.mv1");
}

void Moerugomi::InitTransform(void)
{
	pos_ = { -1216.226582f,0.000156f,-515.020325 };
	scale_ = { 0.4f,0.7f,0.4f };
	angle_ = { 0.0f,180.0f * DX_PI_F / 180.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);
	MV1SetRotationXYZ(modelId_, angle_);
}

void Moerugomi::InitAnimation(void)
{
}

void Moerugomi::InitPost(void)
{
	isCollision_ = true;
	sphereRadius_ = 20.0f;
}
