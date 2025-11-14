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
	titleText_eta = LoadGraph("Data/Image/title_text_eta.png");
	titleText_guti = LoadGraph("Data/Image/title_text_kuti.png");
	titleText_ki_k = LoadGraph("Data/Image/title_text_ki_k.png");
	titleText_de_k = LoadGraph("Data/Image/title_text_de_k.png");
	titleText_e = LoadGraph("Data/Image/title_text_e.png");
	titleText_hara = LoadGraph("Data/Image/title_text_hara.png");
	titleText_ta = LoadGraph("Data/Image/title_text_ta.png");
	titleText_naka = LoadGraph("Data/Image/title_text_naka.png");
	titleText_naru = LoadGraph("Data/Image/title_text_naru.png");
	title_Back = LoadGraph("Data/Image/Title_Background.png");

	kitime_ = 0;
	change_ki_Time_ = 300;	// 切り替える時間
	etatime_ = 0;
	change_eta_Time_ = 200;	// 切り替える時間
	detime_ = 0;
	change_de_Time_ = 307;	// 切り替える時間
	gutitime_ = 0;
	change_guti_Time_ = 70;	// 切り替える時間

	text_ki_Change_ = false;	// 消を変える
	text_eta_Change_ = false;	// えたを変える
	text_de_Change_ = De::DE_KANJI;
	text_guti_Change_ = Guti::TA;
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
	kitime_++;		// 消と仲を切り替える時間
	etatime_++;		// えたとなるを切り替える時間
	detime_++;		// 出と原を切り替える時間
	gutitime_++;	// 口と田を切り替える時間

	// 切り替える時間に到達したら
	if (kitime_ > change_ki_Time_)
	{
		// 今が仲なのか？
		if (text_ki_Change_)
		{
			// 消に変更
			text_ki_Change_ = false;
		}
		else
		{
			// 仲に変更
			text_ki_Change_ = true;
		}

		if (text_ki_Change_)
		{
			// 次に切り替える時間を再設定
			change_ki_Time_ = GetRand(100);
		}
		else
		{
			// 次に切り替える時間を再設定
			change_ki_Time_ = GetRand(1200);
		}

		// 計測用の時間をリセット
		kitime_ = 0;
	}

	// 切り替える時間に到達したら
	if (etatime_ > change_eta_Time_)
	{
		// 今がえたなのか？
		if (text_eta_Change_)
		{
			// えたに変更
			text_eta_Change_ = false;
		}
		else
		{
			// なるに変更
			text_eta_Change_ = true;
		}

		if (text_eta_Change_)
		{
			// 次に切り替える時間を再設定
			change_eta_Time_ = GetRand(100);
		}
		else
		{
			// 次に切り替える時間を再設定
			change_eta_Time_ = GetRand(1300);
		}

		// 計測用の時間をリセット
		etatime_ = 0;
	}

	// 切り替える時間に到達したら
	if (detime_ > change_de_Time_)
	{
		int de = GetRand(2);

		switch (de)
		{
		case 0:
			text_de_Change_ = De::DE_HARA;
			// 次に切り替える時間を再設定
			change_de_Time_ = GetRand(100);
			break;
		case 1:
			text_de_Change_ = De::DE_KANJI;
			// 次に切り替える時間を再設定
			change_de_Time_ = GetRand(100);
			break;
		case 2:
			text_de_Change_ = De::E;
			// 次に切り替える時間を再設定
			change_de_Time_ = GetRand(100);
			break;
		}

		// 計測用の時間をリセット
		detime_ = 0;
	}

	// 切り替える時間に到達したら
	if (gutitime_ > change_guti_Time_)
	{
		int guti = GetRand(2);

		switch (guti)
		{
		case 0:
			text_guti_Change_ = Guti::TA;
			break;
		case 1:
			text_guti_Change_ = Guti::GUTI_KANJI;
			break;
		}

		// 次に切り替える時間を再設定
		change_guti_Time_ = GetRand(100);
		// 計測用の時間をリセット
		gutitime_ = 0;
	}

	//次のシーンへ遷移する
	toNextScene();
}

void TitleScene::Draw(void)
{
	//タイトル背景の描画
	DrawRotaGraph(500, 250, 1.0f, 0.0, title_Back, true);

	// えたとなるをフラグで描画を切り替える
	if (text_eta_Change_)
	{
		// 消 えた 出口
		DrawRotaGraph(500, 250, 0.5f, 0.0, titleText_naru, true);
	}
	else
	{
		// 消 なる 出口
		DrawRotaGraph(500, 250, 0.5f, 0.0, titleText_eta, true);
	}


	// 消と仲をフラグで描画を切り替える
	if (text_ki_Change_)
	{
		// 仲 えた出口
		DrawRotaGraph(500, 250, 0.5f, 0.0, titleText_naka, true);
	}
	else
	{
		// 消 えた出口
		DrawRotaGraph(500, 250, 0.5f, 0.0, titleText_ki_k, true);
	}

	switch (text_de_Change_)
	{
	case TitleScene::De::DE_HARA:
		DrawRotaGraph(500, 250, 0.5f, 0.0, titleText_hara, true);
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

	switch (text_guti_Change_)
	{
	case TitleScene::Guti::TA:
		DrawRotaGraph(500, 250, 0.5f, 0.0, titleText_guti, true);
		break;
	case TitleScene::Guti::GUTI_KANJI:
		DrawRotaGraph(500, 250, 0.5f, 0.0, titleText_ta, true);
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
	DeleteGraph(titleText_eta);
	DeleteGraph(titleText_guti);
	DeleteGraph(titleText_ki);
	DeleteGraph(titleText_ki_k);
	DeleteGraph(titleText_de);
	DeleteGraph(titleText_de_k);
	DeleteGraph(titleText_e);
	DeleteGraph(titleText_hara);
	DeleteGraph(titleText_ta);
	DeleteGraph(titleText_naka);
	DeleteGraph(titleText_naru);
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
