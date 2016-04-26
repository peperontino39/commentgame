#include "GameMain.h"
#include "../Title/Title.h"

GameMain::GameMain()
{
	player = new Player(Vec2f::Zero(), Vec2f(100, 100));
}

void GameMain::update()
{
	player->update();
	map.update();
	ui.update();
	enemyholder.update();
	comment.update();
}

void GameMain::draw()
{
	player->draw();
	map.draw();
	ui.draw();
	enemyholder.draw();
	comment.draw();
	drawFillBox(0, 0, 100, 100, Color::blue);
}

void GameMain::shift()
{
	if (env.isPushButton(Mouse::LEFT)) {
		Scene::create<Title>(new Title());
	}
}
