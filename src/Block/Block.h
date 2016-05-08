#pragma once

#include "../AppEnv.h"
#include "../Object/MoveObject.h"

enum BlockType {
	NON,
	NORMAL,
};


class BlockBase : public MoveObject
{
public:
	BlockBase(Vec2f _pos, Vec2f _size) :
		MoveObject(_pos, _size) 
	{
		up_block = true;
		down_block = true;
		left_block = true;
		right_block = true;
	}
	virtual Vec2f collision(Vec2f,Vec2f, Vec2f);
	virtual void update() override;
	virtual void draw() override;
	Vec2f vec;
	bool up_block;
	bool down_block;
	bool left_block;
	bool right_block;
	virtual bool is_Object() = 0;
	Vec2f getPos();

};