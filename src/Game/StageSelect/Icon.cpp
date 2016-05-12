#include "Icon.h"

void Icon::update(bool select) {
	scaleChange(select);
}
void Icon::draw() {
	Vec2f drawsize = Vec2f(size_.x()*scale_.x(), size_.y()*scale_.y());
	drawTextureBox(pos_.x(), pos_.y(), drawsize.x(), drawsize.y(), 0, 0, image_.width(), image_.height(),
		image_, Color::white,0,Vec2f(1,1),drawsize/2);
	
	/*drawFillBox(pos_.x(), pos_.y(), drawsize.x(), drawsize.y(), Color::white,
		0,Vec2f(1,1),drawsize/2);*/
}
void Icon::scaleChange(bool select) {
	Vec2f nomalscale = Vec2f(1.f, 1.f);
	Vec2f bigscale = Vec2f(1.1f, 1.1f);
	scale_.x() = Easing::Function::BackInOut(t_, nomalscale.x(), bigscale.x());
	scale_.y() = Easing::Function::BackInOut(t_, nomalscale.y(), bigscale.y());
	float speed = 10.0f;
	if (select) {
		t_ += 1.0f / speed;
		t_ = std::min(t_, 1.0f);
	}
	else {
		t_ -= 1.0f / speed;
		t_ = std::max(t_, 0.f);
	}
}