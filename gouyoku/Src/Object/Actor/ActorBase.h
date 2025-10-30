#pragma once
#include <string>
#include <DxLib.h>
class AnimationController;

class ActorBase
{
public:
	enum TAG
	{
		NON,
		PLAYER,
		HUMAN,
		IHEN_OBJECT,
		DOOR,
	};

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

	// �����蔻��̃t���O���擾
	const bool& GetisCollision(void) const { return isCollision_; }

	// ���̂̓����蔻��̔��a���擾
	const float GetSphereRadius(void)const { return sphereRadius_; }

	// �^�O���擾
	const TAG GetTag(void)const { return tag_; }

	// �ٕσt���O���Z�b�g
	const void SetIhen(bool isihen) { isIhen_ = isihen; }

	// �X�e�[�W�ƏՓ�
	void CollisionStage(const VECTOR& pos);

protected:

	// �A�j���[�V��������
	AnimationController* animationController_;

	// �A�j���[�V�������
	int animType_;

	// ���f�����
	int modelId_;
	int ihenModelId_;

	VECTOR pos_;
	VECTOR angle_;
	VECTOR localAngle_;
	VECTOR scale_;

	// ���̂̓����蔻��̑傫��
	float sphereRadius_;

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

	// �^�O�̐ݒ�
	TAG tag_;

	// �`��t���O
	bool isDraw_;

	// �d�̓t���O
	bool isGravity_;

	// �ٕσt���O
	bool isIhen_;

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
