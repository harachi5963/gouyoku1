#pragma once
#include "../ActorBase.h"

class Pettobotorugomi :public ActorBase
{
public:
	Pettobotorugomi();
	~Pettobotorugomi();

	//自己発光
	static constexpr COLOR_F EMI_COLOR = { 1.0f,1.0f,1.0f,1.0f };

public:

	// 更新
	void Update(void) override;

	// 描画
	void Draw(void) override;

	// 解放
	void Release(void) override;

private:

	// リソースロード
	void InitLoad(void) override;

	// 大きさ、回転、座標の初期化
	void InitTransform(void) override;

	// アニメーションの初期化
	void InitAnimation(void) override;

	// 初期化後の個別処理
	void InitPost(void) override;

};
