#pragma once

#include <vector>
#include <string>
#include <map>

class CommentStructure
{
public:
    CommentStructure( )
        : comment( "" )
        , size( "" )
        , type( "" )
        , color( "" )
    { }
    std::string comment;
    std::string size;
    std::string type;
    std::string color;

public:
    std::map<std::string, std::map<std::string, std::string>> INIMap( );
};