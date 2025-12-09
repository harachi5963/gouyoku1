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

	for (int i = 0; i < static_cast<int>(Calender::CALENDER::MAX); i++)
	{
		MV1SetScale(calenderModelId_[i], scale_);
		MV1SetRotationXYZ(calenderModelId_[i], angle_);
		MV1SetPosition(calenderModelId_[i], pos_);
	}
}

void Calender::Draw(void)
{
	MV1DrawModel(calenderModelId_[static_cast<int>(nowCalender_)]);
}

void Calender::Release(void)
{
	ActorBase::Release();

	for (int i = 0; i < static_cast<int>(Calender::CALENDER::MAX); i++)
	{
		MV1DeleteModel(calenderModelId_[i]);
	}
}

void Calender::InitLoad(void)
{
	calenderModelId_[static_cast<int>(Calender::CALENDER::JAN)] = MV1LoadModel("Data/object/Calender/karennda1gatu.mv1");
	calenderModelId_[static_cast<int>(Calender::CALENDER::FEB)] = MV1LoadModel("Data/object/Calender/karennda2gatu.mv1");
	calenderModelId_[static_cast<int>(Calender::CALENDER::MAR)] = MV1LoadModel("Data/object/Calender/karennda3gatu.mv1");
	calenderModelId_[static_cast<int>(Calender::CALENDER::APR)] = MV1LoadModel("Data/object/Calender/karennda4gatu.mv1");
	calenderModelId_[static_cast<int>(Calender::CALENDER::MAY)] = MV1LoadModel("Data/object/Calender/karennda5gatu.mv1");
	calenderModelId_[static_cast<int>(Calender::CALENDER::JNU)] = MV1LoadModel("Data/object/Calender/karennda6gatu.mv1");
	calenderModelId_[static_cast<int>(Calender::CALENDER::JUL)] = MV1LoadModel("Data/object/Calender/karennda7gatu.mv1");
	calenderModelId_[static_cast<int>(Calender::CALENDER::AUG)] = MV1LoadModel("Data/object/Calender/karennda8gatu.mv1");
	calenderModelId_[static_cast<int>(Calender::CALENDER::SEP)] = MV1LoadModel("Data/object/Calender/karennda9gatu.mv1");
	calenderModelId_[static_cast<int>(Calender::CALENDER::OCT)] = MV1LoadModel("Data/object/Calender/karennda10gatu.mv1");
	calenderModelId_[static_cast<int>(Calender::CALENDER::NOV)] = MV1LoadModel("Data/object/Calender/karennda11gatu.mv1");
	calenderModelId_[static_cast<int>(Calender::CALENDER::DEC)] = MV1LoadModel("Data/object/Calender/karennda12gatu.mv1");
}

void Calender::InitTransform(void)
{
	pos_ = { -1589.290527f,180.0f,-1035.0f };
	scale_ = { 1.0f,1.0f,1.0f };
	angle_ = { 0.0f,180.0f * DX_PI_F / 180.0f,0.0f };

	for (int i = 0; i < static_cast<int>(Calender::CALENDER::MAX); i++)
	{
		MV1SetScale(calenderModelId_[i], scale_);
		MV1SetRotationXYZ(calenderModelId_[i], angle_);
		MV1SetPosition(calenderModelId_[i], pos_);
	}
}

void Calender::InitAnimation(void)
{
	
}

void Calender::InitPost(void)
{
	tag_ = TAG::CALENDER;

	isCollision_ = true;
	sphereRadius_ = 100.0f;
	nowCalender_ = CALENDER::JAN;


}
