#include "Bomb.h"


Bomb::Bomb() :
	ItemBase()
{

}

Bomb::Bomb(Vec2f _pos, Vec2f _size) :
	ItemBase(Vec2f::Zero(), Vec2f::Zero())
{

}

Bomb::~Bomb() {

}

void Bomb::update() {

	
}

void Bomb::draw() {

	//drawTextureBox(pos.x(), pos.y(), size.x(), size.y(), 0.0f, 0.0f, 128.0f, 128.0f, texture, Color::white);

	/*‰¼’u‚«*/
	drawFillBox(pos.x(), pos.y(), size.x(), size.y(), Color::blue);
	/*‰¼’u‚«*/
}