#include "Tirasi.h"
#include "../../Common/AnimationController.h"
#include "../../../Input/InputManager.h"

Tirasi::Tirasi()
{
}

Tirasi::~Tirasi()
{
}

void Tirasi::InitLoad(void)
{
	tag_ = TAG::IHEN_OBJECT;
	modelId_ = MV1LoadModel("Data/object/tirasi/tirasi.mv1");
	ihenModelId_ = MV1LoadModel("Data/object/tirasi/tirasiihenn.mv1");
}

void Tirasi::InitTransform(void)
{
<<<<<<< HEAD
	pos_ = { -108.0f,75.0f,-386.5f };
	scale_ = { 0.3f,0.3f,0.f };
=======
	pos_ = { 120.0f,50.0f,-10.0f };
	scale_ = { 1.0f,1.0f,1.0f };
>>>>>>> 5c28a288f0e1feaa67705f88163160554c98cb02
	angle_ = { 0.0f,0.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);
}

void Tirasi::InitAnimation(void)
{
}

void Tirasi::InitPost(void)
{
	tag_ = TAG::IHEN_OBJECT;
	isCollision_ = true;
	sphereRadius_ = 300.0f;
}

void Tirasi::Update(void)
{
	ActorBase::Update();
}

void Tirasi::Draw(void)
{
	ActorBase::Draw();
}

void Tirasi::Release(void)
{
	ActorBase::Release();
}
