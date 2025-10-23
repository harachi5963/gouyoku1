#pragma once
#include "../ActorBase.h"

class Player;

class Enemy : public ActorBase
{

public:

	// ����̍L��
	static constexpr float VIEW_RANGE = 600.0f;

	// ����p
	static constexpr float VIEW_ANGLE = 30.0f;

	// ���o�̍L��
	static constexpr float HEARING_RANGE = 400.0f;

	// �A�j���[�V�������
	enum class ANIM_TYPE
	{
		IDLE,
		WALK,
		MAX,
	};

public:
	// �R���X�g���N�^
	Enemy(Player* player);

	// �f�X�g���N�^
	~Enemy(void) override;

	// �X�V
	void Update(void) override;

	// �`��
	void Draw(void) override;

private:

	// ���\�[�X���[�h
	void InitLoad(void) override;

	// �傫���A��]�A���W�̏�����
	void InitTransform(void) override;

	// �A�j���[�V�����̏�����
	void InitAnimation(void) override;

	// ��������̌ʏ���
	void InitPost(void) override;

	// ����`��
	void DrawViewRange(void);

private:

	// �v���C���[
	Player* player_;
	
	// ���m�t���O(����)
	bool isNoticeView_;

	// ���m�t���O(���o)
	bool isNoticeHearing_;

	// ���G
	void Search(void);
};
