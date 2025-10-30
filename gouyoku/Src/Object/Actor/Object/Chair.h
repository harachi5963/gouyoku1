#pragma once
#include "../ActorBase.h"

class Chair:public ActorBase
{
public:
	Chair();
	~Chair();
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


