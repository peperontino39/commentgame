#include "Fire.h"

Fire::Fire(Vec2f _pos, Vec2f _size,Direction _direction)
	: MoveObject(_pos, _size) 
{
	direction = _direction;
	std::string register_key("boss_fire");
	std::string resourse("res/Texture/Enemy/Fire.png");
	Textures::set(register_key, resourse);
	count = 0;
	active = true;
};

void Fire::update()
{
	count++;
	if (direction == Direction::LEFT) {
		pos.x()--;
	}
	if (direction == Direction::RIGHT) {
		pos.x()++;
	}

	if(count >= 1000){
		active = false;
	}
}

void Fire::draw()
{
	if (direction == Direction::RIGHT) {
		drawTextureBox(pos.x()+size.x()/2, pos.y(), size.x(), size.y(), 0, 0, 256, 256, Textures::get("boss_fire"), Color::white
			,0,Vec2f(-1,1),Vec2f(size.x()/2,0));
	}
	if (direction == Direction::LEFT) {
		drawTextureBox(pos.x() + size.x() / 2, pos.y(), size.x(), size.y(), 0, 0, 256, 256, Textures::get("boss_fire"), Color::white
			, 0, Vec2f(1, 1), Vec2f(size.x() / 2, 0));
	}
}
