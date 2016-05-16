#pragma once

#include "../AppEnv.h"
#include "../Object/MoveObject.h"
#include "../Taxture/Taxtures.h"
enum BlockType {
	NON,
	WHITEBLOCK, //���u���b�N
	BLACKBLOCK, //���u���b�N�i�ǃu���b�N�j
	GRASS,      //���u���b�N
	SAND,       //���u���b�N
	THORN,      //�g�Q
	SWITCH,     //�X�C�b�`
	RIFUTO,     //���t�g
	MOVEBLOCK,  //��������u���b�N
	MAGMA,      //�}�O�}
	RENGA,      //�����K
	DUMMY,      //�_�~�[
	LCICLE,     //���
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