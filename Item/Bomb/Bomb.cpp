#include "Bomb.h"

float getAnimationCutPositionX(
	Vec2f cut_size,
	int& animation_count,
	int animation_display_time,
	int animation_cut_num) {

	return cut_size.x() *
		(static_cast<float>((++animation_count / animation_display_time) % animation_cut_num));

}




Bomb::Bomb() :
	ItemBase(),
	explosion_count(600),
	is_countdown(false),
	is_explosion(false)
{

}

Bomb::Bomb(Vec2f _pos, Vec2f _size, Vec2f _vec) :
	ItemBase(_pos, _size, _vec),
	explosion_count(600),
	is_countdown(false),
	is_explosion(false)
{

}

Bomb::~Bomb() {

}

void Bomb::update() {

	move();
	countDown();
	animation();
}

void Bomb::draw() {

	//drawTextureBox(pos.x() - size.x() / 2, pos.y() - size.y() / 2, size.x(), size.y(), cut_pos.x(), cut_pos.y(), cut_size.x(), cut_size.y(), texture, Color(color.x(), color.y(), color.z()));

	/*‰¼’u‚«*/
	drawFillBox(pos.x() - size.x() / 2, pos.y() - size.y() / 2, size.x(), size.y(), Color::blue);
	/*‰¼’u‚«*/
}





void Bomb::move() {

	if (is_countdown != true)
		return;

	if (vec_.x() < 0.0f) {

		vec_.x() += 1.0f;

		if (vec_.x() > 0.0f)
			vec_.x() = 0.0f;
	}

	if (vec_.x() > 0.0f) {

		vec_.x() += -1.0f;

		if (vec_.x() < 0.0f)
			vec_.x() = 0.0f;
	}

	vec_.y() += -1.0f;

	if (vec_.y() < -10.0f)
		vec_.y() = -10.0f;


	pos += vec_;
}

void Bomb::countDown() {

	if (is_countdown != true || explosion_count <= 0)
		return;

	--explosion_count;

	if (explosion_count <= 0)
		is_explosion = true;
}

void Bomb::animation() {

	if (is_explosion != true) {

		animation_count = 0;
		return;
	}

	cut_pos.x() = getAnimationCutPositionX(cut_size, animation_count, 20, 6);
}