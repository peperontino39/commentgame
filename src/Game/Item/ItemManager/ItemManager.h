#pragma once
#include "../Bow/BowManager/BowManager.h"
#include "../GrowBombPlace/BombManager/BombManager.h"

#define IManger ItemManager::get()


class ItemManager
{
public:

	ItemManager();
	~ItemManager();


	void setup();
	void update();
	void draw();

	static ItemManager& get()
	{
		static ItemManager item_manager;

		return item_manager;
	}

private:

	
	Vec2f block_size;
	BombManager bomb_manager;
	BowManager bow_manager;

};