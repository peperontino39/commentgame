#pragma once
#include "../SceneBase/CreateScene.h"
#include "../Title/Title.h"
#include "Icon.h"
#include "../Taxture/Taxtures.h"
class StageSelect : public SceneBase
{
public:
	StageSelect():card_(Vec2f(-540,270),Vec2f(500,300), Texture("res/Texture/Block/blacklock.png")),
		post_(Vec2f(-540,-220),Vec2f(400,250), Texture("res/Texture/Block/blacklock.png")),
		exit_(Vec2f(WIDTH/2-25,HEIGHT/2-25), Vec2f(50,50), Texture("res/Texture/Block/blacklock.png"))
	{
		select_ = CARD;
		selectnum_ = 1;
		int createnum = 3;
		mouset_ = 0.0f;
		mousepos_ = card_.getpos();
		savemousepos_ = card_.getpos();
		nextmousepos_ = card_.getpos();
		for (int i = 0;i < createnum;i++) {
			Vec2f size = Vec2f(700, 220);
			Vec2f pos = Vec2f(350, 300 - i*(size.y()*1.4f));
			stagelavel_.push_back(Icon(pos, size, Texture("res/Texture/Block/blacklock.png")));
		}
		
	};
	void update() override;
	void draw() override;
	void shift() override;

private:
	Icon card_, post_, exit_;
	std::vector<Icon> stagelavel_;
	enum Select {
		CARD = 0, POST = 1, EXIT = 2, STAGE = 3
	};
	Select select_;
	int selectnum_;

	Vec2f mousepos_;
	Vec2f savemousepos_;
	Vec2f nextmousepos_;
	float mouset_;

	Vec2f getNextMousePos();
	void ResetMouseEasing();
	void easingMousePointer();
	void ChangeSelectIcon();
	void drawMousePointer();
	void drawBackground();
	void drawCenterBox(const Vec2f pos,const Vec2f size,const Color color);
	void drawCenterTexture(const Vec2f pos,const Vec2f size,const Texture image);
};