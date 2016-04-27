#pragma once
#include "../Block.h"

class NormalBlock : public BlockBase
{
public:
	NormalBlock(Vec2f _pos,Vec2f);
	~NormalBlock();
	void update() override;
	void draw() override;

private:

};
