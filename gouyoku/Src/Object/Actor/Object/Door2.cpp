#include "Door2.h"
#include "../../Common/AnimationController.h"
#include "../../../Input/InputManager.h"

Door2::Door2()
{
}

Door2::~Door2()
{
}

void Door2::InitLoad(void)
{
}

void Door2::InitTransform(void)
{
	pos_ = { 2910.972900f,0.000191f,-735.282410f };
}

void Door2::InitAnimation(void)
{
}

void Door2::InitPost(void)
{
	tag_ = TAG::DOOR;
	isCollision_ = false;
	sphereRadius_ = 300.0f;
}

void Door2::Update(void)
{
	ActorBase::Update();
}

void Door2::Draw(void)
{
	DrawSphere3D(pos_, sphereRadius_, 16, 0xff0000, 0xff0000, false);

	ActorBase::Draw();
}

void Door2::Release(void)
{
	ActorBase::Release();
}
