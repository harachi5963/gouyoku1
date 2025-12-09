#include "Kasatate.h"

Kasatate::Kasatate()
{
}

Kasatate::~Kasatate()
{
}

void Kasatate::Update(void)
{
	ActorBase::Update();
}

void Kasatate::Draw(void)
{
	ActorBase::Draw();
}

void Kasatate::Release(void)
{
	ActorBase::Release();

}

void Kasatate::InitLoad(void)
{
	tag_ = TAG::IHEN_OBJECT;
	modelId_ = MV1LoadModel("Data/object/Kasatate/kasa.mv1");
}

void Kasatate::InitTransform(void)
{
	pos_ = { -1860.069336f,0.022f,765.0 };
	scale_ = { 0.4f,0.7f,0.4f };
	angle_ = { 0.0f,0.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);
}

void Kasatate::InitAnimation(void)
{
}

void Kasatate::InitPost(void)
{
	isCollision_ = true;
	sphereRadius_ = 20.0f;


}
