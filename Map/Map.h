#pragma once
#include "../Block/Block.h"
#include "../Block/NormaBlock/NormalBlock.h"
#include <vector>

class Map
{
public:
	Map();
	~Map();
	void update();
	void draw();
	void Load(int);
	
private:
	Vec2i sell(Vec2f);

	Vec2f block_size;
	std::vector<std::vector<BlockBase*>> block;
};

