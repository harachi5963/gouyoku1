#pragma once
#include <string>
#include <DxLib.h>
class AnimationController;

class ActorBase
{
public:

	ActorBase(void);			// �R���X�g���N�^
	virtual ~ActorBase(void);	// �f�X�g���N�^

	void Init(void);			// ������
	void Load(void);			// �ǂݍ���
	void LoadEnd(void);			// �ǂݍ��݌�
	virtual void Update(void);	// �X�V
	virtual void Draw(void);	// �`��
	virtual void Release(void);	// ���

	// ���W���擾
	const VECTOR& GetPos(void) const { return pos_; }

	// �J�v�Z���̓����蔻����擾
	const VECTOR& GetStartCapsulePos(void) const { return startCapsulePos_; }
	const VECTOR& GetEndCapsulePos(void) const { return endCapsulePos_; }
	const float& GetCapsuleRadius(void) const { return capsuleRadius_; }

	const bool& GetisCollision(void) const { return isCollision_; }

	// �X�e�[�W�ƏՓ�
	void CollisionStage(const VECTOR& pos);

protected:

	// �A�j���[�V��������
	AnimationController* animationController_;

	// �A�j���[�V�������
	int animType_;

	// ���f�����
	int modelId_;
	VECTOR pos_;
	VECTOR angle_;
	VECTOR localAngle_;
	VECTOR scale_;

	// �J�v�Z���̓����蔻����W
	VECTOR startCapsulePos_;
	VECTOR endCapsulePos_;
	float capsuleRadius_;

	// �����蔻�����邩
	bool isCollision_;

	// �p�b�h���͒l�̕��
	VECTOR preInputDir_;

	// �ړ�����
	VECTOR moveDir_;

	// �W�����v��
	float jumpPow_;

	// ���\�[�X���[�h
	virtual void InitLoad(void) = 0;

	// �傫���A��]�A���W�̏�����
	virtual void InitTransform(void) = 0;

	// �A�j���[�V�����̏�����
	virtual void InitAnimation(void) = 0;

	// ��������̌ʏ���
	virtual void InitPost(void) = 0;

	// �ړ�����
	virtual void Move(void);

	// �x����]����
	void DelayRotate(void);

};
