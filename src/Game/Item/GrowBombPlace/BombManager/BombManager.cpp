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

	block_size = size;
}

void BombManager::Setup()
{

}

void BombManager::update() {

	createBomb();
	deleteBomb();

	for (auto& grow_bomb_place : grow_bomb_places)
	{
		grow_bomb_place.update();
	}

	for (auto bomb = bombs.begin(); bomb != bombs.end(); ++bomb)
	{
		if (bomb->getIsPlayerHave() == true)
			bomb->setPos(Vec2f(GetPlayer->getPos().x(), GetPlayer->getPos().y() + GetPlayer->getSize().y()));

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
		if (grow_bomb_place->getIsHereBomb() != false)
			continue;
		if (grow_bomb_place->getRespawnTime() > 0)
			continue;

		bombs.emplace_back(Bomb(grow_bomb_place->createBomb(), block_size, Vec2f::Zero()));
		grow_bomb_place->setIsHereBomb(true);
	}
}

void BombManager::deleteBomb() {

	for (auto bomb = bombs.begin(); bomb != bombs.end(); ++bomb)
	{
		if (bomb->getIsEnd() != true)
			continue;

		bombs.erase(bomb);
	}
}

void BombManager::catchBomb() {

	for (auto bomb = bombs.begin(); bomb != bombs.end(); ++bomb)
	{
		if (bomb->getIsExplosion() != false)
			continue;

		if (!collision_BlockToBlcok(GetPlayer->getPos(), GetPlayer->getSize(), bomb->pos_, bomb->size_))
			continue;

		bomb->setIsPlayerHave(true);
		bomb->setIsCountdown(true);

		if (bomb->getIsRespawnBomb() != false)
			return;

		bomb->setIsRespawnBomb(false);

		for (auto grow_bomb_place = grow_bomb_places.begin(); grow_bomb_place != grow_bomb_places.end(); ++grow_bomb_place)
		{
			if (!collision_BlockToBlcok(bomb->getPos(), bomb->getPos(), grow_bomb_place->getPos(), grow_bomb_place->getSize()))
				continue;

			grow_bomb_place->setIsHereBomb(false);
			grow_bomb_place->respawnTime();
		}
	}
}
