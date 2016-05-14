#include "GameMain.h"
#include "../Title/Title.h"

GameMain::GameMain()
{
	int _stage_num = 11;
	P_Manager.createPlayer("res/stage/stage" + std::to_string(_stage_num) + "/Player.txt");
	map.Load(_stage_num);
	CommentWindow::pos = Vec2f(-WIDTH / 2, -HEIGHT / 2);
	CommentWindow::size = Vec2f(WIDTH, HEIGHT);
	IManger.setup();

}

GameMain::~GameMain()
{
	Easing::Clear();
}

void GameMain::update()
{
	ui.update();
	enemyholder.update();
	GetPlayer->update();
	IManger.update();
	map.push(GetPlayer->getPos(), GetPlayer->getSize(), GetPlayer->vec);
	map.update();
	
	comment.update();

	
	GetPlayer->addpos(map.collision(GetPlayer->getPos(), GetPlayer->getSize(), GetPlayer->vec));
	camera_pos = GetPlayer->getPos();

	if (env.isPushButton(Mouse::RIGHT)) {
		map.breakBlock(GetPlayer->getPos());
	}

}

void GameMain::draw()
{
	glPushMatrix();
	glTranslated(-camera_pos.x(), -camera_pos.y(), 0);
	map.draw(camera_pos);
	enemyholder.draw();
	GetPlayer->draw();
	IManger.draw();

	glPopMatrix();

	comment.draw();
	ui.draw();
}

void GameMain::shift()
{
	if (env.isPushButton(Mouse::LEFT)) {
		Scene::create<Title>(new Title());
	}
}
