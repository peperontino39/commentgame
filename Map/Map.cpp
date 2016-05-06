#include "Map.h"

Map::Map()
{
}

Map::~Map()
{
	for (auto& y : block)
	{
		for (auto& x : y)
		{
			delete x;
		}
	}
}

void Map::update()
{
	for (auto& y : block)
	{
		for (auto& x : y)
		{
			x->update();
		}
	}
}

void Map::draw()
{
	for (auto& y : block)
	{
		for (auto& x : y)
		{
			x->draw();
		}
	}
}

void Map::Load(int _stage_num)
{
	std::ifstream file("res/stage/stage" +
		std::to_string(_stage_num) +
		"/Map.txt");
	
	assert(file);
	
	{
		std::ifstream blocksize_file("res/stage/stage" +
			std::to_string(_stage_num) +
			"/BlockSize.txt");
		assert(blocksize_file);
		blocksize_file >> block_size.x();
		blocksize_file >> block_size.y();
	}

	int _width;
	int _height;
	file >> _width;
	file >> _height;

	for (int y = 0; y < _width; y++)
	{
		std::vector<BlockBase*> _block;
		for (int x = 0; x < _height; x++)
		{
			int _block_type;
			file >> _block_type;

			switch (_block_type)
			{
			case  BlockType::NORMAL:
				_block.push_back(new
					NormalBlock(Vec2f(x * block_size.x(), -y*block_size.y()),
						block_size));
				break;
			default:
				break;
			}

		}
		block.push_back(_block);
		
		_block.clear();
	}

}

Vec2f Map::collision(Vec2f, Vec2f, Vec2f)
{
	return Vec2f::Zero();
}

Vec2i Map::sell(Vec2f _pos)
{
	return Vec2i(_pos.x()/ block_size.x(),-_pos.y()/block_size.y());
}
