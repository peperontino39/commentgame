#include "Skelton.h"

Skelton::Skelton(Vec2f _pos, Vec2f _size) :
	Enemy(_pos, _size)
{

}

Skelton::~Skelton()
{
}

void Skelton::update()
{
	move();
	fall();
	vector();
}

void Skelton::draw()
{

	drawBox(pos.x(), pos.y(), size.x(), size.y(), 5, Color::white, 0, Vec2f(1, 1), Vec2f(size.x() / 2, size.y() / 2));
}

void Skelton::move()
{
	pos.x()++;
}

void Skelton::stan(Vec2f item_pos, Vec2f item_size)
{
}

bool Skelton::kill(Vec2f player_pos, Vec2f player_size)
{
	if (collisionBox(player_pos, player_size, pos, size)) {

		return true;
	}
	return false;
}

bool Skelton::attack(Vec2f player_pos, Vec2f player_size)
{
	return false;
}
