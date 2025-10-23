#pragma once
#include <DxLib.h>

class ActorBase;

class Camera
{

public:

	// �J�����̏������W
	static constexpr VECTOR DERFAULT_POS = { 0.0f, 200.0f, -500.0f };

	// �J�����̏����p�x
	static constexpr VECTOR DERFAULT_ANGLES = { 
		0.0f, 0.0f, 0.0f
	};

	// �Ǐ]�Ώۂ���J�����ւ̑��΍��W
	static constexpr VECTOR FOLLOW_CAMERA_LOCAL_POS = { 0.0f, 200.0f, -350.0f };

	// �Ǐ]�Ώۂ��璍���_�ւ̑��΍��W
	static constexpr VECTOR FOLLOW_TARGET_LOCAL_POS = { 0.0f, 0.0f, 150.0f };

	// �J�����̃N���b�v�͈�
	static constexpr float VIEW_NEAR = 20.0f;
	static constexpr float VIEW_FAR = 5000.0f;
	
	// �J�������[�h
	enum class MODE
	{
		NONE,
		FIXED_POINT,	// ��_�J����
		FREE,			// �t���[���[�h
		FOLLOW,			// �Ǐ]���[�h
	};

	// �R���X�g���N�^
	Camera(void);

	// �f�X�g���N�^
	~Camera(void);

	// ������
	void Init(void);

	// �X�V
	void Update(void);

	// �`��O�̃J�����ݒ�
	void SetBeforeDraw(void);
	void SetBeforeDrawFixedPoint(void);
	void SetBeforeDrawFree(void);
	void SetBeforeDrawFollow(void);

	// �f�o�b�O�p�`��
	void DrawDebug(void);

	// ���
	void Release(void);

	// ���W�̎擾
	const VECTOR& GetPos(void) const { return pos_; }

	// �p�x�̎擾
	const VECTOR& GetAngle(void) const { return angle_; }
	
	// �����_�̎擾
	const VECTOR& GetTargetPos(void) const { return targetPos_; }

	// �J�������[�h�̕ύX
	void ChangeMode(MODE mode);

	// �Ǐ]����̐ݒ�
	void SetFollow(ActorBase* follow);

private:

	// �Ǐ]����
	ActorBase* follow_;

	// �J�������[�h
	MODE mode_;

	// �J�����̈ʒu
	VECTOR pos_;

	// �J�����̊p�x
	VECTOR angle_;
	
	// �����_
	VECTOR targetPos_;
	
	// ������]�ɂ��XYZ�̈ړ�
	void MoveXYZDirection(void);

	// ������]�ɂ��XYZ�̈ړ�(�Q�[���p�b�h)
	void MoveXYZDirectionPad(void);

};
