#include "Signboard.h"

Signboard::Signboard()
{
}

Signboard::~Signboard()
{
}

void Signboard::Update(void)
{
	ActorBase::Update();

}

void Signboard::Draw(void)
{
	ActorBase::Draw();
}


void Signboard::Release(void)
{
	ActorBase::Release();
}

void Signboard::InitLoad(void)
{
	modelId_ = MV1LoadModel("Data/object/signboard/signboard.mv1");

}

void Signboard::InitTransform(void)
{
	pos_ = { 916.0f,0.0f,-10.0f };
	scale_ = { 0.5f,0.5f,0.5f };
	angle_ = { 0.0f,300.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);
}

void Signboard::InitAnimation(void)
{
}

void Signboard::InitPost(void)
{
	tag_ = TAG::IHEN_OBJECT;
	isCollision_ = true;
	sphereRadius_ = 300.0f;
}
