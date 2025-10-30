#include "GameScene.h"

#include <DxLib.h>

#include "../../Application.h"
#include "../../Camera/Camera.h"

#include "../../Object/Actor/ActorBase.h"
#include "../../Object/Actor/Player/Player.h"
#include "../../Object/Actor/Enemy/Enemy.h"
#include "../../Object/Actor/Object/Pc.h"
#include "../../Object/Actor/Stage/Stage.h"
#include "../../Object/Actor/Object/VendingMachine.h"
#include "../../Object/Actor/Object/Door.h"
#include "../../Object/Actor/Object/Door2.h"
#include "../../Object/Actor/Object/Desuku.h"
#include "../../Object/Actor/Object/Chair.h"

#include "../../Utility/AsoUtility.h"
#include "../../Input/InputManager.h"

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
	camera_ = new Camera();						// �J�����̐���
	stage_ = new Stage();						// �X�e�[�W�̐���

	// �A�N�^�[�̐���
	ActorBase* player_ = new Player(camera_);	// �v���C���[�̐���
	ActorBase* vendingMachine = new VendingMachine();	// ���̋@�𐶐�
	ActorBase* door = new Door();						// �h�A�𐶐�
	ActorBase* door2 = new Door2();						// �h�A�𐶐�
	ActorBase* pc = new Pc();						// �h�A�𐶐�
	ActorBase* desuku1 = new Desuku();			//���𐶐�
	ActorBase* chair1 = new Chair();

	// �A�N�^�[�z��ɓ����
	allActor_.push_back(player_);
	allActor_.push_back(vendingMachine);
	allActor_.push_back(door);
	allActor_.push_back(door2);
	allActor_.push_back(pc);
	allActor_.push_back(desuku1);
	allActor_.push_back(chair1);

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
		if (actor->GetisCollision())
		{
			// �����蔻��
			FieldCollision(actor);
			WallCollision(actor);
		}
	}

	// �h�A�Ƃ̓����蔻��
	isDoorCollision();
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

void GameScene::isDoorCollision(void)
{
	// �v���C���[�̍��W�ێ��p
	ActorBase* player = nullptr;

	// �S�ẴI�u�W�F�N�g����
	for (auto actor : allActor_)
	{
		// �v���C���[��������
		if (actor->GetTag() == ActorBase::TAG::PLAYER)
		{
			player = actor;
		}
	}

	// �S�ẴI�u�W�F�N�g����
	for (auto actor : allActor_)
	{
		// �h�A����Ȃ��Ȃ画�肵�Ȃ�
		if (actor->GetTag() != ActorBase::TAG::DOOR)
		{
			// �h�A����Ȃ��̂ł��̃I�u�W�F�N�g���X�L�b�v
			continue;
		}

		// �I�u�W�F�N�g�ƃJ�������ڐG���Ă��邩�H
		if (AsoUtility::IsHitSpheres(
			actor->GetPos(),
			actor->GetSphereRadius(),
			player->GetPos(),
			player->GetSphereRadius()
		))
		{
			// �L�[��������Ă��邩�H
			if (InputManager::GetInstance()->IsTrgDown(KEY_INPUT_F))
			{
				// �J�����������ʒu��
				player->Init();

				// �h�A���J����
				isDoorOpen();
			}
		}
	}
}

void GameScene::isDoorOpen(void)
{
	// �S�ẴI�u�W�F�N�g����
	for (auto actor : allActor_)
	{
		if (actor->GetTag() != ActorBase::TAG::IHEN_OBJECT)
		{
			// �ٕσI�u�W�F�N�g����Ȃ��̂ŃX�L�b�v
			continue;
		}
		
		// �ٕσI�u�W�F�N�g�𔭌�
		actor->SetIhen(true);
	}
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
