#include "ItemManager.h"

ItemManager::ItemManager() {

	std::string item_file_path = "res/stage/stage10"/* + std::to_string(ステージ番号) + */"/item.txt";
	std::ifstream item_file(item_file_path);
	assert(!item_file.fail());

	while (!item_file.eof())
	{
		int item_id;
		Vec2f pos;
		item_file >> item_id;
		item_file >> pos.x();
		item_file >> pos.y();

		std::function<void()> createItem[] = {

			[&]() {

			item_list.emplace_back(new Bomb(pos, Vec2f(100, 100), Vec2f::Zero()));
		},
			[&]() {

			item_list.emplace_back(new Bow(pos, Vec2f(100, 100)));
		}
		};

		createItem[item_id]();

	}
}

ItemManager::~ItemManager() {


}

void ItemManager::update() {



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
