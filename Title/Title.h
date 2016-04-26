#pragma once
#include "../SceneBase/CreateScene.h"
#include "../StageSelect/StageSelect.h"

class Title : public SceneBase
{
public:
	Title();
	void update() override;
	void draw() override;
	void shift() override;

private:

};