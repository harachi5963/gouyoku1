#include "GameClear.h"
#include <DxLib.h>
#include "../SceneManager.h"
#include "../../Application.h"
#include "../../Input/InputManager.h"
#include "../../Audio/AudioManager.h"

ClearScene::ClearScene(void)
{
}

ClearScene::~ClearScene(void)
{
}

void ClearScene::Init(void)
{
	//ゲームクリア画像
	gameClearImgId_ = LoadGraph("Data/Image/end.png");

	frameCount_ = 0;  // フレームカウンタ初期化
	gameClearposY_ = 0;
}

void ClearScene::Load(void)
{
	AudioManager::GetInstance()->LoadSceneSound(LoadScene::CLEAR);
}

void ClearScene::LoadEnd(void)
{
	AudioManager::GetInstance()->PlayBGM(SoundID::BGM_CLEAR);

	Init();
}

void ClearScene::Update(void)
{
	frameCount_++;  // フレームカウント

	if (gameClearposY_ > -2000) {

		gameClearposY_ -= 1.0f;
	}
	else
	{
		toNextScene();
	}
}

void ClearScene::Draw(void)
{
	DrawGraph(0, gameClearposY_, gameClearImgId_, true);

	DrawFormatString(0, 0, 0xffffff, "%f", gameClearposY_);
}

void ClearScene::Release(void)
{
	DeleteGraph(gameClearImgId_);

	AudioManager::GetInstance()->DeleteSceneSound(LoadScene::CLEAR);
}

void ClearScene::toNextScene(void)
{
	if(InputManager::GetInstance()->IsTrgUp(KEY_INPUT_RETURN))
	//ゲームシーンへ
	SceneManager::GetInstance()->ChangeScene(SceneManager::SCENE_ID::TITLE);
}
