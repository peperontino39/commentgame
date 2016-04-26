#pragma once
#include "../Object/MoveObject.h"
#include "Property/PropertySystem.h"

class Player : public MoveObject
{
public:
	Player(Vec2f _pos, Vec2f _size);
	~Player();
	void draw() override;
	void update() override;

private:

	


};

