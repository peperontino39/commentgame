#pragma once
#include "../Bomb/Bomb.h"
#include "../Bow/Bow.h"


class ItemManager
{
public:

	ItemManager();
	~ItemManager();

	void update();
	void draw();

private:

	std::list<ItemBase*> item_list;
};