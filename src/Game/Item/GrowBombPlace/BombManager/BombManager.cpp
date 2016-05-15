#include "BombManager.h"

BombManager::BombManager() {


}

BombManager::~BombManager() {


}

void BombManager::deleteitem() {

	bombs.clear();
	grow_bomb_places.clear();
}

void BombManager::createGrowBombPlace(Vec2f pos, Vec2f size) {

	grow_bomb_places.emplace_back(pos, size);
}

void BombManager::setup(Vec2f pos, Vec2f size) {

	grow_bomb_places.emplace_back(GrowBombPlace(pos, size));

	block_size = size;
}

void BombManager::update() {

	createBomb();
	catchBomb();
	deleteBomb();

	for (auto& grow_bomb_place : grow_bomb_places)
	{
		grow_bomb_place.update();
	}

	for (auto bomb = bombs.begin(); bomb != bombs.end(); ++bomb)
	{
		if (bomb->is_player_have == true)
			bomb->pos_ = Vec2f(GetPlayer->getPos().x(), GetPlayer->getPos().y() + GetPlayer->getSize().y());

		bomb->update();
	}
}

void BombManager::draw() {

	for (auto bomb : bombs)
	{
		bomb.draw();
	}
}

void BombManager::createBomb() {

	for (auto grow_bomb_place = grow_bomb_places.begin(); grow_bomb_place != grow_bomb_places.end(); ++grow_bomb_place)
	{
		if ((grow_bomb_place->is_here_bomb != false))
		{
			if ((grow_bomb_place->respawn_time > 0))
			{
				continue;
			}
		}


		bombs.emplace_back(Bomb(grow_bomb_place->createBomb(), block_size, Vec2f::Zero()));
		grow_bomb_place->is_here_bomb = true;
	}
}

void BombManager::deleteBomb() {

	for (auto bomb = bombs.begin(); bomb != bombs.end(); ++bomb)
	{
		if (bomb->is_end != true)
			continue;

		bombs.erase(bomb);
	}
}

void BombManager::catchBomb() {

	if (!env.isPushKey(GLFW_KEY_ENTER))
		return;

	for (auto bomb = bombs.begin(); bomb != bombs.end(); ++bomb)
	{
		if (bomb->is_explosion != false)
			continue;

		if (!collision_BlockToBlcok(GetPlayer->getPos(), GetPlayer->getSize(), bomb->pos_, bomb->size_))
			continue;

		bomb->is_player_have = true;
		bomb->is_countdown = true;

		if (bomb->is_respawn_bomb != false)
			return;

		bomb->is_respawn_bomb = false;

		for (auto grow_bomb_place = grow_bomb_places.begin(); grow_bomb_place != grow_bomb_places.end(); ++grow_bomb_place)
		{
			if (!collision_BlockToBlcok(bomb->pos_, bomb->size_, grow_bomb_place->pos_, grow_bomb_place->size_))
				continue;

			grow_bomb_place->is_here_bomb = false;
			grow_bomb_place->respawnTime();
		}
	}
}
