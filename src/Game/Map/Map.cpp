#include "Map.h"

float absmax(float a, float b) {
	if (std::abs(a) > std::abs(b))
		return a;
	return b;
}

Map::Map()
{
	Textures::set("whiteblock", "res/Texture/Block/whitelock.png");
	Textures::set("blackblock", "res/Texture/Block/blacklock.png");
	Textures::set("grass", "res/Texture/Block/grass.png");
	Textures::set("sand", "res/Texture/Block/sand.png");
	Textures::set("thorn", "res/Texture/Block/thorn.png");
	Textures::set("switch", "res/Texture/Block/switch.png");
	Textures::set("rifuto", "res/Texture/Block/rift.png");
	Textures::set("bomb", "res/Texture/Block/bomb.png");
	Textures::set("magma", "res/Texture/Block/magma.png");
	Textures::set("dummy", "res/Texture/Block/dummy.png");
	Textures::set("renga", "res/Texture/Block/renga.png");
	Textures::set("lcicle", "res/Texture/Block/icicle.png");

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
	for (auto& it : move_block)
	{
		it->update();
	}
	for (auto& it : move_block)
	{
		it->addpos(this->collision(it->getPos(), it->getSize(), it->getVec()));

	}

}

void Map::draw(Vec2f _pos)
{
	Vec2i _sell = sell(_pos);
	Vec2i _bigin = sellBigin(_sell, -drawSell);
	Vec2i _end = sellEnd(_sell, drawSell);

	for (int y = _bigin.y(); y <= _end.y(); y++)
	{
		for (int x = _bigin.x(); x <= _end.x(); x++)
		{
			block[y][x]->draw();
		}
	}
	for (auto it : move_block)
	{
		it->draw();
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
	file >> _height;
	file >> _width;

	Vec2f _block_pos;
	int _block_type;
	int _floor_size;
	Vec2i _move = Vec2i::Zero();

	for (int y = 0; y < _width; y++)
	{
		std::vector<std::shared_ptr<BlockBase>> _block;
		for (int x = 0; x < _height; x++)
		{
			file >> _block_type;
			_block_pos = Vec2f(x * block_size.x(), -y*block_size.y());
			switch (_block_type)
			{
			case  BlockType::WHITEBLOCK:
				_block.push_back(std::make_shared<WhiteBlock>(
					WhiteBlock(_block_pos,
						block_size)));
				break;
			case BLACKBLOCK:
				_block.push_back(std::make_shared<BlackBlock>(
					BlackBlock(_block_pos,
						block_size)));
				break;
			case GRASS:
				_block.push_back(std::make_shared<Grass>(
					Grass(_block_pos,
						block_size)));
				break;
			case SAND:
				_block.push_back(std::make_shared<Sand>(
					Sand(_block_pos,
						block_size)));

				break;
			case THORN:
				_block.push_back(std::make_shared<Needle>(
					Needle(_block_pos,
						block_size)));
				break;
			case SWITCH:
				_block.push_back(std::make_shared<Switch>(
					Switch(_block_pos,
						block_size)));
				break;
			case RIFUTO:

				file >>  _move.x() >> _move.y() >> _floor_size;

				move_block.push_back(std::make_shared<Lift>(
					Lift(_block_pos,
						block_size, _floor_size, _move)));
				_block.push_back(std::make_shared<BlockBase>(BlockBase(_block_pos, block_size)));
				break;

			case MOVEBLOCK:
				move_block.push_back(std::make_shared<MoveBlock>(
					MoveBlock(_block_pos,
						block_size)));
				_block.push_back(std::make_shared<BlockBase>(BlockBase(_block_pos, block_size)));
				break;
			case BlockType::MAGMA:
				_block.push_back(std::make_shared<Magma>(
					Magma(_block_pos,
						block_size)));
				break;
			case BlockType::RENGA:
				_block.push_back(std::make_shared<Renga>(
					Renga(_block_pos,
						block_size)));
				break;
			case BlockType::DUMMY:
				_block.push_back(std::make_shared<Dummy>(
					Dummy(_block_pos,
						block_size)));
				break;
			case BlockType::LCICLE:
				_block.push_back(std::make_shared<Lcicle>(
					Lcicle(_block_pos,
						block_size)));
				break;


			default:
				_block.push_back(std::make_shared<BlockBase>(BlockBase(_block_pos, block_size)));
				break;
			}

		}
		block.push_back(_block);
		_block.clear();
	}
	drawSell = Vec2i(WIDTH / block_size.x(), HEIGHT / block_size.y() + 1) / 2;
}

Vec2f Map::collision(Vec2f _pos, Vec2f _size, Vec2f _vec)
{
	Vec2f sinking = Vec2f::Zero();
	Vec2f a;
	Vec2i _sell = sell(_pos);
	Vec2i _bigin = sellBigin(_sell, Vec2i(-1, -1));
	Vec2i _end = sellEnd(_sell, Vec2i(+1, +1));

	for (int y = _bigin.y(); y <= _end.y(); y++)
	{
		for (int x = _bigin.x(); x <= _end.x(); x++)
		{
			a = block[y][x]->collision(_pos, _size, _vec);
			sinking.x() = absmax(sinking.x(), a.x());
			sinking.y() = absmax(sinking.y(), a.y());
		}
	}


	for (auto& it : move_block)
	{

		/*if (_pos.x() == Vec2f(it->pos_).x() &&
			_pos.y() == Vec2f(it->pos_).y())
			continue;
*/
		a = it->collision(_pos, _size, _vec);
		sinking.x() = absmax(sinking.x(), a.x());
		sinking.y() = absmax(sinking.y(), a.y());
	}
	return sinking;
}

void Map::breakBlock(Vec2f _pos)
{
	drawPoint(_pos.x(), _pos.y(), 10, Color::white);

	Vec2i _sell = sell(_pos);
	Vec2f _block_pos;
	Vec2i _bigin = sellBigin(_sell, Vec2i(-1, -1));
	Vec2i _end = sellEnd(_sell, Vec2i(+1, +1));

	for (int y = _bigin.y(); y <= _end.y(); y++)
	{
		for (int x = _bigin.x(); x <= _end.x(); x++)
		{
			//‰ó‚¹‚é‚©”Û‚©
			if (block[y][x]->isBreak())
			{
				_block_pos = Vec2f(x * block_size.x(), -y*block_size.y());
					if (block[y][x] == nullptr)
						block[y][x] = std::make_shared<BlockBase>(BlockBase(_block_pos, block_size));
				
			}
		}
	}



}

void Map::push(Vec2f _pos, Vec2f _size, Vec2f _vec)
{
	for (auto& it : move_block)
	{
		it->push(_pos, _size, _vec);
	}

}


Vec2i Map::sell(Vec2f _pos)
{
	return Vec2i((_pos.x() - block_size.x() / 2) / block_size.x() + 1,
		(-_pos.y() - block_size.y() / 2) / block_size.y() + 1);

}

Vec2i Map::sellBigin(Vec2i _sell, Vec2i _add)
{
	return Vec2i(
		std::max(0, _sell.x() + _add.x()),
		std::max(0, _sell.y() + _add.y())
		);
}

Vec2i Map::sellEnd(Vec2i _sell, Vec2i _add)
{
	return Vec2i(
		std::min(static_cast<int>(block[0].size() - 1), _sell.x() + _add.x()),
		std::min(static_cast<int>(block.size() - 1), _sell.y() + _add.y())
		);
}
