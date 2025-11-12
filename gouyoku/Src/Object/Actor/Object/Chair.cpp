#include "Chair.h"

Chair::Chair()
{
}

Chair::~Chair()
{
}



void Chair::InitLoad(void)
{
	tag_ = TAG::IHEN_OBJECT;
	modelId_ = MV1LoadModel("Data/object/Chair/Chair2.mv1");
	ihenModelId_ = MV1LoadModel("Data/object/Chair/Chair.mv1");
}

void Chair::InitTransform(void)
{
	pos_ = { 710.069336f,0.000103f,-240.828400 };
	scale_ = { 1.7f,1.7f,1.7f };
	angle_ = { 0.0f,0.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);
}

void Chair::InitAnimation(void)
{
}

void Chair::InitPost(void)
{
	isCollision_ = true;
	sphereRadius_ = 20.0f;
}

void Chair::Update(void)
{
	ActorBase::Update();
}

void Chair::Draw(void)
{
	ActorBase::Draw();
}

void Chair::Release(void)
{
	ActorBase::Release();
}
