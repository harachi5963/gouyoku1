#pragma once
#include <vector>
#include <DxLib.h>

#include "../ActorBase.h"

class Camera;

class Player : public ActorBase
{

public:

	// �A�j���[�V�������
	enum class ANIM_TYPE
	{
		IDLE,
		WALK,
		MAX,
	};

	// �R���X�g���N�^
	Player(Camera* camera);

	// �f�X�g���N�^
	~Player(void) override;

	// �X�V
	void Update(void) override;

	// �`��
	void Draw(void) override;

	// ���
	void Release(void) override;

private:

	// ���\�[�X���[�h
	void InitLoad(void) override;

	// �傫���A��]�A���W�̏�����
	void InitTransform(void) override;

	// �A�j���[�V�����̏�����
	void InitAnimation(void) override;

	// ��������̌ʏ���
	void InitPost(void) override;

	// �ړ�����
	void Move(void) override;

private:
	// �J����
	Camera* camera_;
};
