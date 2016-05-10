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
	is_explosion(false),
	cut_pos(Vec2f::Zero()),
	cut_size(Vec2f(0.0f, 0.0f)),
	color(Vec3f(1.0f, 1.0f, 1.0f))
{
	Textures::set("bomb", "res/Texture/Block/bomb.png");
}

Bomb::Bomb(Vec2f _pos, Vec2f _size, Vec2f vec) :
	ItemBase(ItemID::BOMB, _pos, _size, vec),
	explosion_count(600),
	animation_count(0),
	is_explosion(false),
	cut_pos(Vec2f(0.0f, 0.0f)),
	cut_size(Vec2f(256.0f, 256.0f)),
	color(Vec3f(1.0f, 1.0f, 1.0f))
{
	Textures::set("bomb", "res/Texture/Block/bomb.png");
}

Bomb::~Bomb() {

}

void Bomb::update() {

	countDown();
	animation();
	gravity();
}

void Bomb::draw() {

	drawTextureBox(pos.x() - size.x() / 2, pos.y() - size.y() / 2, size.x(), size.y(), cut_pos.x(), cut_pos.y(), cut_size.x(), cut_size.y(), Textures::get("bomb"), Color(color.x(), color.y(), color.z()));

	/*‰¼’u‚«*/
	//drawFillBox(pos.x() - size.x() / 2, pos.y() - size.y() / 2, size.x(), size.y(), Color::blue);
	/*‰¼’u‚«*/
}





void Bomb::countDown() {

	if (is_countdown != true || explosion_count <= 0)
		return;

	--explosion_count;

	if (explosion_count <= 0)
		is_explosion = true;
}

void Bomb::animation() {

	if (is_explosion != true)
		return;

	cut_pos = getAnimationCutPosition(cut_size, animation_count, Vec2i(20, 120), Vec2i(6, 2));

	--explosion_end_count;

	if (explosion_end_count <= 0)
		is_end_ = true;
}

void Bomb::gravity() {

	vec_.x() -= 0.1f;
	vec_.y() -= 0.3f;

	if (vec_.x() >= -0.1f && vec_.x() < 0.1f)
		vec_.x() = 0.0f;
	if (vec_.y() >= -3.0f)
		vec_.y() = -3.0f;

	pos = vec;
}
