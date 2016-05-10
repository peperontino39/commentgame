#include "ItemManager.h"

bool IsHitBlockToBlock(Vec2f pos1, Vec2f size1, Vec2f pos2, Vec2f size2)
{
	return (pos1.x() + size1.x() > pos2.x() &&
		pos1.x() < pos2.x() + size2.x() &&
		pos1.y() + size1.y() > pos2.y() &&
		pos1.y() < pos2.y() + size2.y());
}



ItemManager::ItemManager() {

	//player = std::make_shared<Player>(GetPlayer);

	std::string item_file_path = "res/stage/stage10/item.txt";
	std::ifstream item_file(item_file_path);
	assert(!item_file.fail());

	std::string block_size_file_path = "res/stage/stage10/BlockSize.txt";
	std::ifstream block_size_file(block_size_file_path);
	assert(!block_size_file.fail());

	Vec2f block_size;
	block_size_file >> block_size.x();
	block_size_file >> block_size.y();

	while (!item_file.eof())
	{
		int item_id;
		Vec2f pos;
		item_file >> item_id;
		item_file >> pos.x();
		item_file >> pos.y();

		std::function<void()> createItem[] = {

			[&]() {

			item_list.emplace_back(new Bomb(pos, block_size, Vec2f::Zero()));
		},
			[&]() {

			item_list.emplace_back(new Bow(pos, block_size));
		}
		};

		createItem[item_id]();

	}
}

ItemManager::~ItemManager() {


}

void ItemManager::update() {

	updateItem();
	useBomb();
	PickUpItem();
	IsItemDelete();

	for (auto item : item_list)
	{
		item->update();
	}
}

void ItemManager::draw() {

	for (auto item : item_list)
	{
		if (item->is_draw != true)
			continue;

		item->draw();
	}
}

void ItemManager::updateItem() {

	/*for (std::list<ItemBase*>::iterator item = item_list.begin(); item != item_list.end(); ++item)
	{
		if ((*item)->is_player_have != true)
			continue;

		if ((*item)->id == ItemID::BOW) {
			(*item)->pos_ = player->getPos();
		}

		if ((*item)->id == ItemID::BOMB) {

			(*item)->pos_ = Vec2f(player->getPos().x(), player->getPos().y() + player->getSize().y());
		}
	}*/
}

void ItemManager::PickUpItem() {

	/*for (std::list<ItemBase*>::iterator item = item_list.begin(); item != item_list.end(); ++item)
	{
		if (!IsHitBlockToBlock(player->getPos(), player->getSize(), (*item)->pos_, (*item)->size_))
			continue;
		if ((*item)->is_player_have != false)
			continue;

		if (!env.isPushKey(GLFW_KEY_ENTER))
			continue;

		if ((*item)->id == ItemID::BOW) {

			(*item)->is_player_have = true;
			(*item)->is_draw = false;
		}

		if ((*item)->id == ItemID::BOMB) {

			(*item)->is_draw = false;
			item_list.emplace_back(item);
			std::list<ItemBase*>::iterator player_have_bomb = --item_list.end();

			(*player_have_bomb)->pos_ = Vec2f(player->getPos().x(), player->getPos().y() + player->getSize().y());
			(*player_have_bomb)->is_player_have = true;
			(*player_have_bomb)->is_countdown = true;
		}

		env.flushInput();
	}*/
}

void ItemManager::IsItemDelete()
{
	for (std::list<ItemBase*>::iterator item = item_list.begin(); item != item_list.end(); ++item)
	{
		if ((*item)->is_end != true)
			continue;

		item_list.erase(item);
	}
}

void ItemManager::useBomb() {

	/*for (std::list<ItemBase*>::iterator item = item_list.begin(); item != item_list.end(); ++item)
	{
		if ((*item)->id != ItemID::BOMB)
			continue;
		if ((*item)->is_player_have != true)
			continue;

		if (!env.isPushKey('B'))
			continue;

		Vec2f player_vec = player->vec;

		if (player_vec.x() < -0.5f || player_vec.x() > 0.5f) {

			(*item)->vec = Vec2f(5.0f * (player_vec.x() > 0), 5.0f);
		}
		else
		{
			(*item)->pos_ = player->getPos();
		}

		(*item)->is_player_have = false;
	}*/
}
