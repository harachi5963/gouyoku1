#include <DxLib.h>
#include "AnimationController.h"

AnimationController::AnimationController(int modelId)
{
	modelId_ = modelId;
	playType_ = -1;
	animCount_ = 0;
}

AnimationController::~AnimationController(void)
{
}

void AnimationController::Add(int type, float speed, const std::string path)
{
	Animation animation;
	animation.model = MV1LoadModel(path.c_str());
	animation.animIndex = -1;

	Add(type, speed, animation);
}

void AnimationController::AddInFbx(int type, float speed, int animIndex)
{
	Animation animation;
	animation.model = -1;
	animation.animIndex = animIndex;

	Add(type, speed, animation);
}

void AnimationController::Play(int type, bool isLoop)
{

	if (playType_ == type)
	{
		// �����A�j���[�V������������Đ����p������
		return;
	}

	if (playType_ != -1)
	{
		// ���f������A�j���[�V�������O��
		MV1DetachAnim(modelId_, playAnim_.attachNo);
	}

	// �A�j���[�V������ʂ�ύX
	playType_ = type;
	playAnim_ = animations_[type];

	// ������
	playAnim_.step = 0.0f;

	// ���f���ɃA�j���[�V������t����
	if (playAnim_.model == -1)
	{
		// ���f���Ɠ����t�@�C������A�j���[�V�������A�^�b�`����
		playAnim_.attachNo = MV1AttachAnim(modelId_, playAnim_.animIndex);
	}
	else
	{
		// �ʂ̃��f���t�@�C������A�j���[�V�������A�^�b�`����
		// DxModelViewer���m�F���邱��(���0��1)
		int animIdx = 0;
		playAnim_.attachNo = MV1AttachAnim(modelId_, animIdx, playAnim_.model);
	}

	// �A�j���[�V���������Ԃ̎擾
	playAnim_.totalTime = MV1GetAttachAnimTotalTime(modelId_, playAnim_.attachNo);

	// �A�j���[�V�������[�v
	isLoop_ = isLoop;

}

void AnimationController::Update(void)
{
	// �Đ�
	playAnim_.step += playAnim_.speed;

	// �A�j���[�V�������I��������
	if (playAnim_.step > playAnim_.totalTime)
	{
		if (isLoop_)
		{
			// ���[�v�Đ�
			playAnim_.step = 0.0f;
		}
		else
		{
			// ���[�v���Ȃ�
			playAnim_.step = playAnim_.totalTime;
		}
	}

	// �A�j���[�V�����ݒ�
	MV1SetAttachAnimTime(modelId_, playAnim_.attachNo, playAnim_.step);

}

void AnimationController::Release(void)
{

	// �O��FBX�̃��f��(�A�j���[�V����)���
	for (const std::pair<int, Animation>& pair : animations_)
	{
		if (pair.second.model != -1)
		{
			MV1DeleteModel(pair.second.model);
		}
	}
	
	// �ϒ��z����N���A����
	animations_.clear();
	
}

int AnimationController::GetPlayType(void) const
{
	return playType_;
}

bool AnimationController::IsEnd(void) const
{

	bool ret = false;

	if (isLoop_)
	{
		// ���[�v�ݒ肳��Ă���Ȃ�A
		// �������ŏI�����Ȃ���Ԃ�
		return ret;
	}

	if (playAnim_.step >= playAnim_.totalTime)
	{
		// �Đ����Ԃ��߂�����true
		return true;
	}

	return ret;

}

const AnimationController::Animation& AnimationController::GetPlayAnim(void) const
{
	return playAnim_;
}

void AnimationController::Add(int type, float speed, Animation& animation)
{
	animation.speed = speed;

	if (animations_.count(type) == 0)
	{
		// �ǉ�
		animations_.emplace(type, animation);
	}
}
