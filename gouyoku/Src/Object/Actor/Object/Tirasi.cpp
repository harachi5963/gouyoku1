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
	modelId_ = MV1LoadModel("Data/object/tirasi/tirasi.mv1");
	ihenModelId_ = MV1LoadModel("Data/object/tirasi/zigoku.mv1");
}

void Tirasi::InitTransform(void)
{
	pos_ = { 96.0f,0.0f,-10.0f };
	scale_ = { 0.5f,0.5f,0.5f };
	angle_ = { 0.0f,0.0f,0.0f };

	// �T�C�Y�ύX
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
