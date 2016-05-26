#include "Bow.h"


Bow::Bow() :
	ItemBase(),
	max_arrow_vec(10),
	arrow_vec(Vec2f::Zero()),
	rad(0.0f)
{
	//Textures::set("bow", "res/Texture/Item/Bow.png");
}

Bow::Bow(Vec2f _pos, Vec2f _size) :
	ItemBase(ItemID::BOW, _pos, _size, Vec2f::Zero()),
	max_arrow_vec(10),
	arrow_vec(Vec2f::Zero()),
	rad(0.0f)
{
	//Textures::set("bow", "res/Texture/Item/Bow.png");
}

Bow::~Bow() {

}

void Bow::putDownTheBow(const Vec2f& pos) {

	 setPos(pos);
	is_player_have = false;
	is_draw = true;
}

void Bow::update() {

	drawTheBow();
	shootTheBow();
}

void Bow::draw() {

	//drawTextureBox(getPos().x() - getSize().x() / 2, getPos().y() - getSize().y() / 2, getSize().x(), getSize().y(), cut_pos.x(), cut_pos.y(), cut_size.x(), cut_size.y(), Textures.get("bow"), Color(color.x(), color.y(), color.z()));

	/*���u��*/
	//�|
	drawFillBox(getPos().x() - getSize().x() / 2, getPos().y() - getSize().y() / 2, getSize().x(), getSize().y(), Color::green);
	//�\����
	if (env.isPressKey(GLFW_KEY_ENTER))
		drawLine(getPos().x(), getPos().y(), getPos().x() + (arrow_vec.x() * 10.0f), getPos().y() + (arrow_vec.y() * 10.0f), 10, Color(1.0f, 1.0f, 0.0f, 0.5f));
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

	arrow_vec.x() = max_arrow_vec * std::cos(rad);
	arrow_vec.y() = max_arrow_vec * std::sin(rad);

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