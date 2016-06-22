#pragma once
#include "../../Object/MoveObject.h"
#include "../../Taxture/Taxtures.h"
class Fire : public MoveObject
{
private:
	Direction direction;
	int count;
	bool active;
public:
	Fire(Vec2f _pos, Vec2f _size,Direction _direction);
	void update();
	void draw();
	bool getActive() {
		return active;
	}
};