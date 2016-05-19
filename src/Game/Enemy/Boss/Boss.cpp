#include "Boss.h"

Boss::Boss(Vec2f _pos, Vec2f _size) :
	Enemy(_pos, _size)
{

}

Boss::~Boss()
{
}

void Boss::update()
{
	move();
	fall();
	vector();
}

void Boss::draw()
{

	drawBox(pos.x(), pos.y(), size.x(), size.y(), 5, Color::white, 0, Vec2f(1, 1), Vec2f(size.x() / 2, size.y() / 2));
}

void Boss::move()
{
	pos.x()++;
}

void Boss::stan(Vec2f item_pos, Vec2f item_size)
{
}

bool Boss::kill(Vec2f player_pos, Vec2f player_size)
{
	if (collisionBox(player_pos, player_size, pos, size)) {

		return true;
	}
	return false;
}

bool Boss::attack(Vec2f player_pos, Vec2f player_size)
{
	return false;
}
