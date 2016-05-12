#pragma once
#include "../NormalBlock.h"

class MoveBlock : public NormalBlock
{
public:
	MoveBlock(Vec2f, Vec2f);
	Vec2f collision(Vec2f, Vec2f, Vec2f) override;
	void update() override;


};
