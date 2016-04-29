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

	}
	virtual Vec2f collision(ObjectBase&, Vec2f vec);
	virtual void update() override;
	virtual void draw() override;
	Vec2f vec;
	bool up_block;
	bool down_block;
	bool left_block;
	bool rightblock;

	Vec2f getPos();

};