#include "CommentStructure.hpp"

#include "../CommentCommands/CommentCommands.h"

std::map<std::string, std::map<std::string, std::string>> CommentStructure::INIMap( )
{
    std::map<std::string, std::map<std::string, std::string>> data;
    data [comment];
    data [comment] [CommentCommands::findCommandName( size )] = size;
    data [comment] [CommentCommands::findCommandName( type )] = type;
    data [comment] [CommentCommands::findCommandName( color )] = color;
    return data;
}
