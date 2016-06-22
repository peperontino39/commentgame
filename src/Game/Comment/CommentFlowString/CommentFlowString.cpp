#include "CommentFlowString.h"
#include "../CommentOption/CommentOption.h"
#include "../CommentWindow/CommentWindow.h"
#include "../CommnetStackList/CommentStackList.h"

struct CommentFlowString::_m_CommentFlowString
{
    int eraseCount;
    size_t spawnFrame;
    Vec2f pos;
    Type type;
    Size size;
    Color col;
    std::string comment;
};

CommentFlowString::CommentFlowString( const std::string& comment, const CommentFlowString::Size size, const CommentFlowString::Type type, const Color& col )
{
    member = std::make_shared<CommentFlowString::_m_CommentFlowString>( );

    member->eraseCount = CommentOption::eraseCount;
    member->spawnFrame = CommentOption::frameCounter;
    member->pos.x( ) = CommentWindow::size.x( );
    member->pos.y( ) = 0.0f;
    member->type = type;
    member->size = size;
    member->col = col;
    member->comment = comment;

    regist( );
}

void CommentFlowString::regist( )
{
    double commentHeight = CommentWindow::size.y( ) / CommentOption::lines;
    switch ( member->type )
    {
    case CommentFlowString::Type::MIDDLE:
        member->pos.y( ) = CommentWindow::size.y( ) - commentHeight - ( commentHeight * CommentStackList::regist( member->type ) );
        break;
    case CommentFlowString::Type::TOP:
        member->pos.y( ) = CommentWindow::size.y( ) - commentHeight - ( commentHeight * CommentStackList::regist( member->type ) );
        break;
    case CommentFlowString::Type::BOTTOM:
        member->pos.y( ) = +( commentHeight * CommentStackList::regist( member->type ) );
        break;
    default:
        break;
    }
}

void CommentFlowString::draw( std::vector<Font>& font )
{
    size_t access = static_cast< size_t >( member->size );
    switch ( member->type )
    {
    case CommentFlowString::Type::MIDDLE:
        member->pos.x( ) = CommentWindow::size.x( ) - ( font.at( access ).drawSize( member->comment ).x( ) + CommentWindow::size.x( ) ) / CommentOption::eraseCount * ( CommentOption::frameCounter - member->spawnFrame );
        font.at( access ).draw( member->comment, member->pos, member->col );
        break;
    case CommentFlowString::Type::TOP:
        member->pos.x( ) = ( CommentWindow::size.x( ) - font.at( access ).drawSize( member->comment ).x( ) ) / 2.0f;
        font.at( access ).draw( member->comment, member->pos, member->col );
        break;
    case CommentFlowString::Type::BOTTOM:
        member->pos.x( ) = ( CommentWindow::size.x( ) - font.at( access ).drawSize( member->comment ).x( ) ) / 2.0f;
        font.at( access ).draw( member->comment, member->pos, member->col );
        break;
    default:
        break;
    }
}

void CommentFlowString::update( )
{
    member->eraseCount -= 1;
}

bool CommentFlowString::isActive( )
{
    return 0 <= member->eraseCount ? true : false;
}