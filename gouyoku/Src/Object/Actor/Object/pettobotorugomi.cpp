#include "Pettobotorugomi.h"

Pettobotorugomi::Pettobotorugomi()
{
}

Pettobotorugomi::~Pettobotorugomi()
{
}



void Pettobotorugomi::InitLoad(void)
{
	modelId_ = MV1LoadModel("Data/object/PlasticBottleTrashCan/pettobotorugomi.mv1");
}

void Pettobotorugomi::InitTransform(void)
{
	pos_ = { -1109.0f,0.000206f,-800.0f };
	scale_ = { 0.5f,0.5f,0.5f };
	angle_ = { 0.0f,180.0f * DX_PI_F / 180.0f,0.0f };

	// サイズ変更
	MV1SetScale(modelId_, scale_);
	MV1SetRotationXYZ(modelId_, angle_);

}

void Pettobotorugomi::InitAnimation(void)
{
}

void Pettobotorugomi::InitPost(void)
{
	isCollision_ = true;
	sphereRadius_ = 30.0f;
}

void Pettobotorugomi::Update(void)
{
	ActorBase::Update();
}

void Pettobotorugomi::Draw(void)
{
	ActorBase::Draw();
}

void Pettobotorugomi::Release(void)
{
	ActorBase::Release();
}
