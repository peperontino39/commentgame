#include "Golem.h"

Golem::Golem(Vec2f _pos, Vec2f _size) :
	Enemy(_pos, _size)
{
	std::string pattern("res/Texture/Enemy/golem_pattern.txt");
	std::string action("res/Texture/Enemy/golem_animation.txt");
	readPatterns(pattern);
	readAction(action);

	std::string register_key("golem");
	std::string resourse("res/Texture/Enemy/golemMotion.png");
	Textures::set(register_key, resourse);
}

Golem::~Golem()
{
}

void Golem::update()
{
	if (!stan_flag) {
	move();
	fall();
	vector();
	updateChara();
	}
	if (stan_flag == true) {
		vec_.x() = 0.0f;
	}
}

void Golem::draw()
{
	if (!blind) {
		drawChara(pos, Textures::get("golem"));
	}
	//drawBox(pos.x(), pos.y(), size.x(), size.y(), 5, Color::white, 0, Vec2f(1, 1), Vec2f(size.x() / 2, size.y() / 2));
}

void Golem::move()
{
	
}




Vec2f Golem::ride(Vec2f player_pos, Vec2f player_size, Vec2f vec)
{
	return player_pos;
}