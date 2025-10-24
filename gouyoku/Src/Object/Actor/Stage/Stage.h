#pragma once
#include <DxLib.h>

class Stage
{

public:

	Stage(void);
	~Stage(void);

	//���Ȕ���
	static constexpr COLOR_F EMI_COLOR = { 1.0f,1.0f,1.0f,1.0f };

	void Init(void);
	void Load(void);
	void LoadEnd(void);
	void Update(void);
	void Draw(void);
	void Release(void);

	// �X�e�[�W���f���̃n���h��ID
	int GetModelId(void);

private:

	// �X�e�[�W���f���̃n���h��ID
	int modelId_;

	// �X�e�[�W���f���̈ʒu
	VECTOR pos_;

};

