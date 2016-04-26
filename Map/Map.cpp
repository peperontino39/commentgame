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
			std::cout << x->getPos() << std::endl;
		}
	}
}

void Map::Load(int _stage_num)
{
	std::ifstream file("res/stage/stage" +
		std::to_string(_stage_num) +
		".txt");
	//std::ifstream file("res/stage/stage1.txt");
	assert(file);
	Vec2f _block_size;
	{
		std::ifstream blocksize_file("res/stage/stage" +
			std::to_string(_stage_num) +
			"_blocksize.txt");
		assert(blocksize_file);
		blocksize_file >> _block_size.x();
		blocksize_file >> _block_size.y();
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
					NormalBlock(Vec2f(x * _block_size.x(), -y*_block_size.y()),
						_block_size));
				break;
			default:
				break;
			}

		}
		block.push_back(_block);
		/*for (auto& it : _block)
		{
			delete it;
		}*/
		_block.clear();
	}

}
