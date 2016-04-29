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
	
	std::vector<std::vector<BlockBase*>> block;
};

