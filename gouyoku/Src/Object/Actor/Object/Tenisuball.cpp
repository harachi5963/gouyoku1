#include "Tenisuball.h"

Tenisuball::Tenisuball()
{
}

Tenisuball::~Tenisuball()
{
}



void Tenisuball::InitLoad(void)
{
	tag_ = TAG::IHEN_OBJECT;
	//modelId_ = MV1LoadModel("Data/object/Ball/tenisuball.mv1");
}

void Tenisuball::InitTransform(void)
{
	pos_ = { 100.0f,30.0f,0.0f };
	scale_ = { 0.5f,0.5f,0.5f };
	angle_ = { 0.0f,0.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);
}

void Tenisuball::InitAnimation(void)
{
}

void Tenisuball::InitPost(void)
{
	isCollision_ = true;
	sphereRadius_ = 20.0f;
}

void Tenisuball::Update(void)
{
	ActorBase::Update();
}

void Tenisuball::Draw(void)
{
	ActorBase::Draw();
}

void Tenisuball::Release(void)
{
	ActorBase::Release();
}
