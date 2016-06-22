#include "GameMain.h"
#include "../Title/Title.h"

GameMain::GameMain()
{
	int _stage_num = 11; //今はサンプルステージを読み込み
	GameInfo::get().stage_num = _stage_num;
	P_Manager.createPlayer("res/stage/stage" + std::to_string(_stage_num) + "/Player.txt");

	map.Load(_stage_num);
	enemyholder.load(_stage_num);
	CommentWindow::pos = Vec2f(-WIDTH / 2, -HEIGHT / 2);
	CommentWindow::size = Vec2f(WIDTH, HEIGHT);
	IManger.setup();

	bgload(_stage_num);

}

GameMain::~GameMain()
{
	Easing::Clear();
	bgm.stop();
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

	enemycollision();
	itemcollision();

	GetPlayer->addpos(map.collision(GetPlayer->getPos(), GetPlayer->getSize(), GetPlayer->vec));
	camera_pos = GetPlayer->getPos();

	if (env.isPushButton(Mouse::RIGHT)) {
		map.breakBlock(GetPlayer->getPos());
	}

	map.checkPoint(GetPlayer->getPos(), GetPlayer->getSize());
}

void GameMain::draw()
{
	drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, 0, 0, 1024, 512, bg);

	glPushMatrix();
	glScaled(2, 2, 2);
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

void GameMain::enemycollision()
{

	for (auto& it : enemyholder.enemy_list()) {
		it->addpos(map.collision(it->getPos(), it->getSize(), it->getVec()));
		GetPlayer->setPos(it->ride(GetPlayer->getPos(), GetPlayer->getSize(), GetPlayer->vec));
	}
	//敵のボムが当たった時の当たり判定
	for (auto& it : IManger.getbomb().getBombs())
	{
		if (it.getBombStatus() == BombStatus::EXPLOSION) {

			enemyholder.stan(it.getPos(), it.getExplosionSize());
		}
	}
}

void GameMain::itemcollision()
{
	for (auto& it : IManger.getbomb().getBombs())
	{
		if (it.getBombStatus() == BombStatus::COUNTDOWN) {
			it.addpos(map.collision(it.getPos(), it.getSize(), it.getBVec()));
		}//it.addpos(Vec2f())
	}

}

void GameMain::bgload(int stage_num)
{


	Textures::set("stage1", "res/Texture/background/GreenField.png");
	Textures::set("stage2", "res/Texture/background/Cave.png");
	Textures::set("stage3", "res/Texture/background/LastDungeon.png");
	Medias::set("stage1", "res/Media/BGM/stage1/GreenField.wav");
	Medias::set("stage2", "res/Media/BGM/stage2/Cave.wav");
	Medias::set("stage3", "res/Media/BGM/stage3/BossField.wav");

	bg = Textures::get("stage" + std::to_string(1));
	bgm = Medias::get("stage" + std::to_string(1));
	bgm.looping(1);
	bgm.play();
}
