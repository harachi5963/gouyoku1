#include "Projector.h"
#include "../../Common/AnimationController.h"
#include "../../../Input/InputManager.h"

Projector::Projector()
{
}

Projector::~Projector()
{
}

void Projector::Update(void)
{
	ActorBase::Update();
}

void Projector::Draw(void)
{
	ActorBase::Draw();

}

void Projector::Release(void)
{
	ActorBase::Release();

}

void Projector::InitLoad(void)
{
	tag_ = TAG::IHEN_OBJECT;
	modelId_ = MV1LoadModel("Data/object/Projector/projector.mv1");
	ihenModelId_ = MV1LoadModel("Data/object/Projector/PRojector_IH.mv1");
}

void Projector::InitTransform(void)
{
	pos_ = { 920.0f,100.0f,-10.0f };
	scale_ = { 0.4f,0.4f,0.4f };
	angle_ = { 0.0f,500.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);
}

void Projector::InitAnimation(void)
{
}

void Projector::InitPost(void)
{
	tag_ = TAG::IHEN_OBJECT;
	isCollision_ = true;
	sphereRadius_ = 300.0f;
}
