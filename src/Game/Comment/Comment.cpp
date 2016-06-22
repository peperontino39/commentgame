#include "Comment.h"
#include "CommentTask/CommentTask.h"
#include "CommnetStackList/CommentStackList.h"
#include "CommentOption/CommentOption.h"
#include "CommentWindow/CommentWindow.h"
#include "CommentCardinalSystem/CommentCardinalSystem.h"

Comment::Comment( )
{
    clear( );

    setup( );
}

Comment::~Comment( )
{
    clear( );
}

void Comment::update( )
{
    CommentTask::update( );

    CommentCardinalSystem::update( );

    CommentStackList::update( );

    CommentOption::update( );

    CommentWindow::update( );
}

void Comment::draw( )
{
    CommentTask::draw( );
}

void Comment::setup( )
{
    CommentTask::setup( );

    CommentCardinalSystem::setup( );
}

void Comment::clear( )
{
    CommentTask::clear( );

    CommentCardinalSystem::clear( );

    CommentStackList::clear( );

    CommentOption::clear( );

    CommentWindow::clear( );
}
