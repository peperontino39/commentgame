#include "Map.h"

float absmax(float a, float b) {
	if (std::abs(a) > std::abs(b))
		return a;
	return b;
}

Map::Map()
{
}

Map::~Map()
{
	
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
		std::vector<std::shared_ptr<BlockBase>> _block;
		for (int x = 0; x < _height; x++)
		{
			int _block_type;
			file >> _block_type;

			switch (_block_type)
			{
			case  BlockType::NORMAL:
				_block.push_back(std::make_shared<NormalBlock>(
					NormalBlock(Vec2f(x * block_size.x(), -y*block_size.y()),
						block_size)));
				break;
			default:
				break;
			}

		}
		block.push_back(_block);
		
		_block.clear();
	}

}

Vec2f Map::collision(Vec2f _pos, Vec2f _size, Vec2f _vec)
{
	Vec2f sinking = Vec2f::Zero();
	Vec2f a;
	for (auto& y : block)
	{
		for (auto& x : y)
		{
			a = x->collision(_pos, _size, _vec);
			sinking.x() = absmax(sinking.x(), a.x());
			sinking.y() = absmax(sinking.y(), a.y());
		}
	}
	return sinking;
}


Vec2i Map::sell(Vec2f _pos)
{
	return Vec2i(_pos.x()/ block_size.x(),-_pos.y()/block_size.y());
}
