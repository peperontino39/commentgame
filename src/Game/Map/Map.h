#pragma once
#include "../Block/Block.h"
#include "../Block/NormaBlock/NormalBlock.h"
#include "../Block/NormaBlock/WhiteBlock/WhiteBlock.h"
#include "../Block/NormaBlock/BlackBlock/BlackBlock.h"
#include "../Block/NormaBlock/Grass/Grass.h"
#include "../Block/NormaBlock/Sand/Sand.h"
#include "../Block/NormaBlock/Needle/Needle.h"
#include "../Block/NormaBlock/Lift/Lift.h"
#include "../Block/NormaBlock/Switch/Switch.h"
#include "../Block/BombBlock/BombBlock.h"
#include "../Block/NormaBlock/MoveBlock/MoveBlock.h"
#include "../Block/NormaBlock/Magma/Magma.h"
#include "../Block/NormaBlock/Dummy/Dummy.h"
#include "../Block/NormaBlock/Renga/Renga.h"
#include "../Block/NormaBlock/Lcicle/Lcicle.h"

#include <vector>
#include "../Taxture/Taxtures.h"

class Map
{
public:
	Map();
	~Map();
	void update();
	void draw(Vec2f);
	void Load(int);
	Vec2f collision(Vec2f, Vec2f, Vec2f);
	void breakBlock(Vec2f);
	void push(Vec2f, Vec2f, Vec2f);

private:
	Vec2i sell(Vec2f);

	Vec2f block_size;
	std::vector<std::vector<std::shared_ptr<BlockBase>>> block;
	std::vector<std::shared_ptr<BlockBase>> move_block;

	Vec2i sellBigin(Vec2i, Vec2i);
	Vec2i sellEnd(Vec2i, Vec2i);
	Vec2i drawSell;
};

