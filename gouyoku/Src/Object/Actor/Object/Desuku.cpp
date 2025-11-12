#include "Desuku.h"

Desuku::Desuku()
{
}

Desuku::~Desuku()
{
}



void Desuku::InitLoad(void)
{
	modelId_ = MV1LoadModel("Data/object/Desuku/desuku.mv1");
}

void Desuku::InitTransform(void)
{
	pos_ = { 678.352173f,0.000122f,-310.874786f };
	scale_ = { 2.5f,2.5f,2.5f };
	angle_ = { 0.0f,300.0f,0.0f };

	MV1SetScale(modelId_, scale_);
}

void Desuku::InitAnimation(void)
{
}

void Desuku::InitPost(void)
{
	isCollision_ = true;
	sphereRadius_ = 300.0f;
}

void Desuku::Update(void)
{
	ActorBase::Update();
}

void Desuku::Draw(void)
{
	ActorBase::Draw();
}

void Desuku::Release(void)
{
	ActorBase::Release();
}
