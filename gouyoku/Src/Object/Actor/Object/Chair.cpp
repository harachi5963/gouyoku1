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
	pos_ = { 700.0f,0.0f,0.0f };
	scale_ = { 2.0f,2.0f,2.0f };
	angle_ = { 0.0f,0.0f,0.0f };

	// �T�C�Y�ύX
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
