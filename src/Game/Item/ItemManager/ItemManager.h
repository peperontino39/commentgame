#pragma once
#include "../Bomb/Bomb.h"
#include "../Bow/Bow.h"
#include "../../Taxture/Taxtures.h"
#include "../../Player/PlayerManager.h"

#define I_Manager ItemManager::get()
#define GetItemList I_Manager.getItemList()

class ItemManager
{
public:

	ItemManager();
	~ItemManager();

	void update();
	void draw();

	static ItemManager& get()
	{
		ItemManager item_manager;

		return item_manager;
	}

	std::list<ItemBase*> getItemList()
	{
		return item_list;
	}

private:

	void updateItem();
	void PickUpItem();
	void IsItemDelete();
	void useBomb();
	

	std::list<ItemBase*> item_list;
	std::shared_ptr<Player> player;
};