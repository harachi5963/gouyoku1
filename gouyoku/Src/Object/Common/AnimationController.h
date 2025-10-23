#pragma once
#include <string>
#include <map>

class AnimationController
{

public:

	// �A�j���[�V�����f�[�^
	struct Animation
	{
		int model = -1;
		int attachNo = -1;
		int animIndex = 0;
		float speed = 0.0f;
		float totalTime = 0.0f;
		float step = 0.0f;
	};

	// �R���X�g���N�^
	AnimationController(int modelId);

	// �f�X�g���N�^
	~AnimationController(void);

	// �O��FBX����A�j���[�V�����ǉ�
	void Add(int type, float speed, const std::string path);
	
	// ����FBX���̃A�j���[�V����������
	void AddInFbx(int type, float speed, int animIndex);

	// �A�j���[�V�����Đ�
	void Play(int type, bool isLoop = true);

	void Update(void);
	void Release(void);

	// �Đ����̃A�j���[�V����
	int GetPlayType(void) const;

	// �Đ��I��
	bool IsEnd(void) const;

	// �Đ����̃A�j���[�V���������擾
	const Animation& GetPlayAnim(void) const;

private:
	// �A�j���[�V�����̃J�E���g
	int animCount_;

	// �A�j���[�V�������郂�f���̃n���h��ID
	int modelId_;

	// ��ޕʂ̃A�j���[�V�����f�[�^
	std::map<int, Animation> animations_;

	// �Đ����̃A�j���[�V����
	int playType_;
	Animation playAnim_;

	// �A�j���[�V���������[�v���邩���Ȃ���
	bool isLoop_;

	// �A�j���[�V�����ǉ��̋��ʏ���
	void Add(int type, float speed, Animation& animation);

};
