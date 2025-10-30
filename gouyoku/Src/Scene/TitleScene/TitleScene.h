#pragma once
#include "../SceneBase.h"

class TitleScene : public SceneBase
{
	enum class De
	{
		DE_KANA,	// �f
		DE_KANJI,	// �o
		E,			// �]
	};

public:
	
	TitleScene(void);				// �R���X�g���N�^
	~TitleScene(void) override;		// �f�X�g���N�^

	void Init(void)		override;	// ������
	void Load(void)		override;	// �ǂݍ���
	void LoadEnd(void)	override;	// �ǂݍ��݌�̏���
	void Update(void)	override;	// �X�V
	void Draw(void)		override;	// �`��
	void Release(void)	override;	// ���

	void toNextScene(void);			//���̃V�[����

private:

	int titleText_etaro;	// �@�����@��
	int titleText_ki_k;		// ��
	int titleText_ki;		// �L
	int titleText_de_k;		// �@�@�@�o�@
	int titleText_de;		// �@�@�@�f
	int titleText_e;		// �@�@�@�]
	int title_Back;		//�^�C�g���̔w�i

	int kitime_;				// ���Ԍv���p
	int change_ki_Time_;	// �؂�ւ��鎞��
	int detime_;				// ���Ԍv���p
	int change_de_Time_;	// �؂�ւ��鎞��

	bool text_ki_Change_;	// �L��ς���
	De text_de_Change_;	// �f��ς���
};
