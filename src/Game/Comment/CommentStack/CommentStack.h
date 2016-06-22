#pragma once

#include "../CommentFlowString/CommentFlowString.h"

#include <memory>

class CommentStack
{
    struct _m_CommentStack;
    std::shared_ptr<_m_CommentStack> member;
public:
    CommentStack( );
public:
    void update( );
    size_t regist( );
private:
    size_t interrupt( );
    bool allTheSame( );
};