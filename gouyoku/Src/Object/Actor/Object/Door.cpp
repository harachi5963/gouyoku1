#include "Door.h"
#include "../../Common/AnimationController.h"
#include "../../../Input/InputManager.h"

Door::Door()
{
}

Door::~Door()
{
}

void Door::InitLoad(void)
{
}

void Door::InitTransform(void)
{
	pos_ = { -2907.340820f,0.000198f,-777.524658f };
}

void Door::InitAnimation(void)
{
}

void Door::InitPost(void)
{
	tag_ = TAG::RETURN_DOOR;
	isCollision_ = false;
	sphereRadius_ = 300.0f;
}

void Door::Update(void)
{
	ActorBase::Update();
}

void Door::Draw(void)
{
	//DrawSphere3D(pos_, sphereRadius_, 16, 0xff0000, 0xff0000, false);

	ActorBase::Draw();
}

void Door::Release(void)
{
	ActorBase::Release();
}
