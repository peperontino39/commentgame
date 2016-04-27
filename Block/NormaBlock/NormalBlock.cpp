#include "NormalBlock.h"

NormalBlock::NormalBlock(Vec2f _pos,Vec2f _size) :
	BlockBase(_pos, _size)
{

}

NormalBlock::~NormalBlock()
{

}

void NormalBlock::update()
{
}

void NormalBlock::draw()
{
	drawFillBox(pos.x() - size.x() / 2, 
		pos.y() - size.y() / 2, 
		size.x(), size.y(),Color::blue);
}
