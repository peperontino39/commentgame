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

	pickUpBow();
	putDownBow();

	for (auto bow : bows)
	{
		//プレイヤーが弓を持っているときにプレイヤーと同じ位置に弓を更新する
		if (bow.is_player_have == true) {

			bow.pos_ = GetPlayer->getPos();
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
		if (bow.is_draw != true)
			continue;

		bow.update();
	}

	for (auto arrow : arrows)
	{
		arrow.update();
	}
}

void BowManager::createArrow() {

	if (!env.isPullKey(GLFW_KEY_ENTER))
		return;

	Vec2f arrow_vec;

	for (auto bow : bows)
	{
		if (bow.is_player_have != false) {

			arrow_vec = bow.shootTheBow();

			break;
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

	if (!env.isPushKey(GLFW_KEY_SPACE))
		return;

	for (auto bow = bows.begin(); bow != bows.end(); ++bow)
	{
		if (bow->is_player_have != false)
			return;

		if (collision_BlockToBlcok(GetPlayer->getPos(), GetPlayer->getSize(), bow->pos_, bow->size_))
			continue;

		bow->is_player_have = true;
		bow->is_draw = false;
	}
}

void BowManager::putDownBow() {

	if (!env.isPushKey(GLFW_KEY_ESCAPE))
		return;

	for (auto bow = bows.begin(); bow != bows.end(); ++bow)
	{
		if (bow->is_player_have != true)
			continue;

		bow->putDownTheBow(GetPlayer->getPos());
	}
}
