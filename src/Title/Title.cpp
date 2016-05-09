#include "Title.h"

Title::Title()
{
	//�X�^�[�g�{�^���̏����l���
	sButton = Vec2f(-100, -100);
	//�X�^�[�g�{�^���̏I���l���
	sButtonEnd = Vec2f(200, 100);

	//�^�C�g�����S�̕`�揉���l
	TitleRogo = Vec2f(-400, 200);
	//�^�C�g�����S�̕`��I���l
	TitleRogoEnd = Vec2f(800, 200);

	//�X�C�b�`���̏����l
	titleSwitch = 1;

	//���ꂼ��̃V�[���ɐ؂�ւ��邽�߂�if��
	gameShift = false;
	stageSelectShift = false;
	fatalShift = false;
}

void Title::update()
{
	//���̂Ƃ���g�p���Ȃ��}�E�X���
	//mousePos = env.mousePosition();
	//std::cout << mousePos << std::endl;

	if (env.isPushKey(GLFW_KEY_DOWN))
	{
		//���L�[�̏���������Ƃ���
		//���L�̃P�[�X���ł̏����l�𑝂₵�ē������B

		titleSwitch += 1;
		if (titleSwitch > 3)
		{
			titleSwitch = 1;
		}
	}
	else if (env.isPushKey(GLFW_KEY_UP))
	{
		//���L�[�̉����������Ƃ���
		//���L�̃P�[�X���ł̏����l�����炵�ē������B
		titleSwitch -= 1;
		if (titleSwitch < 1)
		{
			titleSwitch = 3;
		}
	}
}

void Title::draw()
{
	switch (titleSwitch)

	{
	default:
		break;

	case GAMEFLAG:
		//�Q�[���{�҂Ɉڍs���邽�߂̃P�[�X��
		gameShift = true;

		if (gameShift == true)
		{
			stageSelectShift = false;
			fatalShift = false;
		}

		drawFillBox(sButton.x(), sButton.y(), sButtonEnd.x(), sButtonEnd.y(), Color::red);

		break;

	case STAGESLECT:
		//�X�e�[�W�Z���N�g�Ɉڍs���邽�߂̃P�[�X��
		stageSelectShift = true;

		if (stageSelectShift == true)
		{
			gameShift = false;
			fatalShift = false;
		}

		drawFillBox(sButton.x(), sButton.y(), sButtonEnd.x(), sButtonEnd.y(), Color::white);
		break;

	case FATAL:
		//�Q�[�����I������Ƃ��Ɏg�p����P�[�X��
		fatalShift = true;
		
		if (fatalShift == true)
		{
			stageSelectShift = false;
			gameShift = false;
		}

		drawFillBox(sButton.x(), sButton.y(), sButtonEnd.x(), sButtonEnd.y(), Color::blue);

		break;
	}

	drawFillBox(TitleRogo.x(),TitleRogo.y(),TitleRogoEnd.x(),TitleRogoEnd.y(), Color::white);
}

void Title::shift()
{
	if (gameShift == true && env.isPullKey(GLFW_KEY_ENTER))
	{
		//gameShift��true�ɂȂ������ŃG���^�[�L�[���������Ƃ���
		//�Q�[���{�҂ɃV�t�g����B
		Scene::create<GameMain>(new GameMain());
	}

	if (stageSelectShift == true && env.isPullKey(GLFW_KEY_ENTER))
	{
		//stageSelectShift��true�̎��ŃG���^�[�L�[���������Ƃ���
		//�X�e�[�W�Z���N�g�ɃV�[����؂�ւ���B
		Scene::create<StageSelect>(new StageSelect());
	}

	if (fatalShift == true && env.isPullKey(GLFW_KEY_ENTER))
	{
		//�Q�[���𗎂Ƃ�
	}
}

