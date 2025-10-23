#pragma once
#include <string>

// �N���X�̑O���錾
class FpsControl;

class Application
{

public:

	// �X�N���[���T�C�Y
	static constexpr int SCREEN_SIZE_X = 1024;
	static constexpr int SCREEN_SIZE_Y = 640;

	// �f�[�^�p�X�֘A
	//-------------------------------------------
	static const std::string PATH_DATA;
	static const std::string PATH_IMAGE;
	static const std::string PATH_MODEL;
	static const std::string PATH_EFFECT;
	//-------------------------------------------

public:
	// �V���O���g���i�����E�擾�E�폜�j
	static void CreateInstance(void) { if (instance_ == nullptr) { instance_ = new Application(); } }
	static Application* GetInstance(void) { return instance_; }
	static void DeleteInstance(void) { if (instance_ != nullptr) delete instance_; instance_ = nullptr; }

private:
	// �ÓI�C���X�^���X
	static Application* instance_;

	// �f�t�H���g�R���X�g���N�^��private�ɂ��āA
	// �O�����琶���ł��Ȃ��l�ɂ���
	Application(void);

	// �f�X�g���N�^�����l
	~Application(void);

	// �R�s�[�E���[�u������֎~
	Application(const Application&) = delete;
	Application& operator=(const Application&) = delete;
	Application(Application&&) = delete;
	Application& operator=(Application&&) = delete;

	// ���L���R���p�C���G���[�����邽�� ��L��ǉ�
	// Application copy = *Application::GetInstance();
	// Application copied(*Application::GetInstance());
	// Application moved = std::move(*Application::GetInstance());

public:

	void Init(void);		// ������
	void Run(void);			// �Q�[�����[�v�̊J�n
	void Delete(void);		// ���\�[�X�̔j��
	
	bool IsInitFail(void) const;	// �����������^���s�̔���
	bool IsReleaseFail(void) const;	// ��������^���s�̔���

private:

	// ���������s
	bool isInitFail_;

	// ������s
	bool isReleaseFail_;

	// FPS
	FpsControl* fps_;
};
