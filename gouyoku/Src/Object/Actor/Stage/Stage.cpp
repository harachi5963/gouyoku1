#include "Stage.h"

#include "../../../Application.h"

Stage::Stage(void)
{
	modelId_ = -1;
	pos_ = { 0.0f, 0.0f, 0.0f };
}

Stage::~Stage(void)
{
}

void Stage::Init(void)
{
	// ���f���̈ʒu
	pos_ = { 0.0f, 0.0f, 0.0f };

	// ���f���̈ʒu��ݒ�
	MV1SetPosition(modelId_, pos_);

	// �}�e���A���̐����擾
	int num = MV1GetMaterialNum(modelId_);
	for (int i = 1; i < num; i++)
	{
		// 0�͒n�ʂȂ̂ŁA1����ݒ肷��
		MV1SetMaterialEmiColor(modelId_, i, GetColorF(0.2f, 0.2f, 0.2f, 1.0f));
	}

	// �Փ˔�����̍\�z
	MV1SetupCollInfo(modelId_, -1);

	//���Ȕ��s
	MV1SetMaterialAmbColor(modelId_, 0, EMI_COLOR);
	MV1SetMaterialDifColor(modelId_, 0, EMI_COLOR);
}

void Stage::Load(void)
{
	// �X�e�[�W���f���̓ǂݍ���
	modelId_ = MV1LoadModel((Application::PATH_MODEL + "Stage/Stage.mv1").c_str());
}

void Stage::LoadEnd(void)
{
	Init();
}

void Stage::Update(void)
{
}

void Stage::Draw(void)
{
	// �X�e�[�W���f���`��
	MV1DrawModel(modelId_);
}

void Stage::Release(void)
{
	MV1DeleteModel(modelId_);
}

int Stage::GetModelId(void)
{
	return modelId_;
}
