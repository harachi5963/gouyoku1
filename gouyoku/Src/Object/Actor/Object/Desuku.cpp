#include "Desuku.h"

Desuku::Desuku()
{
}

Desuku::~Desuku()
{
}



void Desuku::InitLoad(void)
{
	//modelId_ = MV1LoadModel("Data/object/Desuku/desuku4.mv1");
}

void Desuku::InitTransform(void)
{
	pos_ = { 0.0f,200.0f,0.0f };
	scale_ = { 0.8f,0.8f,0.8f };
	angle_ = { 0.0f,300.0f,0.0f };
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
