#pragma once
#include "../SceneBase/CreateScene.h"
#include "../Title/Title.h"
#include "Icon.h"
#include "../Taxture/Taxtures.h"
class StageSelect : public SceneBase
{
public:
	StageSelect():card_(Vec2f(-500,190),Vec2f(450,300),Vec2f(70,148),Vec2f(358,201), Texture("res/Texture/UI2/ProfCard_UI.png")),
		post_(Vec2f(-500,-220),Vec2f(450,450), Vec2f(0, 0), Vec2f(256, 256), Texture("res/Texture/UI2/Play_UI.png")),
		exit_(Vec2f(WIDTH/2-112,HEIGHT/2-164), Vec2f(0,0), Vec2f(0, 0), Vec2f(256, 256), Texture("res/Texture/UI2/Play_UI.png"))
	{
		select_ = CARD;
		selectnum_ = 1;
		int createnum = 3;
		mouset_ = 0.0f;
		mousepos_ = card_.getpos() + Vec2f(card_.getsize().x() / 2, -card_.getsize().y() / 2);
		savemousepos_ = card_.getpos() + Vec2f(card_.getsize().x() / 2, -card_.getsize().y() / 2);
		nextmousepos_ = card_.getpos() + Vec2f(card_.getsize().x() / 2, -card_.getsize().y() / 2);
		for (int i = 0;i < createnum;i++) {
			Vec2f size = Vec2f(730, 180);
			Vec2f pos = Vec2f(375, 180 - i*(size.y()*1.3f));
			stagelavel_.push_back(Icon(pos, size,Vec2f(34,193),Vec2f(434,115), Texture("res/Texture/UI2/Stage_UI.png")));
		}
		loadRes();
		bgm_.play();
		bgm_.gain(1);
		bgm_.looping(true);
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
	Texture window_tex_;
	Texture background_tex_;
	Texture mouse_tex_;
	Texture scroll_tex_;
	Texture scrollbar_tex_;
	Texture dodai_tex_;
	Media bgm_;
	Media mouse_se_;
	Media start_se_;
	Media select_se_;
	Media cyancel_se_;
	Vec2f getNextMousePos();
	void loadRes();
	void ResetMouseEasing();
	void easingMousePointer();
	void ChangeSelectIcon();
	void drawDodai();
	void drawMousePointer();
	void drawWindow();
	void drawBackground();
	void drawScrollbar();
	void drawCenterBox(const Vec2f pos,const Vec2f size,const Color color);
	void drawCenterTexture(const Vec2f pos,const Vec2f size,const Texture image);
};