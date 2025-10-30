#pragma once
#pragma once
#include "../SceneBase.h"

class ClearScene : public SceneBase
{

public:

	bool isGameClear = false;

	//�Q�[���N���A
	static constexpr float GAME_CLEAR = 1;


	ClearScene(void);				// �R���X�g���N�^
	~ClearScene(void) override;		// �f�X�g���N�^

	void Init(void)		override;	// ������
	void Load(void)		override;	// �ǂݍ���
	void LoadEnd(void)	override;	// �ǂݍ��݌�̏���
	void Update(void)	override;	// �X�V
	void Draw(void)		override;	// �`��
	void Release(void)	override;	// ���

	void toNextScene(void);			//���̃V�[����

private:

	int gameClearImgId_;
	int frameCount_;   // �ǉ��F�\���t���[���J�E���^

	float gameClearposY_;
};
