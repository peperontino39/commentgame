#include "../CommentCall.h"

//  �R�����g�f�[�^�x�[�X����Q�Ƃ��ăR�����g���o�͂��܂��B
//  �f�[�^�x�[�X�ɑ��݂��Ȃ��ꍇ�́A�f�t�H���g�ݒ�ł̏o�͂ƂȂ�܂��B
void comment( const std::string& behavior ) 
{ 
    CommentCreater::comment( behavior );
}

//  �V�����R�����g�𐶐��ł��܂��B
//  �R�}���h�͏��s���Ȃ̂ŁA�D���ɂ��ł����������B
//  �R�}���h�̎�ނɊւ��܂��ẮAsrc/Comment/CommentCommands.txt���䗗���������B
void comment( const std::string& comment, const std::string& commandA, const std::string& commandB, const std::string& commandC ) 
{ 
    CommentCreater::comment( comment, commandA, commandB, commandC );
}