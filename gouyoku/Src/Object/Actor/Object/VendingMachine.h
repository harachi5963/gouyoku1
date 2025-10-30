#pragma once
#include "../ActorBase.h"

class VendingMachine :public ActorBase
{
public:
	VendingMachine();
	~VendingMachine();


	// �A�j���[�V�������
	enum class ANIM_TYPE
	{
		OPEN,
		NON,
	};

	//���Ȕ���
	static constexpr COLOR_F EMI_COLOR = { 1.0f,1.0f,1.0f,1.0f };
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
