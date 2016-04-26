#pragma once
#include "../Block/Block.h"
#include <vector>

class Map
{
public:
	Map();
	~Map();
	void update();
	void draw();

	
private:
	
	std::vector<std::vector<std::shared_ptr<BlockBase>>> block;
};

