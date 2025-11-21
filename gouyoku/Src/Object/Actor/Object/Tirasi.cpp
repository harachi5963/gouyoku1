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

	pos_ = { -700.682190f,160.66f,866.526855f };
	scale_ = { 1.2f,1.2f,1.2f };
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
