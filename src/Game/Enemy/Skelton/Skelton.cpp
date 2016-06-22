#include "Skelton.h"

Skelton::Skelton(Vec2f _pos, Vec2f _size) :
	Enemy(_pos, _size)
{
	std::string pattern("res/Texture/Enemy/skelton_pattern.txt");
	std::string action("res/Texture/Enemy/skelton_animation.txt");
	readPatterns(pattern);
	readAction(action);
	std::string register_key("skelton");
	std::string resourse("res/Texture/Enemy/skeletonMotion.png");
	Textures::set(register_key, resourse);
	vec_.x() = 0.5f;
	increment = 0;
	decrement = 0;
	setup = 0;
	buf_pos = _pos;
	buf_size = _size;
}

Skelton::~Skelton()
{
}

void Skelton::addpos(Vec2f _vec) {

	if (_vec.y() > 0) {
		vec_.y() = 0;
	}
	this->pos += _vec;

	if (_vec.x() > 0) {
		vec_.x() = 0.5;
	}
	if (_vec.x() < 0) {
		vec_.x() = -0.5;
	}

}
void Skelton::update()
{
	setup++;
	if (setup==1) {
		buf_pos = pos;
		buf_size = size;
	}
	if (increment == 0) {
		decrement++;
		if (decrement == 1) {
			changeCharaAction(0);
			pos = buf_pos;
			size = buf_size;
		}
	}
	if (direction_ == Direction::RIGHT) {
		attack_pos = pos + Vec2f(size.x()*3/2, 0.0f);
		attack_size = size - Vec2f(size.x()/2, 0.0f);
	}
	if (direction_ == Direction::LEFT) {
		attack_pos = pos + Vec2f(-size.x()/2, 0.0f);
		attack_size = size - Vec2f(size.x() / 2, 0.0f);
	}
	if (increment == 1) {
		buf_pos = pos;
		buf_size = size;
		pos = pos - Vec2f(33, 0.0f);
		size = size + Vec2f(33, 0);
		changeCharaAction(1);
	}
	if (increment <= 5) {
		if (!stan_flag) {
			move();
			fall();
			vector();
			
			directionControlEnemy();
		}
	}
	if (stan_flag == true) {
		vec_.x() = 0.0f;
	}
	updateChara();
}

void Skelton::draw()
{
	if (!blind) {
		drawChara(pos, Textures::get("skelton"));
	}
	//drawBox(pos.x(), pos.y(), size.x(), size.y(), 5, Color::white, 0, Vec2f(1, 1), Vec2f(size.x() / 2, size.y() / 2));
}

void Skelton::move()
{

}





bool Skelton::attack(Vec2f player_pos, Vec2f player_size)
{
	if (collisionBox(pos, size, player_pos, player_size)) {
		increment = 0;
		return true;
	}
	if (collisionBox(attack_pos, attack_size, player_pos, player_size)) {
		increment++;
		decrement = 0;
		if (increment >= 15){
			return true;
		}
		return false;
	}
	increment = 0;
	return false;
}
Vec2f Skelton::ride(Vec2f player_pos, Vec2f player_size, Vec2f vec)
{
	return player_pos;
}