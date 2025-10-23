#pragma once

class Loading
{

private:
	// �Œ�ł����[�h��ʂ�\�����鎞��
	static constexpr int MIN_LOAD_TIME = 60;	// 60fps(1�b) * x

public:
	// �f�t�H���g�R���X�g���N�^��private�ɂ��āA
	// �O�����琶���ł��Ȃ��l�ɂ���
	Loading();
	~Loading();

	void Init(void);		// ������
	void Load(void);		// �ǂݍ���
	void Update(void);		// �X�V
	void Draw(void);		// �`��
	void Release(void);		// ���

	void StartAsyncLoad(void);	// �񓯊����[�h�̊J�n
	void EndAsyncLoad(void);	// �񓯊����[�h�̏I��

	// ���[�h������Ԃ��B
	bool IsLoading(void) { return isLoading_; }

private:

	// �摜�n���h��
	int handle_;

	// ���W
	float posX_;	// X���W
	float posY_;	// Y���W

	// ���[�h���̔���p
	bool isLoading_;

	// �Œ�ł����[�h��ʂ�\�����鎞�Ԃ͈̔�
	int loadTimer_;
};
