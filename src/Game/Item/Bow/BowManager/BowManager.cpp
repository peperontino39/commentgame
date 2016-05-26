#include "BowManager.h"


BowManager::BowManager() :
	max_arrow_draw_num(10) {


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

	for (auto bow : bows)
	{
		//プレイヤーが弓を持っているときにプレイヤーと同じ位置に弓を更新する
		if (bow.getIsPlayerHave() == true) {

			bow.setPos(GetPlayer->getPos());
		}

		bow.update();
	}

	//矢の描写数を確認
	deleteArrow();

	for (auto arrow : arrows)
	{
		arrow.update();
	}
}

void BowManager::draw() {

	for (auto bow : bows)
	{
		if (bow.getIsDraw() != true)
			continue;

		bow.update();
	}

	for (auto arrow : arrows)
	{
		arrow.update();
	}
}

void BowManager::createArrow() {

	Vec2f arrow_vec;

	for (auto bow = bows.begin(); bow != bows.end(); ++bow)
	{
		if ((*bow).getIsPlayerHave() != false) {

			arrow_vec = (*bow).shootTheBow();

			break;
		}
		else if(bow != --bows.end())
		{
			continue;
		}

		return;
	}

	arrows.emplace_back(GetPlayer->getPos(), Vec2f(50.0f, 25.0f), arrow_vec);
}

void BowManager::deleteArrow() {

	if (arrows.size() <= 10)
		return;

	auto first_arrow = arrows.begin();

	arrows.erase(first_arrow);
}

void BowManager::pickUpBow() {

	for (auto bow = bows.begin(); bow != bows.end(); ++bow)
	{
		if (bow->getIsPlayerHave() != false)
			return;

		if (collision_BlockToBlcok(GetPlayer->getPos(), GetPlayer->getSize(), bow->pos_, bow->size_))
			continue;

		bow->setIsPlayerHave(true);
		bow->setIsDraw(false);
	}
}

void BowManager::putDownBow() {

	for (auto bow = bows.begin(); bow != bows.end(); ++bow)
	{
		if (bow->getIsPlayerHave() != true)
			continue;

		bow->putDownTheBow(GetPlayer->getPos());
	}
}
