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
		is_Object = false;
	}
	virtual Vec2f collision(Vec2f,Vec2f, Vec2f);
	virtual void update() override;
	virtual void draw() override;
	Vec2f vec;
	bool up_block;
	bool down_block;
	bool left_block;
	bool rightblock;
	bool is_Object;
	Vec2f getPos();

};