#include "Calender.h"

Calender::Calender()
{
}

Calender::~Calender()
{
}

void Calender::Update(void)
{
	ActorBase::Update();
}

void Calender::Draw(void)
{
	ActorBase::Draw();
}

void Calender::Release(void)
{
	ActorBase::Release();
}

void Calender::InitLoad(void)
{
	modelId_ = MV1LoadModel("Data/object/Calender/karennda1gatu.mv1");
}

void Calender::InitTransform(void)
{
	pos_ = { 0.000370f,200.0f,860.0f };
	scale_ = { 0.7f,0.7f,0.7f };
	angle_ = { 0.0f,300.0f,0.0f };

	MV1SetScale(modelId_, scale_);
}

void Calender::InitAnimation(void)
{
	
}

void Calender::InitPost(void)
{
	isCollision_ = true;
	sphereRadius_ = 100.0f;
}
