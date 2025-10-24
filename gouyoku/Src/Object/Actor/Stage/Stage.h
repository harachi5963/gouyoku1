#pragma once
#include <DxLib.h>

class Stage
{

public:

	Stage(void);
	~Stage(void);

	//自己発光
	static constexpr COLOR_F EMI_COLOR = { 1.0f,1.0f,1.0f,1.0f };

	void Init(void);
	void Load(void);
	void LoadEnd(void);
	void Update(void);
	void Draw(void);
	void Release(void);

	// ステージモデルのハンドルID
	int GetModelId(void);

private:

	// ステージモデルのハンドルID
	int modelId_;

	// ステージモデルの位置
	VECTOR pos_;

};

