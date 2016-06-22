#pragma once
#include "../Bomb/Bomb.h"
#include "../GrowBombPlace.h"
#include "../../../Player/PlayerManager.h"
#include "../../../Share/Utility/Utility.h"



class BombManager
{
public:

	BombManager();
	~BombManager();

	void deleteitem();

	void createGrowBombPlace(Vec2f pos, Vec2f size);
	std::list<Bomb>& getBombs() { return bombs; }

	void Setup();
	void update();
	void draw();

private:

	void createBomb();
	void deleteBomb();
	void catchBomb();
	void ReleaseBomb();

	std::list<Bomb> bombs;
	std::list<GrowBombPlace> grow_bomb_places;
	Vec2f block_size;

};