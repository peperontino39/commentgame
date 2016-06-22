#include "StageSelect.h"
#include "../GameMain/GameMain.h"



void StageSelect::update()
{
	ChangeSelectIcon();
	easingMousePointer();
	card_.update(select_ == CARD);
	post_.update(select_ == POST);
	exit_.update(select_ == EXIT);
	for (int i = 0;i < stagelavel_.size(); i++) {
		stagelavel_[i].update(select_ == STAGE && (i + 1) == selectnum_);
	}

}
void StageSelect::ChangeSelectIcon() {
	switch (select_)
	{
	case CARD:
		if (env.isPushKey('W')) {
			select_ = EXIT;
			ResetMouseEasing();
		}
		if (env.isPushKey('D') && stagelavel_.size() >= 1) {
			select_ = STAGE;
			if (selectnum_ >= 3)
				selectnum_ = 1;
			ResetMouseEasing();
		}
		if (env.isPushKey('S')) {
			select_ = POST;
			ResetMouseEasing();
		}
		break;
	case POST:
		if (env.isPushKey('W')) {
			select_ = CARD;
			ResetMouseEasing();
		}
		if (env.isPushKey('D') && stagelavel_.size() >= 1) {
			select_ = STAGE;
			ResetMouseEasing();
		}
		break;
	case EXIT:
		if (env.isPushKey('S')&&stagelavel_.size()>=1) {
			select_ = STAGE;
			selectnum_ = 1;
			ResetMouseEasing();
		}
		if (env.isPushKey('A')) {
			select_ = CARD;
			ResetMouseEasing();
		}
		break;
	case STAGE:
		if (env.isPushKey('W')) {
			if (selectnum_ == 1) {
				select_ = EXIT;
			}
			else {
				selectnum_--;
			}
			ResetMouseEasing();
		}
		if (env.isPushKey('S')) {
			if (!(selectnum_ == stagelavel_.size())) {
				selectnum_++;
				ResetMouseEasing();
			}
		}
		if (env.isPushKey('A')) {
			if (selectnum_ == 1) {
				select_ = CARD;
			}
			else {
				select_ = POST;
			}
			ResetMouseEasing();
		}
		break;
	default:
		break;
	}
}

void StageSelect::easingMousePointer() {
	mousepos_.x() = Easing::Function::CircOut(mouset_, savemousepos_.x(), nextmousepos_.x());
	mousepos_.y() = Easing::Function::CircOut(mouset_, savemousepos_.y(), nextmousepos_.y());
	float speed = 0.3f;
	mouset_ += 1.0f / (60.0f*speed);
	mouset_ = std::min(mouset_, 1.0f);
	
}
void StageSelect::ResetMouseEasing(){
	mouse_se_.play();
	savemousepos_ = mousepos_;
	nextmousepos_ = getNextMousePos();
	mouset_ = 0.0f;
}
Vec2f StageSelect::getNextMousePos() {
	switch (select_)
	{
	case CARD:
		return card_.getpos()+Vec2f(card_.getsize().x()/3,-card_.getsize().y()/3);
	case POST:
		return post_.getpos() + Vec2f(post_.getsize().x() / 7, -post_.getsize().y() / 7);
	case EXIT:
		return exit_.getpos();
	case STAGE:
		return stagelavel_[selectnum_ - 1].getpos()
			+Vec2f(stagelavel_[selectnum_-1].getsize().x()/3, -stagelavel_[selectnum_ - 1].getsize().y()/3);
	default:
		break;
	}
}
void StageSelect::draw()
{
	drawWindow();
	drawBackground();
	drawDodai();
	card_.draw();
	post_.draw();
	exit_.draw();
	drawScrollbar();
	for (int i = 0;i < stagelavel_.size(); i++) {
		stagelavel_[i].draw();
	}
	drawMousePointer();
}
void StageSelect::drawMousePointer() {
	drawCenterTexture(mousepos_,Vec2f(75,75),mouse_tex_);
}
void StageSelect::drawDodai() {
	drawCenterTexture(Vec2f(350,-20), Vec2f(920, 810), dodai_tex_);
}
void StageSelect::drawScrollbar() {
	Vec2f pos = Vec2f(-15, -50);
	Vec2f size = Vec2f(870, 760);
	drawCenterTexture(pos,size, scrollbar_tex_);
	drawCenterTexture(pos+Vec2f(-22,0), Vec2f(size.x()*0.2,size.y()*0.6), scroll_tex_);
}
void StageSelect::drawWindow() {
	Vec2f pos = Vec2f(-WIDTH / 2, -HEIGHT / 2);
	Vec2f size = Vec2f(WIDTH, HEIGHT);
	drawTextureBox(pos.x(), pos.y(), size.x(), size.y(),
		0, 0, window_tex_.width(), window_tex_.height(), window_tex_, Color::white);
}
void StageSelect::drawBackground() {
	Vec2f pos = Vec2f(0,-22);
	Vec2f size = Vec2f(1678, 825);
	drawTextureBox(pos.x(), pos.y(), size.x(), size.y(),
		0, 0, background_tex_.width(), background_tex_.height(), background_tex_, Color::white, 0,
		Vec2f(1, 1), size / 2);
}
void StageSelect::shift()
{
	if (env.isPushButton(Mouse::LEFT)) {
		bgm_.stop();
		Scene::create<GameMain>(new GameMain());
	}
}
void StageSelect::loadRes() {
	std::string texturepass = "res/Texture/UI2/";
	window_tex_ = Texture(texturepass + "Window_UI.png");
	background_tex_ = Texture(texturepass + "StageSelect_UI.png");
	mouse_tex_ = Texture(texturepass + "MouseP_UI.png");
	scroll_tex_ = Texture(texturepass + "Scroll_UI.png");
	scrollbar_tex_ = Texture(texturepass + "ScrollBar_UI.png");
	dodai_tex_ = Texture(texturepass + "dodai.png");

	std::string bgmpass = "res/Media/BGM/StageSelect.wav";
	bgm_ = Media(bgmpass);

	std::string sepass = "res/Media/SE/System/System/";
	mouse_se_ = Media(sepass + "MovingCursol.wav");
	start_se_ = Media(sepass + "GameStart.wav");
	cyancel_se_ = Media(sepass + "Cansel.wav");
	select_se_ = Media(sepass + "Select.wav");
}
void StageSelect::drawCenterBox(Vec2f pos, Vec2f size, Color color) {
	drawFillBox(pos.x(), pos.y(), size.x(), size.y(), color, 0, Vec2f(1, 1), size / 2);
}
void StageSelect::drawCenterTexture(Vec2f pos, Vec2f size, Texture image) {
	drawTextureBox(pos.x(), pos.y(), size.x(), size.y(), 0, 0, image.width(), image.height(), image, Color::white,
		0, Vec2f(1, 1), size / 2);
}