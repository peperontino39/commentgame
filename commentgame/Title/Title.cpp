#include "Title.h"

Title::Title()
{
}

void Title::update()
{
	
}

void Title::draw()
{
	drawFillBox(0, 0, 100, 100, Color::red);
}

void Title::shift()
{
	if (env.isPushButton(Mouse::LEFT)) {
		Scene::create<StageSelect>(new StageSelect());
	}
}

