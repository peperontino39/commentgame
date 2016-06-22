#pragma once

# include "../CommentStack/CommentStack.h"

#include <memory>
#include <vector>

class CommentStackList
{
    struct _m_CommentStackList;
    static std::shared_ptr<_m_CommentStackList> member;
public:
    static size_t regist( const CommentFlowString::Type type );
    static void update( );
    static void clear( );
};