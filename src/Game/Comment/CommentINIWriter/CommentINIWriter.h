#pragma once

#include <memory>
#include <string>
#include <map>

class CommentINIWriter
{
public:
    static void write( const std::string & filePath, std::map<std::string, std::map<std::string, std::string>> data );
private:
    static std::string _fieldWrite( const std::string& field );
    static bool _grammarValueCheck( const std::pair < std::string, std::string >& value );
    static std::string _valuesWrite( const std::pair < std::string, std::string >& values );
};