//#include "Enemy.h"
//
//#include "../../../Application.h"
//#include "../../../Utility/AsoUtility.h"
//#include "../../../Utility/MatrixUtility.h"
//#include "../../Common/AnimationController.h"
//
//#include "../Player/Player.h"
//
//Enemy::Enemy(Player* player)
//{
//	player_ = player;
//}
//
//Enemy::~Enemy(void)
//{
//}
//
//void Enemy::Update(void)
//{
//	ActorBase::Update();
//
//	// ���G
//	Search();
//}
//
//void Enemy::Draw(void)
//{
//	if (isNoticeView_)
//	{
//		// ����͈͓��F�f�B�t���[�Y�J���[��ԐF�ɂ���
//		MV1SetMaterialDifColor(modelId_, 0, GetColorF(1.0f, 0.0f, 0.0f, 1.0f));
//	}
//	else if (isNoticeHearing_)
//	{
//		// ���o�͈͓��F�f�B�t���[�Y�J���[�����F�ɂ���
//		MV1SetMaterialDifColor(modelId_, 0, GetColorF(1.0f, 1.0f, 0.0f, 1.0f));
//	}
//	else
//	{
//		// ����͈͊O�F�f�B�t���[�Y�J���[���D�F�ɂ���
//		MV1SetMaterialDifColor(modelId_, 0, GetColorF(0.5f, 0.5f, 0.5f, 1.0f));
//	}
//
//	ActorBase::Draw();
//
//	// ����`��
//	DrawViewRange();
//}
//
//void Enemy::InitLoad(void)
//{
//	// ���f���̓ǂݍ���
//	modelId_ = MV1LoadModel((Application::PATH_MODEL + "Player/Player.mv1").c_str());
//}
//
//void Enemy::InitTransform(void)
//{
//	// ���f���̊p�x
//	angle_ = { 0.0f, AsoUtility::Deg2RadF(45.0f), 0.0f };
//	localAngle_ = { 0.0f, AsoUtility::Deg2RadF(180.0f), 0.0f };
//
//	// �p�x��������ɕϊ�����
//	moveDir_ = { sinf(angle_.y), 0.0f, cosf(angle_.y) };
//
//	// �s��̍���(�q, �e�Ǝw�肷��Ɛe�ˎq�̏��ɓK�p�����)
//	MATRIX mat = MatrixUtility::Multiplication(localAngle_, angle_);
//
//	// ��]�s������f���ɔ��f
//	MV1SetRotationMatrix(modelId_, mat);
//
//	// ���f���̈ʒu�ݒ�
//	pos_ = { 200.0f, 0.0f, 150.0f };
//	MV1SetPosition(modelId_, pos_);
//
//	// �����蔻����쐬
//	startCapsulePos_ = { 0.0f,110,0.0f };
//	endCapsulePos_ = { 0.0f,30.0f,0.0f };
//	capsuleRadius_ = 20.0f;
//
//	// �����蔻�����邩
//	isCollision_ = true;
//}
//
//void Enemy::InitAnimation(void)
//{
//	// ���f���A�j���[�V��������̏�����
//	animationController_ = new AnimationController(modelId_);
//
//	// �A�j���[�V�����̒ǉ�
//	animationController_->Add(
//		static_cast<int>(ANIM_TYPE::IDLE), 0.5f, Application::PATH_MODEL + "Player/Idle.mv1");
//	animationController_->Add(
//		static_cast<int>(ANIM_TYPE::WALK), 0.5f, Application::PATH_MODEL + "Player/Walk.mv1");
//
//	// �����A�j���[�V�����̍Đ�
//	animationController_->Play(static_cast<int>(ANIM_TYPE::WALK));
//}
//
//void Enemy::InitPost(void)
//{
//	isNoticeView_ = false;
//	isNoticeHearing_ = false;
//}
//
//void Enemy::DrawViewRange(void)
//{
//	float viewRad = AsoUtility::Deg2RadF(VIEW_ANGLE);
//
//	// �����p�x����������擾����
//	MATRIX mat = MGetIdent();
//	mat = MatrixUtility::GetMatrixRotateXYZ(angle_);
//
//	// �O������
//	VECTOR forward = VTransform(AsoUtility::DIR_F, mat);
//
//	// �E������
//	MATRIX rightMat = MMult(mat, MGetRotY(AsoUtility::Deg2RadF(VIEW_ANGLE)));
//	VECTOR right = VTransform(AsoUtility::DIR_F, rightMat);
//
//	// ��������
//	MATRIX leftMat = MMult(mat, MGetRotY(AsoUtility::Deg2RadF(-VIEW_ANGLE)));
//	VECTOR left = VTransform(AsoUtility::DIR_F, leftMat);
//
//	// �����̈ʒu
//	VECTOR pos0 = pos_;
//
//	// ���ʂ̈ʒu
//	VECTOR pos1 = VAdd(pos0, VScale(forward, VIEW_RANGE));
//
//	// ���ʂ��甽���v���
//	VECTOR pos2 = VAdd(pos0, VScale(left, VIEW_RANGE));
//
//	// ���ʂ��玞�v���
//	VECTOR pos3 = VAdd(pos0, VScale(right, VIEW_RANGE));
//
//	// ����
//	pos0.y = pos1.y = pos2.y = pos3.y = 10.0f;
//	DrawTriangle3D(pos0, pos2, pos1, 0xdd77dd, true);
//	DrawTriangle3D(pos0, pos1, pos3, 0xdd77dd, true);
//	DrawLine3D(pos0, pos1, 0x000000);
//	DrawLine3D(pos0, pos2, 0x000000);
//	DrawLine3D(pos0, pos3, 0x000000);
//
//	// ���o
//	DrawCone3D(
//		VAdd(pos_, { 0.0f, 0.0f, 0.0f }),
//		VAdd(pos_, { 0.0f, 1.0f, 0.0f }),
//		HEARING_RANGE, 10, 0xffff7f, 0xffff7f, true);
//}
//
//void Enemy::Search(void)
//{
//	// ���m�t���O���Z�b�g
//	isNoticeView_ = false;
//	isNoticeHearing_ = false;
//
//	// �v���C���[�̍��W���擾
//	VECTOR pPos = player_->GetPos();
//
//	// �G�l�~�[����v���C���[�܂ł̃x�N�g��
//	VECTOR diff = VSub(pPos, pos_);
//
//	// ����͈͂ɓ����Ă��邩���f(�s�^�S���X�̒藝)
//	float distance = std::pow(diff.x, 2.0f) + std::pow(diff.z, 2.0f);
//	if (distance <= (std::pow(VIEW_RANGE, 2.0f)))
//	{
//		// �G�l�~�[���猩���v���C���[�̊p�x�����߂�
//		float dot = VDot(VNorm(moveDir_), VNorm(diff));
//		float angle = acosf(dot);
//
//		// ����p�����W�A���ɕϊ�
//		const float viewRad = AsoUtility::Deg2RadF(VIEW_ANGLE);
//
//		// ����e���ɓ����Ă��邩���f
//		if (angle <= viewRad)
//		{
//			isNoticeView_ = true;
//		}
//	}
//
//	// ���o
//	if (distance <= (std::pow(HEARING_RANGE, 2.0f)))
//	{
//		isNoticeHearing_ = true;
//	}
//}
