#pragma once
#include "../SceneBase/CreateScene.h"
#include "../StageSelect/StageSelect.h"
#include "../GameMain/GameMain.h"

//���̖��̒ʂ�
//switch���Ŏg�p�����
enum SwitchNumber
{
	GAMEFLAG = 1,
	STAGESLECT = 2,
	FATAL = 3,
};

class Title : public SceneBase
{
public:
	Title();
	void update() override;
	void draw() override;
	void shift() override;

private:
	//���̂Ƃ���͎g�p���Ȃ��}�E�X�|�C���^
	//Vec2f mousePos;

	//�X�^�[�g�{�^����`�悷�邽�߂̕ϐ�
	Vec2f sButton;
	Vec2f sButtonEnd;

	//�^�C�g�����S���
	Vec2f TitleRogo;
	Vec2f TitleRogoEnd;
	
	//swicth���𓮂������߂̏����l
	int titleSwitch;

	//�V�[����؂�ւ���ׂ̕ϐ�
	bool gameShift;
	bool stageSelectShift;
	bool fatalShift;
};