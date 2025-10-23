#include "GameScene.h"

#include <DxLib.h>

#include "../../Application.h"
#include "../../Camera/Camera.h"

#include "../../Object/Actor/ActorBase.h"
#include "../../Object/Actor/Player/Player.h"
#include "../../Object/Actor/Enemy/Enemy.h"

#include "../../Object/Actor/Stage/Stage.h"

GameScene::GameScene(void)
{
}

GameScene::~GameScene(void)
{
}

void GameScene::Init(void)
{
	// �J�����̏�����
	camera_->Init();

	// �X�e�[�W������
	stage_->Init();

	// �S�ẴA�N�^�[��������
	for (auto actor : allActor_)
	{
		// ������
		actor->Init();
	}
}

void GameScene::Load(void)
{
	// ��������
	camera_ = new Camera();					// �J�����̐���
	stage_ = new Stage();					// �X�e�[�W�̐���
	Player* player_ = new Player(camera_);	// �v���C���[�̐���
	Enemy* enemy_ = new Enemy(player_);		// �G�̐���

	// �A�N�^�[�z��ɓ����
	allActor_.push_back(player_);
	allActor_.push_back(enemy_);

	// �J�������[�h�ύX
	camera_->SetFollow(player_);
	camera_->ChangeMode(Camera::MODE::FOLLOW);

	// �X�e�[�W�̓ǂݍ���
	stage_->Load();

	// �S�ẴA�N�^�[��ǂݍ���
	for (auto actor : allActor_)
	{
		// �ǂݍ���
		actor->Load();
	}
}

void GameScene::LoadEnd(void)
{
	// �J�����̏�����
	camera_->Init();

	// �X�e�[�W������
	stage_->LoadEnd();

	// �S�ẴA�N�^�[��ǂݍ��݌�
	for (auto actor : allActor_)
	{
		// �ǂݍ���
		actor->LoadEnd();
	}
}

void GameScene::Update(void)
{
	// �J�����̍X�V
	camera_->Update();

	// �X�e�[�W�X�V
	stage_->Update();

	// �S�ẴA�N�^�[����
	for (auto actor : allActor_)
	{
		// �X�V����
		actor->Update();

		// �����蔻�����邩�H
		if (actor)
		{
			// �����蔻��
			//FieldCollision(actor);
			WallCollision(actor);
		}
	}
}

void GameScene::Draw(void)
{
	// �J�����̕`��X�V
	camera_->SetBeforeDraw();

	// �X�e�[�W�`��
	stage_->Draw();

	// �S�ẴA�N�^�[����
	for (auto actor : allActor_)
	{
		// �X�V����
		actor->Draw();
	}
}

void GameScene::Release(void)
{
	// �X�e�[�W���
	stage_->Release();
	delete stage_;
	
	// �S�ẴA�N�^�[����
	for (auto actor : allActor_)
	{
		// �X�V����
		actor->Release();
		delete actor;
	}

	// �z����N���A
	allActor_.clear();
}

// �X�e�[�W�̏��ƃv���C���[�̏Փ�
void GameScene::FieldCollision(ActorBase* actor)
{
	// ���W������
	VECTOR actorPos = actor->GetPos();

	// �����̏���W
	VECTOR startPos = actorPos;
	startPos.y = actorPos.y + 10.0f;

	// �����̉����W
	VECTOR endPos = actorPos;
	endPos.y = actorPos.y - 10.0f;

	// �X�e�[�W�̃��f�����擾
	int modelId = stage_->GetModelId();

	// �����ƃ��f���̏Փ˔���
	MV1_COLL_RESULT_POLY res =
		MV1CollCheck_Line(modelId, -1, startPos, endPos);

	// �X�e�[�W�ɓ������Ă��邩�H
	if (res.HitFlag)
	{
		// ���������ꏊ�ɖ߂�
		actor->CollisionStage(res.HitPosition);
	}
}

void GameScene::WallCollision(ActorBase* actor)
{
	// ���W���擾
	VECTOR pos = actor->GetPos();

	// �J�v�Z���̍��W
	VECTOR capStartPos = VAdd(pos, actor->GetStartCapsulePos());
	VECTOR capEndPos = VAdd(pos, actor->GetEndCapsulePos());

	// �J�v�Z���Ƃ̓����蔻��
	auto hits = MV1CollCheck_Capsule
	(
		stage_->GetModelId(),			// �X�e�[�W�̃��f��ID
		-1,								// �X�e�[�W�S�Ẵ|���S�����w��
		capStartPos,					// �J�v�Z���̏�
		capEndPos,						// �J�v�Z���̉�
		actor->GetCapsuleRadius()		// �J�v�Z���̔��a
	);

	// �Փ˂����|���S���S�Ă̌���
	for (int i = 0; i < hits.HitNum; i++)
	{
		// �|���S����1���ɕ���
		auto hit = hits.Dim[i];

		// �|���S�������𐧌�(�S�Ă���������Əd���̂�)
		for (int tryCnt = 0; tryCnt < 10; tryCnt++)
		{
			// �ŏ��̏Փ˔���Ō��o�����Փ˃|���S��1���ƏՓ˔�������
			int pHit = HitCheck_Capsule_Triangle
			(
				capStartPos,					// �J�v�Z���̏�
				capEndPos,						// �J�v�Z���̉�
				actor->GetCapsuleRadius(),		// �J�v�Z���̔��a
				hit.Position[0],				// �|���S��1
				hit.Position[1],				// �|���S��2
				hit.Position[2]					// �|���S��3
			);

			// �J�v�Z���ƃ|���S�����������Ă���
			if (pHit)
			{
				// �������Ă����̂ō��W���|���S���̖@�������Ɉړ�������
				pos = VAdd(pos, VScale(hit.Normal, 1.0f));

				// ���̂̍��W���ړ�������
				capStartPos = VAdd(capStartPos, VScale(hit.Normal, 1.0f));
				capEndPos = VAdd(capEndPos, VScale(hit.Normal, 1.0f));

				// �����������Ă���\��������̂ōČ���
				continue;
			}
		}
	}
	// ���o�����|���S�����̌�n��
	MV1CollResultPolyDimTerminate(hits);

	// �v�Z�����ꏊ�ɃA�N�^�[��߂�
	actor->CollisionStage(pos);
}
