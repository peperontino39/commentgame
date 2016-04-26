#include "Bomb.h"


Bomb::Bomb() :
	pos(Vec2f::Zero()),
	size(Vec2f::Zero())
{

}

Bomb::Bomb(Vec2f _pos, Vec2f _size) :
	pos(_pos),
	size(_size)
{

}

Bomb::~Bomb() {

}

void Bomb::use(Vec2f _pos, Direction _direction) {

}

void Bomb::update() {

	
}

void Bomb::draw() {

	//drawTextureBox(pos.x(), pos.y(), size.x(), size.y(), 0.0f, 0.0f, 128.0f, 128.0f, texture, Color::white);

	/*‰¼’u‚«*/
	drawFillBox(pos.x(), pos.y(), size.x(), size.y(), Color::blue);
	/*‰¼’u‚«*/
}