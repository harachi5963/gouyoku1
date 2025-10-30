#pragma once
#include "../ActorBase.h"

class Pc :public ActorBase
{
public:
	Pc();
	~Pc();


	// �A�j���[�V�������
	enum class ANIM_TYPE
	{
		OPEN,
		NON,
	};

public:

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

};
