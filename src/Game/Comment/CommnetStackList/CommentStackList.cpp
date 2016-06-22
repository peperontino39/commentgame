#include "CommentStackList.h"
#include <vector>

struct CommentStackList::_m_CommentStackList
{
    std::vector<CommentStack> stackList = std::vector<CommentStack>( 3 );
};

std::shared_ptr<CommentStackList::_m_CommentStackList> CommentStackList::member = std::make_shared<CommentStackList::_m_CommentStackList>( );

size_t CommentStackList::regist( const CommentFlowString::Type type )
{
    return member->stackList.at( static_cast< size_t >( type ) ).regist( );
}

void CommentStackList::update( )
{
    for ( auto& obj : member->stackList )
    {
        obj.update( );
    }
}

void CommentStackList::clear( )
{
    member->stackList.clear( );
    member->stackList = std::vector<CommentStack>( 3 );
}
