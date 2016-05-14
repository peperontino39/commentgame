#pragma once

#include "../AppEnv.h"
#include "../Object/MoveObject.h"
#include "../Taxture/Taxtures.h"
enum BlockType {
	NON,
	WHITEBLOCK, //白ブロック
	BLACKBLOCK, //黒ブロック（壁ブロック）
	GRASS,      //草ブロック
	SAND,       //砂ブロック
	THORN,      //トゲ
	SWITCH,     //スイッチ
	RIFUTO,     //リフト
	MOVEBLOCK,  //動かせるブロック
	MAGMA,      //マグマ
	RENGA,      //レンガ
	DUMMY,      //ダミー
	LCICLE,     //つらら
};


class BlockBase : public MoveObject
{
public:
	BlockBase(Vec2f _pos, Vec2f _size) :
		MoveObject(_pos, _size) 
	{
		up_block = true;
		down_block = true;
		left_block = true;
		right_block = true;
	}
	virtual Vec2f collision(Vec2f,Vec2f, Vec2f);
	virtual void update() override;
	virtual void draw() override;
	virtual bool is_Object() { return false; };
	virtual void push(Vec2f, Vec2f, Vec2f) {};
	virtual bool isBreak();
	virtual void Break();
	virtual bool isBreakfunc() { return true; };


	bool up_block;
	bool down_block;
	bool left_block;
	bool right_block;
	
	Vec2f getPos();
	Vec2f getSize();
	Vec2f getVec();

};