#include "Howaitoboudo.h"

Howaitoboudo::Howaitoboudo()
{
}

Howaitoboudo::~Howaitoboudo()
{
}

void Howaitoboudo::Update(void)
{
	ActorBase::Update();
}

void Howaitoboudo::Draw(void)
{
	ActorBase::Draw();
}

void Howaitoboudo::Release(void)
{
	ActorBase::Release();
}

void Howaitoboudo::InitLoad(void)
{
	tag_ = TAG::IHEN_OBJECT;
	modelId_ = MV1LoadModel("Data/object/Howaitoboudo/Howaitoboudo.mv1");
}

void Howaitoboudo::InitTransform(void)
{
	pos_ = { 953.964111f,-400.000132f,-370.614502f };
	scale_ = { 3.0f,3.0f,3.0f };
	angle_ = { 0.0f,90.0f * DX_PI_F / 180.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);
	MV1SetRotationXYZ(modelId_, angle_);
}

void Howaitoboudo::InitAnimation(void)
{
}

void Howaitoboudo::InitPost(void)
{
	isCollision_ = true;
	sphereRadius_ = 20.0f;
}
