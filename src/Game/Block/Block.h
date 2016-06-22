#pragma once

#include "../AppEnv.h"
#include "../Object/MoveObject.h"
#include "../Taxture/Taxtures.h"
#include "../Share/Utility/Utility.h"

enum BlockType {
	NON,
	WHITEBLOCK, //���u���b�N             1
	BLACKBLOCK, //���u���b�N�i�ǃu���b�N�j2
	GRASS,      //���u���b�N             3
	SAND,       //���u���b�N				4
	THORN,      //�g�Q					5
	SWITCH,     //�X�C�b�`				6
	RIFUTO,     //���t�g					7	
	MOVEBLOCK,  //��������u���b�N		8
	MAGMA,      //�}�O�}					9
	RENGA,      //�����K					10
	DUMMY,      //�_�~�[					11
	LCICLE,     //���					12
	CAVE,		//���A					13
	DROP,		//��						14
	CHECKPOINT,	//�`�F�b�N�|�C���g		15
	GOAL		//�S�[��					16
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
	virtual bool isBreak();						//���邩�ۂ�
	virtual bool BreakClear() { return true; };	//�����邩�ۂ�
	virtual void Break() {};					//��ꂽ���̏���
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