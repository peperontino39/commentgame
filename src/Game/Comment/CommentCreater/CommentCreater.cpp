#include "CommentCreater.h"

#include "../CommentTask/CommentTask.h"
#include "../CommentCommands/CommentCommands.h"

#include <string>
#include <map>

void CommentCreater::comment( const std::string& behavior )
{
    CommentTask::create( behavior );
}

void CommentCreater::comment( const std::string& comment, const std::string& commandA, const std::string& commandB, const std::string& commandC )
{
    CommentStructure data;
    data.comment = comment;

    std::map<std::string, std::string*> map =
    {
        { "Type", &data.type },
        { "Size", &data.size },
        { "Color", &data.color }
    };

    std::string* temp;
    temp = map [CommentCommands::findCommandName( commandA )];
    if ( temp != nullptr ) *temp = commandA;
    temp = map [CommentCommands::findCommandName( commandB )];
    if ( temp != nullptr ) *temp = commandB;
    temp = map [CommentCommands::findCommandName( commandC )];
    if ( temp != nullptr ) *temp = commandC;

    CommentTask::create( data );
}
