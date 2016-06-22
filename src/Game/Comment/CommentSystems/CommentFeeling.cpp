
#include "CommentSystems.h"

CommentSystems::CommentFeeling::CommentFeeling( )
{
    member = std::make_shared<CommentSystems::CommentFeeling::_m_CommentFeeling>( );
}

struct CommentSystems::CommentFeeling::_m_CommentFeeling
{
    int joy;
    int surprise;
    int boring;
    int Fun;
public:
};