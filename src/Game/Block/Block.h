#pragma once

#include "../AppEnv.h"
#include "../Object/MoveObject.h"
#include "../Taxture/Taxtures.h"
#include "../Share/Utility/Utility.h"

enum BlockType {
	NON,
	WHITEBLOCK, //白ブロック             1
	BLACKBLOCK, //黒ブロック（壁ブロック）2
	GRASS,      //草ブロック             3
	SAND,       //砂ブロック				4
	THORN,      //トゲ					5
	SWITCH,     //スイッチ				6
	RIFUTO,     //リフト					7	
	MOVEBLOCK,  //動かせるブロック		8
	MAGMA,      //マグマ					9
	RENGA,      //レンガ					10
	DUMMY,      //ダミー					11
	LCICLE,     //つらら					12
	CAVE,		//洞窟					13
	DROP,		//雫						14
	CHECKPOINT,	//チェックポイント		15
	GOAL		//ゴール					16
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
	virtual bool isBreak();						//壊れるか否か
	virtual bool BreakClear() { return true; };	//消えるか否か
	virtual void Break() {};					//壊れた時の処理
	virtual bool isHit(Vec2f, Vec2f);
	virtual void checkPoint() {};
	virtual bool isBreakfunc() { return true; };


	bool up_block;
	bool down_block;
	bool left_block;
	bool right_block;
	
	Vec2f getPos();
	Vec2f getSize();
	Vec2f getVec();

};