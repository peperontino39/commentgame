#pragma once
#include "../Object/MoveObject.h"
#include "../Share/Property/PropertySystem.h"

class Player : public MoveObject
{
public:
	Player(Vec2f _pos, Vec2f _size);
	~Player();
	void draw() override;
	void update() override;

	void setPos(Vec2f _pos);
	void setSize(Vec2f _size);
	Vec2f getPos();
	Vec2f getSize();

private:

	void move();

};

