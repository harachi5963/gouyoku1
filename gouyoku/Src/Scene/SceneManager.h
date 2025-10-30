#pragma once

class SceneBase;
class Loading;

class SceneManager
{

public:

	// �V�[���Ǘ��p
	enum class SCENE_ID
	{
		NONE,
		TITLE,
		GAME,
		CLEAR
	};

public:
	// �V���O���g���i�����E�擾�E�폜�j
	static void CreateInstance(void) { if (instance_ == nullptr) { instance_ = new SceneManager(); } };
	static SceneManager* GetInstance(void) { return instance_; };
	static void DeleteInstance(void) { if (instance_ != nullptr) { delete instance_; instance_ = nullptr; } }

private:

	// �ÓI�C���X�^���X
	static SceneManager* instance_;

	// �f�t�H���g�R���X�g���N�^��private�ɂ��āA
	// �O�����琶���ł��Ȃ��l�ɂ���
	SceneManager(void);
	// �f�X�g���N�^�����l
	~SceneManager(void);

	// �R�s�[�E���[�u������֎~
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
	SceneManager(SceneManager&&) = delete;
	SceneManager& operator=(SceneManager&&) = delete;

	// ���L���R���p�C���G���[�����邽�� ��L��ǉ�
	// SceneManager copy = *SceneManager::GetInstance();
	// SceneManager copied(*SceneManager::GetInstance());
	// SceneManager moved = std::move(*SceneManager::GetInstance());

public:

	void Init(void);	// ������
	void Init3D(void);	// 3D�̏�����
	void Update(void);	// �X�V
	void Draw(void);	// �`��
	void Delete(void);	// ���\�[�X�̔j��

	// ��ԑJ��
	void ChangeScene(SCENE_ID nextId);

	// �V�[��ID�̎擾
	SCENE_ID GetSceneID(void) { return sceneId_; };

	// �Q�[���I��
	void GameEnd(void) { isGameEnd_ = true; }

	// �Q�[���I���擾
	bool GetGameEnd(void) { return isGameEnd_; }

private:

	// �e��V�[��
	SceneBase* scene_;

	// ���[�h���
	Loading* load_;

	// �V�[��ID
	SCENE_ID sceneId_;

	// �Q�[���I��
	bool isGameEnd_;
};