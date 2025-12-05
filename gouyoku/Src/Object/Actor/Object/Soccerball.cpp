#include "Soccerball.h"

#include "../../Common/AnimationController.h"
#include "../../../Application.h"

Soccerball::Soccerball()
{
}

Soccerball::~Soccerball()
{
}



void Soccerball::InitLoad(void)
{
	tag_ = TAG::IHEN_OBJECT;
	modelId_ = MV1LoadModel("Data/object/Ball/soccerball.mv1");
	ihenModelId_ = MV1LoadModel("Data/object/Ball/SoccerballAnim.mv1");
}

void Soccerball::InitTransform(void)
{
	pos_ = { 360.0f,123.0f,-311.0f };
	scale_ = { 0.3f,0.3f,0.3f };
	angle_ = { 0.0f,0.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);
}

void Soccerball::InitAnimation(void)
{
	// モデルアニメーション制御の初期化
	animationController_ = new AnimationController(ihenModelId_);

	// アニメーションの追加
	animationController_->AddInFbx(0, 0.5f, 0);

}

void Soccerball::InitPost(void)
{
	isCollision_ = true;
	sphereRadius_ = 20.0f;
}

void Soccerball::Update(void)
{
	ActorBase::Update();

	// アニメーションの更新
	animationController_->Update();

}

void Soccerball::Draw(void)
{
	ActorBase::Draw();
}

void Soccerball::Release(void)
{
	ActorBase::Release();
}
