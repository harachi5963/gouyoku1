#include "Chair.h"

Chair::Chair()
{
}

Chair::~Chair()
{
}



void Chair::InitLoad(void)
{
	modelId_ = MV1LoadModel("Data/object/Chair/Chair.mv1");
}

void Chair::InitTransform(void)
{
	pos_ = { 700.0f,0.0f,0.0f };
	scale_ = { 1.0f,1.0f,1.0f };
	angle_ = { 0.0f,0.0f,0.0f };
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
