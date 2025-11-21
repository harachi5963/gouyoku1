#include "Chair.h"

Chair::Chair()
{
}

Chair::~Chair()
{
}



void Chair::InitLoad(void)
{
	//tag_ = TAG::IHEN_OBJECT;
    //ihenModelId_ = MV1LoadModel("Data/object/Chair/Chair.mv1");
}

void Chair::InitTransform(void)
{
	// サイズ変更
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


void Chair::SetChair(const TCHAR* path, VECTOR pos, VECTOR scl, VECTOR angle)
{
	modelId_ = MV1LoadModel(path);
	pos_ = pos;
	scale_ = scl;
	angle_ = angle;
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
