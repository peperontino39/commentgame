#pragma once
#include "../AppEnv.h"
#include"../Easing/easing.h"
#include "../Taxture/Taxtures.h"
class Icon {
	
public:
	Icon::Icon(){}
	Icon::Icon(const Vec2f pos,const Vec2f size, const Vec2f cutpos, const Vec2f cutsize,const Texture image) {
		pos_ = pos;
		size_ = size;
		cutpos_ = cutpos;
		cutsize_ = cutsize;
		scale_ = Vec2f(1, 1);
		image_ = image;
		t_ = 0.0f;
	}
	void draw();
	void update(const bool select);
	Vec2f getpos() {
		return pos_;
	}
	Vec2f getsize() {
		return size_;
	}
private:
	void scaleChange(const bool select);
	Vec2f pos_;
	Vec2f size_;
	Vec2f cutpos_;
	Vec2f cutsize_;
	Vec2f scale_;
	Texture image_;
	float t_;
	//Texture image_;
};