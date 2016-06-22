#include "CommentStack.h"
#include "../CommentOption/CommentOption.h"
#include "../../../lib/random.hpp"
#include <chrono>

struct CommentStack::_m_CommentStack
{
    std::vector<std::pair<bool, size_t>> stack = std::vector<std::pair<bool, size_t>>( 10, { false, 0 } );
};

CommentStack::CommentStack( )
{
    member = std::make_shared<CommentStack::_m_CommentStack>( );
}

void CommentStack::update( )
{
    for ( auto& obj : member->stack )
    {
        if ( obj.second == 0 ) continue;
        if ( CommentOption::eraseCount / 2.0f < CommentOption::frameCounter - obj.second )
        {
            obj = { false, 0 };
        }
    }
}

size_t CommentStack::regist( )
{
    for ( size_t i = 0; i < member->stack.size( ); ++i )
    {
        if ( member->stack.at( i ).first == false )
        {
            member->stack.at( i ) = { true, CommentOption::frameCounter };
            return i;
        }
    }
    return interrupt( );
}

//  �ǂ��ɂ��R�����g��z�u�ł��Ȃ��ꍇ�A�����I�ɃR�����g��z�u���܂��B
size_t CommentStack::interrupt( )
{
    size_t min = member->stack.begin( )->second; //  ��ԏ�������������B
    size_t arrayNum = 0;                         //  ���������������Ă���z��ԍ�������B

    //  ��ԏ��������Ԕz�u���̂�T���B
    for ( size_t i = 1; i < member->stack.size( ); ++i )
    {
        if ( member->stack.at( i ).second < min )
        {
            min = member->stack.at( i ).second;
            arrayNum = i;
        }
    }

    if ( allTheSame( ) )   //  �S�Ă������z�u���ԂȂ�i�C���M�����[�j
    {
        //  �C���M�����[�̏ꍇ�A�����_���ȏꏊ�ɔz�u���܂��B
        Random rander;
        rander.setSeed( std::chrono::system_clock::now( ).time_since_epoch( ).count( ) );
        arrayNum = rander( static_cast< int >( member->stack.size( ) ) );
        member->stack.at( arrayNum ).second = CommentOption::frameCounter;
    }
    else                //  �ʏ폈�� ��ԏ������z�u���Ԃ̏ꏊ�ɔz�u���܂��B
    {
        member->stack.at( arrayNum ).second = CommentOption::frameCounter;
    }

    return arrayNum;
}

bool CommentStack::allTheSame( )
{
    bool allTheSame = true;
    for ( size_t i = 1; i < member->stack.size( ); ++i )
    {
        if ( member->stack.at( i ).second != member->stack.begin( )->second )
        {
            allTheSame = false;
            break;
        }
    }
    return allTheSame;
}