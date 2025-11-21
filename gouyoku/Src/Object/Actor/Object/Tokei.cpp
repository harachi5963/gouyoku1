#include "Tokei.h"
#include "../../Common/AnimationController.h"
#include "../../../Input/InputManager.h"

Tokei::Tokei()
{
}

Tokei::~Tokei()
{
}

void Tokei::Update(void)
{
	ActorBase::Update();

}

void Tokei::Draw(void)
{
	ActorBase::Draw();

}

void Tokei::Release(void)
{
	ActorBase::Release();

}

void Tokei::InitLoad(void)
{
}

void Tokei::InitTransform(void)
{
	tag_ = TAG::IHEN_OBJECT;
	modelId_ = MV1LoadModel("Data/object/Tokei/Tokei.mv1");
	ihenModelId_ = MV1LoadModel("Data/object/Tokei/Tokei_IH.mv1");
}

void Tokei::InitAnimation(void)
{
	pos_ = { 1016.0f,260.0f,850.0f };
	scale_ = { 0.0005f,0.0005f,0.0005f };
	angle_ = { 0.0f,300.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);
}

void Tokei::InitPost(void)
{
	tag_ = TAG::IHEN_OBJECT;
	isCollision_ = true;
	sphereRadius_ = 300.0f;
}
