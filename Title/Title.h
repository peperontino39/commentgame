#pragma once
#include "../SceneBase/CreateScene.h"
#include "../StageSelect/StageSelect.h"
#include "../easing.h"
#include <codecvt>

class Title : public SceneBase
{
public:
	Title();
	void update() override;
	void draw() override;
	void shift() override;

	float x = 0;
	bool is_in = true;
	

protected:
	Font titleFont;
};