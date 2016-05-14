#include "Magma.h"

Magma::Magma(Vec2f _pos, Vec2f _size):
	NormalBlock(_pos,_size)
{
	count = 0;
}

void Magma::draw()
{
	drawTextureBox(pos.x() - size.x() / 2, pos.y() - size.y() / 2, size.x(), size.y(), count/30 % 3 * 128, 0, 
		128, 128,
		Textures::get("magma"));
}

void Magma::update()
{
	count++;
}
