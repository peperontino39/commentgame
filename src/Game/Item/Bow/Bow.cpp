#include "Bow.h"


Bow::Bow() :
	ItemBase(),
	max_arrow_vec(10),
	arrow_vec(arrow_vec_),
	rad(0.0f)
{
	//Textures::set("bow", "res/Texture/Item/Bow.png");

	arrow_vec = Vec2f::Zero();
}

Bow::Bow(Vec2f _pos, Vec2f _size) :
	ItemBase(ItemID::BOW, _pos, _size, Vec2f::Zero()),
	max_arrow_vec(10),
	arrow_vec(arrow_vec_),
	rad(0.0f)
{
	//Textures::set("bow", "res/Texture/Item/Bow.png");

	arrow_vec = Vec2f::Zero();
}

Bow::~Bow() {

}

void Bow::putDownTheBow(const Vec2f& pos) {

	this->pos = pos;
	is_player_have = false;
	is_draw = true;
}

void Bow::update() {

	drawTheBow();
	shootTheBow();
}

void Bow::draw() {

	//drawTextureBox(pos.x() - size.x() / 2, pos.y() - size.y() / 2, size.x(), size.y(), cut_pos.x(), cut_pos.y(), cut_size.x(), cut_size.y(), Textures.get("bow"), Color(color.x(), color.y(), color.z()));

	/*���u��*/
	//�|
	drawFillBox(pos.x() - size.x() / 2, pos.y() - size.y() / 2, size.x(), size.y(), Color::green);
	//�\����
	if (env.isPressKey(GLFW_KEY_ENTER))
		drawLine(pos.x(), pos.y(), pos.x() + (arrow_vec_.x() * 10.0f), pos.y() + (arrow_vec_.y() * 10.0f), 10, Color(1.0f, 1.0f, 0.0f, 0.5f));
	/*���u��*/
}

void Bow::drawTheBow() {

	if (!env.isPressKey(GLFW_KEY_ENTER))
		return;

	if (is_player_have != true)
		return;

	changeAngle();
}

Vec2f Bow::shootTheBow() {

	arrow_vec_.x() = max_arrow_vec * std::cos(rad);
	arrow_vec_.y() = max_arrow_vec * std::sin(rad);

	return arrow_vec;
}

void Bow::changeAngle() {

	//���90�x�܂�
	if (env.isPressKey(GLFW_KEY_UP) && rad < 0.5f)
		rad += 0.05f;
	//����0�x�܂�
	else if (env.isPressKey(GLFW_KEY_UP) && rad > 0.0f)
		rad -= 0.05f;

}