#pragma once

#include "../AppEnv.h"
#include "../Object/MoveObject.h"

class BlockBase : public MoveObject
{
public:
	BlockBase(Vec2f _pos, Vec2f _size) :
		MoveObject(_pos, _size) 
	{

	}
	void update() override;
	void draw() override;

};