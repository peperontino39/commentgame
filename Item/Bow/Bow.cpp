#include "Bow.h"


Bow::Bow() :
	ItemBase(),
	arrows_max_num(10)
{

}

Bow::Bow(Vec2f _pos, Vec2f _size, Vec2f _vec) :
	ItemBase(_pos, _size, _vec),
	arrows_max_num(10)
{
	
}

Bow::~Bow() {

}

void Bow::update() {

	drawTheBow();
	shootTheBow();

	for (auto arrow : arrows)
	{
		arrow.update();
	}
}

void Bow::draw() {
	
	//drawTextureBox(pos.x() - size.x() / 2, pos.y() - size.y() / 2, size.x(), size.y(), cut_pos.x(), cut_pos.y(), cut_size.x(), cut_size.y(), texture, Color(color.x(), color.y(), color.z()));

	/*‰¼’u‚«*/
	drawFillBox(pos.x() - size.x() / 2, pos.y() - size.y() / 2, size.x(), size.y(), Color::green);
	/*‰¼’u‚«*/

	for (auto arrow : arrows)
	{
		arrow.draw();
	}
}

void Bow::drawTheBow() {

	if (env.isPressButton(Mouse::LEFT)) {

		if (env.isPressKey(GLFW_KEY_UP))
			rad += 0.02;
		if (env.isPressKey(GLFW_KEY_DOWN))
			rad -= 0.02;

		if (rad < 0.0f)
			rad = 0.0f;
		if (rad > 0.5f)
			rad = 0.5f;

		arrow_vec.x() = vec_.x() * std::cos(rad);
		arrow_vec.y() = vec_.y() * std::sin(rad);
	}
}

void Bow::shootTheBow() {

	if (env.isPullButton(Mouse::LEFT)) {

		arrows.emplace_back(Arrow(pos, Vec2f(100, 100), arrow_vec));

		if (arrows.size() > arrows_max_num) {

			std::list<Arrow>::iterator first_arrow = arrows.begin();
			arrows.erase(first_arrow);
		}
	}
}
