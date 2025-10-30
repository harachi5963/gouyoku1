#pragma once
#include "../SceneBase.h"

class TitleScene : public SceneBase
{
	enum class De
	{
		DE_KANA,	// デ
		DE_KANJI,	// 出
		E,			// 江
	};

public:
	
	TitleScene(void);				// コンストラクタ
	~TitleScene(void) override;		// デストラクタ

	void Init(void)		override;	// 初期化
	void Load(void)		override;	// 読み込み
	void LoadEnd(void)	override;	// 読み込み後の処理
	void Update(void)	override;	// 更新
	void Draw(void)		override;	// 描画
	void Release(void)	override;	// 解放

	void toNextScene(void);			//次のシーンへ

private:

	int titleText_etaro;	// 　えた　口
	int titleText_ki_k;		// 消
	int titleText_ki;		// キ
	int titleText_de_k;		// 　　　出　
	int titleText_de;		// 　　　デ
	int titleText_e;		// 　　　江
	int title_Back;		//タイトルの背景

	int kitime_;				// 時間計測用
	int change_ki_Time_;	// 切り替える時間
	int detime_;				// 時間計測用
	int change_de_Time_;	// 切り替える時間

	bool text_ki_Change_;	// キを変える
	De text_de_Change_;	// デを変える
};
