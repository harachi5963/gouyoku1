#pragma once

#include <vector>

#include "../SceneBase.h"

class Camera;
class Stage;
class ActorBase;


class GameScene : public SceneBase
{
public:
	GameScene(void);				// �R���X�g���N�^
	~GameScene(void) override;		// �f�X�g���N�^

	void Init(void)		override;	// ������
	void Load(void)		override;	// �ǂݍ���
	void LoadEnd(void)	override;	// �ǂݍ��݌�̏���
	void Update(void)	override;	// �X�V
	void Draw(void)		override;	// �`��
	void Release(void)	override;	// ���

private:
	void isDoorCollision(void);

	// �h�A�J����
	void isDoorOpen(void);

private:
	// �J����
	Camera* camera_;

	// �X�e�[�W
	Stage* stage_;

	// �S�ẴA�N�^�[
	std::vector<ActorBase*> allActor_;

	// �Փ˔���(��)
	void FieldCollision(ActorBase* actor);

	// �Փ˔���(��)
	void WallCollision(ActorBase* actor);
};
