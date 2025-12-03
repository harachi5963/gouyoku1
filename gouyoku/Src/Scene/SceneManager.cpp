#include "SceneManager.h"

#include <DxLib.h>

#include "Loading/Loading.h"
#include "TitleScene/TitleScene.h"
#include "GameScene/GameScene.h"
#include"Gameclear/GameClear.h"
#include "../Input/InputManager.h"

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
	// ロード画面生成
	load_ = new Loading();
	load_->Init();
	load_->Load();

	// 3D情報の初期化
	Init3D();

	// 最初はタイトル画面から
	ChangeScene(SCENE_ID::TITLE);
}

void SceneManager::Init3D(void)
{
	// 背景色設定
	SetBackgroundColor(0, 0, 0);

	// Zバッファを有効にする
	SetUseZBuffer3D(true);

	// Zバッファへの書き込みを有効にする
	SetWriteZBuffer3D(true);

	// バックカリングを有効にする
	SetUseBackCulling(true);

	// ライトの設定
	SetUseLighting(true);

	// 正面から斜め下に向かったライト
	ChangeLightTypeDir({ 0.00f, 1.00f, 1.00f });
}

// 更新
void SceneManager::Update(void)
{
	// シーンがなければ終了
	if (scene_ == nullptr) { return; }

	// ロード中
	if (load_->IsLoading())
	{
		// ロード更新
		load_->Update();

		// ロードの更新が終了していたら
		if (load_->IsLoading() == false)
		{
			// ロード後の初期化
			scene_->LoadEnd();
		}
	}
	// 通常の更新処理
	else
	{
		ChangeLightTypeDir({ testX_, testY_, testZ_ });

		if (InputManager::GetInstance()->IsTrgDown(KEY_INPUT_1))
		{
			testX_ += 0.1f;

		}
		if (InputManager::GetInstance()->IsTrgDown(KEY_INPUT_4))
		{
			testX_ -= 0.1f;
		}
		if (InputManager::GetInstance()->IsTrgDown(KEY_INPUT_2))
		{
			testY_ += 0.1f;

		}

		if (InputManager::GetInstance()->IsTrgDown(KEY_INPUT_5))
		{
			testY_ -= 0.1f;
		}
		if (InputManager::GetInstance()->IsTrgDown(KEY_INPUT_3))
		{
			testZ_ += 0.1f;

		}
		if (InputManager::GetInstance()->IsTrgDown(KEY_INPUT_6))
		{
			testZ_ -= 0.1f;
		}
		// 現在のシーンの更新
		scene_->Update();
	}
}

void SceneManager::Draw(void)
{
	// ロード中ならロード画面を描画
	if (load_->IsLoading())
	{
		// ロードの描画
		load_->Draw();
	}
	// 通常の更新
	else
	{
		//　現在のシーン描画
		scene_->Draw();
	}

	DrawFormatString(0, 0, 0xffffff, "X = %f.2, Y = %f.2, Z = %f.2", testX_, testY_, testZ_);
}

void SceneManager::Delete(void)
{
	// 現在のシーンの解放・削除
	scene_->Release();
	delete scene_;

	// ロード画面の削除
	load_->Release();
	delete load_;
}

void SceneManager::ChangeScene(SCENE_ID nextId)
{
	// シーンを変更する
	sceneId_ = nextId;

	// 現在のシーンを解放
	if (scene_ != nullptr)
	{
		scene_->Release();
		delete scene_;
	}

	// 各シーンに切り替え
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
	case SceneManager::SCENE_ID::CLEAR:
		scene_ = new ClearScene();
		break;
	default:
		break;
	}

	// 読み込み(非同期)
	load_->StartAsyncLoad();
	scene_->Load();
	load_->EndAsyncLoad();
}
