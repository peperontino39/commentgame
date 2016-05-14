#include "Bomb.h"

Vec2f getAnimationCutPosition(
	Vec2f cut_size,
	int& animation_count,
	Vec2i animation_display_time,
	Vec2i animation_cut_num) {

	Vec2f cut_pos;
	cut_pos.x() = cut_size.x() *
		(static_cast<float>((++animation_count / animation_display_time.x()) % animation_cut_num.x()));
	cut_pos.y() = cut_size.y() *
		(static_cast<float>((++animation_count / animation_display_time.y()) % animation_cut_num.y()));

	return cut_pos;
}




Bomb::Bomb() :
	ItemBase(),
	explosion_count(600),
	animation_count(0),
	respawn_time(60),
	is_explosion(is_explosion_),
	is_respawn_bomb(is_respawn_bomb_),
	cut_pos(Vec2f::Zero()),
	cut_size(Vec2f(0.0f, 0.0f)),
	color(Vec3f(1.0f, 1.0f, 1.0f))
{
	Textures::set("bomb", "res/Texture/Block/bomb.png");
	is_explosion = false;
	is_respawn_bomb = true;
}

Bomb::Bomb(Vec2f _pos, Vec2f _size, Vec2f vec) :
	ItemBase(ItemID::BOMB, _pos, _size, vec),
	explosion_count(600),
	animation_count(0),
	is_explosion(is_explosion_),
	is_respawn_bomb(is_respawn_bomb_),
	cut_pos(Vec2f(0.0f, 0.0f)),
	cut_size(Vec2f(256.0f, 256.0f)),
	color(Vec3f(1.0f, 1.0f, 1.0f))
{
	Textures::set("bomb", "res/Texture/Block/bomb.png");
	is_explosion = false;
	is_respawn_bomb = true;
}

Bomb::~Bomb() {

}

void Bomb::update() {

	countDown();
	animation();
	updatePos();
}

void Bomb::draw() {

	drawTextureBox(pos.x() - size.x() / 2,
		pos.y() - size.y() / 2,
		size.x(),
		size.y(),
		cut_pos.x(),
		cut_pos.y(),
		cut_size.x(),
		cut_size.y(),
		Textures::get("bomb"),
		Color(color.x(), color.y(), color.z()));
}





void Bomb::countDown() {

	if (is_countdown != true || explosion_count <= 0)
		return;

	--explosion_count;

	if (explosion_count <= 0)
		is_explosion_ = true;
}

void Bomb::animation() {

	if (is_explosion_ != true)
		return;

	cut_pos = getAnimationCutPosition(cut_size, animation_count, Vec2i(20, 120), Vec2i(6, 2));

	--explosion_end_count;

	if (explosion_end_count <= 0)
		is_end_ = true;
}

void Bomb::updatePos() {

	if (vec_.x() > 0.0f)
		vec_.x() -= 0.1f;
	else if (vec_.x() < 0.0f)
		vec_.x() += 0.1f;

	vec_.y() -= 0.3f;

	if (vec_.x() >= -0.1f && vec_.x() < 0.1f)
		vec_.x() = 0.0f;
	if (vec_.y() >= -3.0f)
		vec_.y() = -3.0f;

	pos = vec;
}
