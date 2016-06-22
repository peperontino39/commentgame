#include "Bow.h"


Bow::Bow() :
	ItemBase(),
	bow_status(BowStatus::NOMAL),
	max_arrow_vec(10),
	arrow_vec(Vec2f::Zero()),
	rad(0.0f)
{
	Textures::set("Bow", "res/Texture/Item/Bow.png");
	Textures::set("BowObj", "res/Texture/Item/BowObj.png");
}

Bow::Bow(Vec2f _pos, Vec2f _size) :
	ItemBase(ItemID::BOW, _pos, _size, Vec2f::Zero(), Vec2f(0.0f, 0.0f), Vec2f(256.0f, 256.0f)),
	bow_status(BowStatus::NOMAL),
	max_arrow_vec(10),
	arrow_vec(Vec2f::Zero()),
	rad(0.0f)
{
	Textures::set("Bow", "res/Texture/Item/Bow.png");
	Textures::set("BowObj", "res/Texture/Item/BowObj.png");
}

Bow::~Bow() {

}

void Bow::putDownTheBow(const Vec2f& pos) {

	setPos(pos);
	is_player_have = false;
	is_draw = true;
}

void Bow::update() {

	if (bow_status == BowStatus::DRAW)
	{
		animation_count = std::min(10, ++animation_count);
		index = animation_count / 5;
	}
	else if (bow_status == BowStatus::SHOOT)
	{
		++animation_count;
		index = animation_count / 5;

		if (animation_count > 19)
		{
			animation_count = 0;
			index = 0;
			bow_status = BowStatus::NOMAL;
		}
	}

	if (env.isPullKey('P'))
	{
		if (index == 2)
			bow_status = BowStatus::SHOOT;
		else
		{
			animation_count = 0;
			index = 0;
			bow_status = BowStatus::NOMAL;
		}
	}

	drawTheBow();
	changeAngle();
}

void Bow::draw() {

	if (is_draw == true)
		drawTextureBox(getPos().x() - getSize().x() / 2,
			getPos().y() - getSize().y() / 2,
			getSize().x(), getSize().y(),
			cut_pos.x() + cut_size.x() * index,
			cut_pos.y(),
			cut_size.x(),
			cut_size.y(),
			Textures::get("BowObj"),
			Color(color.x(), color.y(), color.z()));
	else
		if (player_direction == 1)
		{
			drawTextureBox(getPos().x() - getSize().x() / 2 + 2.0f,
				getPos().y() + 8.0f,
				getSize().x(), getSize().y(),
				cut_pos.x() + cut_size.x() * index,
				cut_pos.y(),
				cut_size.x(),
				cut_size.y(),
				Textures::get("Bow"),
				Color(color.x(), color.y(), color.z()),
				rad,
				Vec2f(1.0f, 1.0f),
				Vec2f(2.0f, getSize().y() / 2.0f + 5.0f));
		}
		else if (player_direction == -1)
		{
			drawTextureBox(getPos().x() - getSize().x() / 2 + 8.0f,
				getPos().y() + 8.0f,
				getSize().x(), getSize().y(),
				cut_pos.x() + cut_size.x() * index,
				cut_pos.y(),
				cut_size.x(),
				cut_size.y(),
				Textures::get("Bow"),
				Color(color.x(), color.y(), color.z()),
				-rad,
				Vec2f(-1.0f, 1.0f),
				Vec2f(2.0f, getSize().y() / 2.0f + 5.0f));
		}

	//ó\ë™ê¸
	if (index == 2 && bow_status == BowStatus::DRAW)
	{
		if (player_direction == 1)
			drawLine(getPos().x() - 25.0f, getPos().y() + 8.0f, getPos().x() - 25.0f + arrow_vec.x() * 5.0f, getPos().y() + 8.0f + (arrow_vec.y() * 5.0f), 5, Color(1.0f, 1.0f, 0.0f, 0.5f));
		else if (player_direction == -1)
			drawLine(getPos().x() - 15.0f, getPos().y() + 7.0f, getPos().x() - 15.0f + arrow_vec.x() * 5.0f * -1.0f, getPos().y() + 7.0f + (arrow_vec.y() * 5.0f), 5, Color(1.0f, 1.0f, 0.0f, 0.5f));
	}
	/*âºíuÇ´*/
}

void Bow::drawTheBow() {

	if (!env.isPushKey('P'))
		return;

	if (is_player_have != true)
		return;

	if (bow_status != BowStatus::NOMAL)
		return;

	bow_status = BowStatus::DRAW;
}

Vec2f Bow::shootTheBow() {

	if (player_direction == 1)
		arrow_vec.x() = max_arrow_vec * std::cos(rad);
	if (player_direction == -1)
		arrow_vec.x() = max_arrow_vec * std::cos(rad) * -1.0f;

	arrow_vec.y() = max_arrow_vec * std::sin(rad);

	return arrow_vec;
}

void Bow::changeAngle() {

	if (is_player_have != true)
		return;

	if (bow_status != BowStatus::DRAW)
		return;

	//è„å¿90ìxÇ‹Ç≈
	if (env.isPressKey(GLFW_KEY_UP) && rad < 0.5f)
		rad += 0.05f;
	//â∫å¿0ìxÇ‹Ç≈
	else if (env.isPressKey(GLFW_KEY_DOWN) && rad > 0.05f)
		rad -= 0.05f;

	arrow_vec.x() = max_arrow_vec * std::cos(rad);
	arrow_vec.y() = max_arrow_vec * std::sin(rad);

}