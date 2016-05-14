#pragma once
#include "../NormalBlock.h"

class MoveBlock : public NormalBlock
{
public:
	MoveBlock::MoveBlock(Vec2f, Vec2f);
	Vec2f collision(Vec2f, Vec2f, Vec2f) override;
	void update() override;
	void draw() override;

	void push(Vec2f, Vec2f, Vec2f) override;
	void addpos(Vec2f) override;



public:
	
};
