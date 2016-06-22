#include "BowManager.h"


BowManager::BowManager() :
	max_arrow_draw_num(10)
{


}

BowManager::~BowManager() {


}

void BowManager::deleteitem() {

	bows.clear();
	arrows.clear();
}

void BowManager::setup(Vec2f pos, Vec2f size) {

	bows.emplace_back(pos, size);
}

void BowManager::update() {

	for (auto& bow : bows)
	{
		//プレイヤーが弓を持っているときにプレイヤーと同じ位置に弓を更新する
		if (bow.getIsPlayerHave() == true) {

			bow.setPos(Vec2f(GetPlayer->getPos().x() + 20.0f, GetPlayer->getPos().y() - 25.0f));
			Direction dir = GetPlayer->direction;
			if (dir == Direction::LEFT)
				bow.setPlayerDirection(-1);
			if (dir == Direction::RIGHT)
				bow.setPlayerDirection(1);
		}

		bow.update();
	}

	createArrow();
	pickUpBow();
	putDownBow();

	//矢の描写数を確認
	deleteArrow();

	for (auto& arrow : arrows)
	{
		arrow.update();
	}
}

void BowManager::draw() {

	for (auto &bow : bows)
	{
		bow.draw();
	}

	for (auto &arrow : arrows)
	{
		arrow.draw();
	}
}

void BowManager::createArrow() {

	if (!env.isPullKey('P'))
		return;

	Vec2f arrow_vec;
	float rad;

	for (auto bow = bows.begin(); bow != bows.end(); ++bow)
	{
		if ((*bow).getIsPlayerHave() != false) {

			if ((*bow).getBowStatus() != BowStatus::SHOOT)
				return;

			arrow_vec = (*bow).shootTheBow();
			rad = (*bow).getRad();

			break;
		}
		else if (bow != --bows.end())
		{
			continue;
		}

		return;
	}

	arrows.emplace_back(Vec2f(GetPlayer->getPos().x() + 12.0f, GetPlayer->getPos().y() - 18.0f), Vec2f(50.0f, 25.0f), arrow_vec, rad);
	auto end_arrow = --arrows.end();
	(*end_arrow).setVec(arrow_vec);
	Direction dir = GetPlayer->direction;
	if (dir == Direction::LEFT)
		(*end_arrow).setPlayerDirection(-1);
	if (dir == Direction::RIGHT)
		(*end_arrow).setPlayerDirection(1);
}

void BowManager::deleteArrow() {

	if (arrows.size() <= 10)
		return;

	auto first_arrow = arrows.begin();

	arrows.erase(first_arrow);
}

void BowManager::pickUpBow() {

	if (!env.isPushKey(GLFW_KEY_ENTER))
		return;

	for (auto bow = bows.begin(); bow != bows.end(); ++bow)
	{
		if (bow->getIsPlayerHave() != false)
			return;

		if (!utl::Colli::rect_Rect(
			GetPlayer->getPos() - GetPlayer->getSize() / 2.0f,
			GetPlayer->getSize(),
			bow->getPos() - bow->getSize() / 2.0f,
			bow->getSize()))
			continue;

		bow->setIsPlayerHave(true);
		bow->setIsDraw(false);
	}
}

void BowManager::putDownBow() {

	if (!env.isPushKey(GLFW_KEY_SPACE))
		return;

	for (auto bow = bows.begin(); bow != bows.end(); ++bow)
	{
		if (bow->getIsPlayerHave() != true)
			continue;

		if (bow->getBowStatus() != BowStatus::NOMAL)
			return;

		bow->putDownTheBow(Vec2f(GetPlayer->getPos().x(), GetPlayer->getPos().y() - GetPlayer->getSize().y() / 4.0f));
		bow->setIsPlayerHave(false);
		return;
	}
}
