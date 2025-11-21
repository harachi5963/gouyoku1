#pragma once
#include "../SceneBase.h"

class TitleScene : public SceneBase
{
	enum class De
	{
		DE_HARA,	// 原
		DE_KANJI,	// 出
		E,			// 江
	};

	enum class Guti
	{
		TA,				// 田
		GUTI_KANJI,		// 口
	};

	enum class Eta
	{
		NARU,			//なる
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

	int titleText_eta;	    // 　えた　
	int titleText_guti;	    // 　　　　口　
	int titleText_ki_k;		// 消
	int titleText_ki;		// キ
	int titleText_de_k;		// 　　　出　
	int titleText_de;		// 　　　デ
	int titleText_e;		// 　　　江
	int titleText_hara;		//		 原
	int titleText_ta;		//		 　田
	int titleText_naka;		// 仲
	int titleText_naru;		//　 なる
	int title_Back;			//タイトルの背景

	int kitime_;			// 時間計測用
	int change_ki_Time_;	// 切り替える時間
	int etatime_;			// 時間計測用
	int change_eta_Time_;	// 切り替える時間
	int detime_;			// 時間計測用
	int change_de_Time_;	// 切り替える時間
	int gutitime_;			// 時間計測用
	int change_guti_Time_;	// 切り替える時間

	bool text_ki_Change_;	// 仲に変える
	bool text_eta_Change_;	//なるに変える
	De text_de_Change_;		// 原に変える
	Guti text_guti_Change_;	//田に変える
};
