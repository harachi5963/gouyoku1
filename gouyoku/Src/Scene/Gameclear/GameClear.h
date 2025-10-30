#pragma once
#pragma once
#include "../SceneBase.h"

class ClearScene : public SceneBase
{

public:

	bool isGameClear = false;

	//ゲームクリア
	static constexpr float GAME_CLEAR = 1;


	ClearScene(void);				// コンストラクタ
	~ClearScene(void) override;		// デストラクタ

	void Init(void)		override;	// 初期化
	void Load(void)		override;	// 読み込み
	void LoadEnd(void)	override;	// 読み込み後の処理
	void Update(void)	override;	// 更新
	void Draw(void)		override;	// 描画
	void Release(void)	override;	// 解放

	void toNextScene(void);			//次のシーンへ

private:

	int gameClearImgId_;
	int frameCount_;   // 追加：表示フレームカウンタ

	float gameClearposY_;
};
