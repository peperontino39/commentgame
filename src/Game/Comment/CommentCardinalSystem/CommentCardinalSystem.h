#pragma once

#include <memory>

class CommentCardinalSystem
{
    struct _m_CommentCardinalSystem;
    static std::shared_ptr<_m_CommentCardinalSystem> member;
private:
    CommentCardinalSystem( ) { /*nothing*/ }
public:
    static void setup( );
    static void clear( );
    static void update( );
};