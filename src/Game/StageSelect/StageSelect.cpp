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
	savemousepos_ = mousepos_;
	nextmousepos_ = getNextMousePos();
	mouset_ = 0.0f;
}
Vec2f StageSelect::getNextMousePos() {
	switch (select_)
	{
	case CARD:
		return card_.getpos();
	case POST:
		return post_.getpos();
	case EXIT:
		return exit_.getpos();
	case STAGE:
		return stagelavel_[selectnum_ - 1].getpos();
	default:
		break;
	}
}
void StageSelect::draw()
{
	drawBackground();
	//drawFillBox(0, 0, 100, 100, Color::green);
	card_.draw();
	post_.draw();
	exit_.draw();
	for (int i = 0;i < stagelavel_.size(); i++) {
		stagelavel_[i].draw();
	}
	drawMousePointer();
}
void StageSelect::drawMousePointer() {
	drawCenterBox(mousepos_, Vec2f(50, 50), Color::gray);
}

void StageSelect::drawBackground() {
	Vec2f pos = Vec2f(-WIDTH / 2, -HEIGHT / 2);
	Vec2f size = Vec2f(WIDTH, HEIGHT);
	drawFillBox(pos.x(), pos.y(), size.x(), size.y(), Color::white);
}
void StageSelect::shift()
{
	if (env.isPushButton(Mouse::LEFT)) {
		Scene::create<GameMain>(new GameMain());
	}
}

void StageSelect::drawCenterBox(Vec2f pos, Vec2f size, Color color) {
	drawFillBox(pos.x(), pos.y(), size.x(), size.y(), color, 0, Vec2f(1, 1), size / 2);
}
void StageSelect::drawCenterTexture(Vec2f pos, Vec2f size, Texture image) {
	drawTextureBox(pos.x(), pos.y(), size.x(), size.y(), 0, 0, image.width(), image.height(), image, Color::white,
		0, Vec2f(1, 1), size / 2);
}