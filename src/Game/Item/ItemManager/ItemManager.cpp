#include "ItemManager.h"

ItemManager::ItemManager() :
	block_size(Vec2f::Zero())
{


}

ItemManager::~ItemManager() {


}

void ItemManager::setup() {

	bomb_manager.deleteitem();
	bow_manager.deleteitem();

	std::string stage_item_file_path = "res/stage/stage10/item.txt";
	std::ifstream stage_item_file(stage_item_file_path);
	assert(!stage_item_file.fail());

	std::string block_size_file_path = "res/stage/stage10/BlockSize.txt";
	std::ifstream block_size_file(block_size_file_path);
	assert(!block_size_file.fail());

	block_size_file >> block_size.x();
	block_size_file >> block_size.y();

	int item_id;
	Vec2f item_pos;

	std::function<void()> createItem[] =
	{
		[&] {

		bomb_manager.setup(item_pos, block_size);
	},
		[&] {

		bow_manager.setup(item_pos, block_size);
	}
	};

	while (!stage_item_file.eof())
	{
		stage_item_file >> item_id;
		stage_item_file >> item_pos.x();
		stage_item_file >> item_pos.y();

		createItem[item_id]();
	}

}

void ItemManager::update() {


	bomb_manager.update();
	bow_manager.update();
}

void ItemManager::draw() {

	bomb_manager.draw();
	bow_manager.draw();
}
