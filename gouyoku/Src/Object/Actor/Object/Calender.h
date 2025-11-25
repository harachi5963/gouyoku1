#pragma once
#include"../ActorBase.h"

class Calender:public ActorBase
{
public:
	enum class CALENDER
	{
		JAN,	// 1月
		FEB,	// 2月
		MAR,	// 3月
		APR,	// 4月
		MAY,	// 5月
		JNU,	// 6月
		JUL,	// 7月
		AUG,	// 8月
		SEP,	// 9月
		OCT,	// 10月
		NOV,	// 11月
		DEC,	// 12月

		MAX
	};

public:
	Calender();
	~Calender()override;

	void Update(void)override;
	void Draw(void)override;
	void Release(void)override;

	void SetCalender(CALENDER calender) { nowCalender_ = calender; }

private:

	// カレンダー
	CALENDER nowCalender_;

	// モデルハンドル
	int calenderModelId_[static_cast<int>(CALENDER::MAX)];

	// リソースロード
	void InitLoad(void) override;

	// 大きさ、回転、座標の初期化
	void InitTransform(void) override;

	// アニメーションの初期化
	void InitAnimation(void) override;

	// 初期化後の個別処理
	void InitPost(void) override;

};

