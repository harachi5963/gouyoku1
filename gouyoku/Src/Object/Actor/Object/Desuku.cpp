#include "Desuku.h"

Desuku::Desuku()
{
}

Desuku::~Desuku()
{
}



void Desuku::InitLoad(void)
{
}

void Desuku::InitTransform(void)
{
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

void Desuku::SetDesuku(const TCHAR* path, VECTOR pos, VECTOR scl, VECTOR angle)
{
	modelId_ = MV1LoadModel(path);

	pos_ = pos;
	scale_ = scl;
	angle_ = angle;
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
