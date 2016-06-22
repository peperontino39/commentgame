#include "CheckPoint.h"

CheckPoint::CheckPoint(Vec2f _pos, Vec2f _size) :
	BlockBase(_pos, _size)
{

	angle = 0;
	ischeck = false;
}

void CheckPoint::draw()
{
	drawTextureBox(pos.x() - size.x() / 2,
		pos.y() - size.y() / 2,
		size.x(), size.y(), 48, 75, 79 - 48, 128 - 75,
		Textures::get("flagparts"));
	static float a = 0;
	a+= 0.1f;
	drawTextureBox(pos.x(),
		pos.y()+12,
		size.x(), size.y(), 0,0,128,128,
		Textures::get("flag"), Color::white, angle- float(M_PI) / 2.f,Vec2f(3,3), size / 2 + Vec2f(0,-8));
	
}

void CheckPoint::update()
{
	if(env.isPushKey('C')) {
	
		ischeck = !ischeck;
	}
	angle += ((ischeck * 2) - 1) * 0.1f;
	angle = std::min(float(M_PI) / 2.f, std::max(0.f, angle));
}

void CheckPoint::checkPoint()
{
	if (ischeck) return;
	this->ischeck = true;
	start_pos = this->pos;
}

Vec2f CheckPoint::getRespawn()
{
	return start_pos;
}

void CheckPoint::setRespawn(Vec2f _pos)
{
	if (!is_check) return;
	start_pos = _pos;

}

bool CheckPoint::is_check;
Vec2f CheckPoint::start_pos;