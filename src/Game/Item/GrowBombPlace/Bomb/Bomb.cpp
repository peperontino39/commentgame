#include "Bomb.h"

Vec2f EasingLinar(float& count, Vec2f start_pos, Vec2f end_pos, float frame)
{
	Vec2f pos;

	count += 1.0f / frame;

	pos.x() = (end_pos.x() - start_pos.x()) * count + start_pos.x();
	pos.y() = (end_pos.y() - start_pos.y()) * count + start_pos.y();

	return pos;
}



Bomb::Bomb() :
	ItemBase(),
	animation_count2(0),
	animation_frame(40),
	respawn_time(0.0f),
	is_end(false),
	index2(0),
	index_y(0),
	bomb_status(BombStatus::GROWING),
	explosion_size(Vec2f(100.0f, 100.0f)),
	catching_count(0.0f),
	catxhed_pos(Vec2f::Zero()),
	catch_pos(Vec2f::Zero()),
	b_vec(Vec2f::Zero())
{
	Textures::set("Bomb", "res/Texture/Item/bomb.png");
	cut_size = Vec2f(128.0f, 128.0f);
}

Bomb::Bomb(Vec2f _pos, Vec2f _size, Vec2f vec) :
	ItemBase(ItemID::BOMB, _pos, _size, vec, Vec2f(0.0f, 0.0f), Vec2f(113.0f, 128.0f)),
	animation_count2(0),
	animation_frame(40),
	respawn_time(0.0f),
	is_end(false),
	index2(0),
	index_y(0),
	bomb_status(BombStatus::GROWING),
	explosion_size(Vec2f(100.0f, 100.0f)),
	catching_count(0.0f),
	catxhed_pos(Vec2f::Zero()),
	catch_pos(Vec2f::Zero()),
	b_vec(Vec2f::Zero())
{
	Textures::set("Bomb", "res/Texture/Item/bomb.png");
}

Bomb::~Bomb() {


}

void Bomb::update() {

	Respawn();
	catching();
	countDown();
	animation();
	updatePos();
}

void Bomb::draw() {

	drawTextureBox(getPos().x() - getSize().x() / 2.0f * respawn_time * 1.5f,
		getPos().y() - getSize().y() / 2,
		getSize().x() * respawn_time * 1.5f,
		getSize().y() * respawn_time * 1.5f,
		cut_size.x() * (index + index2),
		cut_size.y() * index_y,
		cut_size.x(),
		cut_size.y(),
		Textures::get("Bomb"),
		Color(color.x(), color.y(), color.z()));
}

Vec2f Bomb::getBVec()
{
	return b_vec;
}





void Bomb::Respawn()
{
	if (bomb_status != BombStatus::GROWING)
		return;

	respawn_time = std::min(1.0f, respawn_time + 1.0f / 30.0f);

	if (respawn_time == 1.0f)
		bomb_status = BombStatus::NORMAL;
}

void Bomb::catching()
{
	if (bomb_status != BombStatus::CATCHING)
		return;

	setPos(EasingLinar(catching_count, catch_pos, catxhed_pos, 50.0f));

	if (catching_count >= 1.0f)
		bomb_status = BombStatus::COUNTDOWN;
}

void Bomb::countDown() {

	if (bomb_status == BombStatus::GROWING ||
		bomb_status == BombStatus::NORMAL ||
		bomb_status == BombStatus::CATCHING)
		return;

	animation_count = std::min(600, ++animation_count);

	if (bomb_status == BombStatus::COUNTDOWN)
	{
		index = animation_count / animation_frame % 9;
		index_y = animation_count / (animation_frame * 9) % 2;
	}

	if (bomb_status == BombStatus::EXPLOSION)
	{
		animation_count2 = std::min(animation_frame * 3, ++animation_count2);
		index2 = animation_count2 / animation_frame % 4;
	}

	if (animation_count == 600)
	{
		bomb_status = BombStatus::EXPLOSION;
		animation_frame = 60;
	}
}

void Bomb::animation() {

	if(bomb_status != BombStatus::EXPLOSION)
		return;

	if (animation_count2 == 180)
		is_end = true;
}

void Bomb::updatePos() {

	if (bomb_status != BombStatus::COUNTDOWN)
		return;
	if (is_player_have != false)
		return;

	b_vec.y() -= 0.1f;

	if (b_vec.y() <= -3.0f)
		b_vec.y() = -3.0f;

	setPos(Vec2f(getPos().x() + b_vec.x(), getPos().y() + b_vec.y()));
}
