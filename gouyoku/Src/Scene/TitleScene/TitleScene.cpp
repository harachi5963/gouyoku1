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
	change_ki_Time_ = 30;	// 切り替える時間
	detime_ = 0;
	change_de_Time_ = 50;	// 切り替える時間

	text_ki_Change_ = false;	// キを変える
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
	kitime_++;		// 消とキを切り替える時間
	detime_++;		// 出とデを切り替える時間

	// 切り替える時間に到達したら
	if (kitime_ > change_ki_Time_)
	{
		// 今がキなのか？
		if (text_ki_Change_)
		{
			// 消に変更
			text_ki_Change_ = false;
		}
		else
		{
			// キに変更
			text_ki_Change_ = true;
		}

		// 次に切り替える時間を再設定
		change_ki_Time_ = GetRand(100);
		// 計測用の時間をリセット
		kitime_ = 0;
	}

	// 切り替える時間に到達したら
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

		// 次に切り替える時間を再設定
		change_de_Time_ = GetRand(100);
		// 計測用の時間をリセット
		detime_ = 0;
	}

	//次のシーンへ遷移する
	toNextScene();
}

void TitleScene::Draw(void)
{
	//タイトル背景の描画
	DrawRotaGraph(500, 250, 1.0f, 0.0, title_Back, true);

	//文字を描画
	DrawRotaGraph(500, 250, 0.5f, 0.0, titleText_etaro, true);

	// 消とキをフラグで描画を切り替える
	if (text_ki_Change_)
	{
		// キ えた出口
		DrawRotaGraph(500, 250, 0.5f, 0.0, titleText_ki, true);
	}
	else
	{
		// 消 えた出口
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

	// 時間経過を取得（ミリ秒単位）
	int time = GetNowCount();

	// 点滅速度（600ミリ秒でON/OFF切り替え）
	int blinkSpeed = 600;

	// 一定時間ごとに表示・非表示を切り替える
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
	//シーン遷移
	//スペースキーが押されたら
	if (InputManager::GetInstance()->IsTrgUp(KEY_INPUT_SPACE))
	{
		//ゲームシーンへ
		SceneManager::GetInstance()->ChangeScene(SceneManager::SCENE_ID::GAME);
	}
}
