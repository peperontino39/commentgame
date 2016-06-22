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
	catchBomb();
	deleteBomb();
	ReleaseBomb();

	for (auto& grow_bomb_place : grow_bomb_places)
	{
		grow_bomb_place.update();
	}

	for (auto& bomb = bombs.begin(); bomb != bombs.end(); ++bomb)
	{
		if (bomb->getIsPlayerHave() == true)
		{
			if (bomb->getBombStatus() == BombStatus::COUNTDOWN)
			{
				Direction direction = GetPlayer->direction;

				if (direction == Direction::RIGHT)
					bomb->setPos(Vec2f(GetPlayer->getPos().x() + 20.0f, GetPlayer->getPos().y() - 30.0f));
				else if (direction == Direction::LEFT)
					bomb->setPos(Vec2f(GetPlayer->getPos().x() - 20.0f, GetPlayer->getPos().y() - 30.0f));
			}
		}


		bomb->update();
	}
}

void BombManager::draw() {

	for (auto& bomb : bombs)
	{
		bomb.draw();
	}

	for (auto &grow_bomb_place : grow_bomb_places)
	{
		grow_bomb_place.draw();
	}
}

void BombManager::createBomb() {

	for (auto& grow_bomb_place = grow_bomb_places.begin(); grow_bomb_place != grow_bomb_places.end(); ++grow_bomb_place)
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

	for (auto& bomb = bombs.begin(); bomb != bombs.end(); ++bomb)
	{
		if (bomb->getIsEnd() != true)
			continue;

		bombs.erase(bomb);
		return;
	}
}

void BombManager::catchBomb() {

	if (!env.isPushKey(GLFW_KEY_ENTER))
		return;

	for (auto& bomb = bombs.begin(); bomb != bombs.end(); ++bomb)
	{
		if (bomb->getBombStatus() == BombStatus::EXPLOSION ||
			bomb->getBombStatus() == BombStatus::GROWING)
			continue;

		if (!utl::Colli::rect_Rect(GetPlayer->getPos() - GetPlayer->getSize() / 2.0f, GetPlayer->getSize(), bomb->getPos() - bomb->getSize() / 2.0f, bomb->getSize()))
			continue;

		bomb->setIsPlayerHave(true);
		bomb->setBombStatus(BombStatus::CATCHING);
		bomb->setCatchPos(bomb->getPos());

		Direction direction = GetPlayer->direction;

		if (direction == Direction::RIGHT)
			bomb->setCathcedPos(Vec2f(GetPlayer->getPos().x() + 20.0f, GetPlayer->getPos().y() - 30.0f));
		else if (direction == Direction::LEFT)
			bomb->setCathcedPos(Vec2f(GetPlayer->getPos().x() - 20.0f, GetPlayer->getPos().y() - 30.0f));

		for (auto grow_bomb_place = grow_bomb_places.begin(); grow_bomb_place != grow_bomb_places.end(); ++grow_bomb_place)
		{
			if (!utl::Colli::rect_Rect(
				grow_bomb_place->getPos() - grow_bomb_place->getSize() / 2.0f,
				GetPlayer->getSize(),
				bomb->getPos() - bomb->getSize() / 2.0f,
				bomb->getSize()))
				continue;

			grow_bomb_place->setIsHereBomb(false);
			grow_bomb_place->respawnTime();
		}

		return;
	}
}

void BombManager::ReleaseBomb()
{
	if (!env.isPushKey('P'))
		return;

	for (auto &bomb = bombs.begin(); bomb != bombs.end(); ++bomb)
	{
		if (bomb->getIsPlayerHave() != true)
			continue;
		if (bomb->getBombStatus() != BombStatus::COUNTDOWN)
			continue;

		bomb->setIsPlayerHave(false);
		Direction dir = GetPlayer->direction;

		if (GetPlayer->getVec().x() != 0.0f)
		{
			if (dir == Direction::LEFT)
				bomb->setBVec(Vec2f(-2.0f, 5.0f));
			if (dir == Direction::RIGHT)
				bomb->setBVec(Vec2f(2.0f, 5.0f));
		}

		return;
	}
}
