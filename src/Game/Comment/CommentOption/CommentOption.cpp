#include "CommentOption.h"

#include "../CommentINIReader/CommentINIReader.h"

size_t CommentOption::lines;
int CommentOption::eraseCount;
size_t CommentOption::frameCounter;

void CommentOption::update( )
{
    CommentOption::frameCounter += 1;
}

void CommentOption::clear( )
{
    CommentINIReader INIData( "src/Game/Comment/CommentOption/CommentOption.ini" );

    CommentOption::lines = std::stoull( INIData ["CommentOption"] ["lines"] );
    CommentOption::eraseCount = std::stoi( INIData ["CommentOption"] ["eraseCount"] );
    CommentOption::frameCounter = std::stoull( INIData ["CommentOption"] ["frameCounter"] );
}
