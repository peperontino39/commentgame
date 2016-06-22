#include "CommentWindow.h"

#include "../CommentINIReader/CommentINIReader.h"

Vec2f CommentWindow::pos;
Vec2f CommentWindow::size;

Vec2f CommentWindow::pPos;
Vec2f CommentWindow::pSize;

bool CommentWindow::isChange( )
{
    return CommentWindow::pos != CommentWindow::pPos || CommentWindow::size != CommentWindow::pSize;
}

void CommentWindow::update( )
{
    CommentWindow::pPos = CommentWindow::pos;
    CommentWindow::pSize = CommentWindow::size;
}

void CommentWindow::clear( )
{
    CommentINIReader INIData( "src/Game/Comment/CommentWindow/CommentWindow.ini" );

    CommentWindow::pos.x( ) = std::stof( INIData ["CommentWindow"] ["posX"] );
    CommentWindow::pos.y( ) = std::stof( INIData ["CommentWindow"] ["posY"] );
    CommentWindow::size.x( ) = std::stof( INIData ["CommentWindow"] ["sizeX"] );
    CommentWindow::size.y( ) = std::stof( INIData ["CommentWindow"] ["sizeY"] );

    CommentWindow::update( );
}