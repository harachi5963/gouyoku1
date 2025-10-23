#pragma once
#include "../SceneBase.h"

class TitleScene : public SceneBase
{

public:
	
	TitleScene(void);				// �R���X�g���N�^
	~TitleScene(void) override;		// �f�X�g���N�^

	void Init(void)		override;	// ������
	void Load(void)		override;	// �ǂݍ���
	void LoadEnd(void)	override;	// �ǂݍ��݌�̏���
	void Update(void)	override;	// �X�V
	void Draw(void)		override;	// �`��
	void Release(void)	override;	// ���

private:

	int handle_;
};
