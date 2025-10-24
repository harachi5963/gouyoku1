#include "SceneManager.h"

#include <DxLib.h>

#include "Loading/Loading.h"
#include "TitleScene/TitleScene.h"
#include "GameScene/GameScene.h"

SceneManager* SceneManager::instance_ = nullptr;

SceneManager::SceneManager(void)
{
	scene_ = nullptr;
	load_ = nullptr;
	sceneId_ = SCENE_ID::NONE;
	isGameEnd_ = false;
}

SceneManager::~SceneManager(void)
{
}

void SceneManager::Init(void)
{
	// ���[�h��ʐ���
	load_ = new Loading();
	load_->Init();
	load_->Load();

	// 3D���̏�����
	Init3D();

	// �ŏ��̓^�C�g����ʂ���
	ChangeScene(SCENE_ID::GAME);
}

void SceneManager::Init3D(void)
{
	// �w�i�F�ݒ�
	SetBackgroundColor(0, 0, 0);

	// Z�o�b�t�@��L���ɂ���
	SetUseZBuffer3D(true);

	// Z�o�b�t�@�ւ̏������݂�L���ɂ���
	SetWriteZBuffer3D(true);

	// �o�b�N�J�����O��L���ɂ���
	SetUseBackCulling(true);

	// ���C�g�̐ݒ�
	SetUseLighting(true);

	// ���ʂ���΂߉��Ɍ����������C�g
	ChangeLightTypeDir({ 0.00f, -1.00f, 1.00f });
}

// �X�V
void SceneManager::Update(void)
{
	// �V�[�����Ȃ���ΏI��
	if (scene_ == nullptr) { return; }

	// ���[�h��
	if (load_->IsLoading())
	{
		// ���[�h�X�V
		load_->Update();

		// ���[�h�̍X�V���I�����Ă�����
		if (load_->IsLoading() == false)
		{
			// ���[�h��̏�����
			scene_->LoadEnd();
		}
	}
	// �ʏ�̍X�V����
	else
	{
		// ���݂̃V�[���̍X�V
		scene_->Update();
	}
}

void SceneManager::Draw(void)
{
	// ���[�h���Ȃ烍�[�h��ʂ�`��
	if (load_->IsLoading())
	{
		// ���[�h�̕`��
		load_->Draw();
	}
	// �ʏ�̍X�V
	else
	{
		//�@���݂̃V�[���`��
		scene_->Draw();
	}
}

void SceneManager::Delete(void)
{
	// ���݂̃V�[���̉���E�폜
	scene_->Release();
	delete scene_;

	// ���[�h��ʂ̍폜
	load_->Release();
	delete load_;
}

void SceneManager::ChangeScene(SCENE_ID nextId)
{
	// �V�[����ύX����
	sceneId_ = nextId;

	// ���݂̃V�[�������
	if (scene_ != nullptr)
	{
		scene_->Release();
		delete scene_;
	}

	// �e�V�[���ɐ؂�ւ�
	switch (sceneId_)
	{
	case SceneManager::SCENE_ID::NONE:
		break;
	case SceneManager::SCENE_ID::TITLE:
		scene_ = new TitleScene();
		break;
	case SceneManager::SCENE_ID::GAME:
		scene_ = new GameScene();
		break;
	default:
		break;
	}

	// �ǂݍ���(�񓯊�)
	load_->StartAsyncLoad();
	scene_->Load();
	load_->EndAsyncLoad();
}
