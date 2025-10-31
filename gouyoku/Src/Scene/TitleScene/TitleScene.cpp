#include "TitleScene.h"

#include <DxLib.h>


#include "../../Input/InputManager.h"
#include "../SceneManager.h"
#include "../../Application.h"

TitleScene::TitleScene(void)
{
}

TitleScene::~TitleScene(void)
{
}

void TitleScene::Init(void)
{
	titleText_etaro = LoadGraph("Data/Image/title_text_etaro.png");
	titleText_ki = LoadGraph("Data/Image/title_text_ki.png");
	titleText_ki_k = LoadGraph("Data/Image/title_text_ki_k.png");
	titleText_de = LoadGraph("Data/Image/title_text_de.png");
	titleText_de_k = LoadGraph("Data/Image/title_text_de_k.png");
	titleText_e = LoadGraph("Data/Image/title_text_e.png");
	title_Back = LoadGraph("Data/Image/Title_Background.png");

	kitime_ = 0;
	change_ki_Time_ = 30;	// �؂�ւ��鎞��
	detime_ = 0;
	change_de_Time_ = 50;	// �؂�ւ��鎞��

	text_ki_Change_ = false;	// �L��ς���
	text_de_Change_ = De::DE_KANJI;
}

void TitleScene::Load(void)
{
}

void TitleScene::LoadEnd(void)
{
	Init();
}

void TitleScene::Update(void)
{
	kitime_++;		// ���ƃL��؂�ւ��鎞��
	detime_++;		// �o�ƃf��؂�ւ��鎞��

	// �؂�ւ��鎞�Ԃɓ��B������
	if (kitime_ > change_ki_Time_)
	{
		// �����L�Ȃ̂��H
		if (text_ki_Change_)
		{
			// ���ɕύX
			text_ki_Change_ = false;
		}
		else
		{
			// �L�ɕύX
			text_ki_Change_ = true;
		}

		// ���ɐ؂�ւ��鎞�Ԃ��Đݒ�
		change_ki_Time_ = GetRand(100);
		// �v���p�̎��Ԃ����Z�b�g
		kitime_ = 0;
	}

	// �؂�ւ��鎞�Ԃɓ��B������
	if (detime_ > change_de_Time_)
	{
		int de = GetRand(2);

		switch (de)
		{
		case 0:
			text_de_Change_ = De::DE_KANA;
			break;
		case 1:
			text_de_Change_ = De::DE_KANJI;
			break;
		case 2:
			text_de_Change_ = De::E;
			break;
		}

		// ���ɐ؂�ւ��鎞�Ԃ��Đݒ�
		change_de_Time_ = GetRand(100);
		// �v���p�̎��Ԃ����Z�b�g
		detime_ = 0;
	}

	//���̃V�[���֑J�ڂ���
	toNextScene();
}

void TitleScene::Draw(void)
{
	//�^�C�g���w�i�̕`��
	DrawRotaGraph(500, 250, 1.0f, 0.0, title_Back, true);

	//������`��
	DrawRotaGraph(500, 250, 0.5f, 0.0, titleText_etaro, true);

	// ���ƃL���t���O�ŕ`���؂�ւ���
	if (text_ki_Change_)
	{
		// �L �����o��
		DrawRotaGraph(500, 250, 0.5f, 0.0, titleText_ki, true);
	}
	else
	{
		// �� �����o��
		DrawRotaGraph(500, 250, 0.5f, 0.0, titleText_ki_k, true);
	}

	switch (text_de_Change_)
	{
	case TitleScene::De::DE_KANA:
		DrawRotaGraph(500, 250, 0.5f, 0.0, titleText_de, true);
		break;
	case TitleScene::De::DE_KANJI:
		DrawRotaGraph(500, 250, 0.5f, 0.0, titleText_de_k, true);
		break;
	case TitleScene::De::E:
		DrawRotaGraph(500, 250, 0.5f, 0.0, titleText_e, true);
		break;
	default:
		break;
	}

	// ���Ԍo�߂��擾�i�~���b�P�ʁj
	int time = GetNowCount();

	// �_�ő��x�i600�~���b��ON/OFF�؂�ւ��j
	int blinkSpeed = 600;

	// ��莞�Ԃ��Ƃɕ\���E��\����؂�ւ���
	if ((time / blinkSpeed) % 3 == 0)
	{
		DrawFormatString(450, 500, GetColor(255, 255, 255), "Space Start");
	}
}

void TitleScene::Release(void)
{
	DeleteGraph(titleText_etaro);
	DeleteGraph(titleText_ki);
	DeleteGraph(titleText_ki_k);
	DeleteGraph(titleText_de);
	DeleteGraph(titleText_de_k);
	DeleteGraph(titleText_e);
}

void TitleScene::toNextScene(void)
{
	//�V�[���J��
	//�X�y�[�X�L�[�������ꂽ��
	if (InputManager::GetInstance()->IsTrgUp(KEY_INPUT_SPACE))
	{
		//�Q�[���V�[����
		SceneManager::GetInstance()->ChangeScene(SceneManager::SCENE_ID::GAME);
	}
}
