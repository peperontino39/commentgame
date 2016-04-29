#include "GameMain.h"
#include "../Title/Title.h"

GameMain::GameMain()
{
	P_Manager.createPlayer("res/stage/stage1/Player.txt");
	map.Load(1);
}

void GameMain::update()
{
	camera_pos = GetPlayer->getPos();
	GetPlayer->update();
	map.update();
	ui.update();
	enemyholder.update();
	comment.update();
}

void GameMain::draw()
{
	glPushMatrix();
	glTranslated(-camera_pos.x(), -camera_pos.y(), 0);
	map.draw();
	ui.draw();
	enemyholder.draw();
	comment.draw();
	drawFillBox(0, 0, 100, 100, Color::blue);
	GetPlayer->draw();
	glPopMatrix();
}

void GameMain::shift()
{
	if (env.isPushButton(Mouse::LEFT)) {
		Scene::create<Title>(new Title());
	}
}
