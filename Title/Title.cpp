#include "Title.h"

Title::Title():titleFont("res/meiryo.ttc")
{
	float x = 0;
	bool is_in = true;
	titleFont.size(20);
}

void Title::update()
{
	if (is_in == true)
	{
		Easing::Start(x, 300, Easing::Function::BackInOut, 60);
	}
	else
		Easing::Start(x, -300, Easing::Function::BackInOut, 60);

	if (env.isPushButton(Mouse::RIGHT))
	{
		
		if (Easing::BeginSet(x))
			is_in = !is_in;
	}
}

void Title::draw()
{

	drawFillBox(0, 0, x, x, Color::red);
	
	titleFont.draw("ƒTƒ“ƒvƒ‹", Vec2f(100, 100), Color::white);
}

void Title::shift()
{
	if (env.isPushButton(Mouse::LEFT)) {
		Scene::create<StageSelect>(new StageSelect());
	}
}

