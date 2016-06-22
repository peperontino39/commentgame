#pragma once

#include <memory>
#include <string>
#include <map>

class CommentStructure;

class CommentINIReader
{
    struct _m_CommentINIReader;
    std::shared_ptr<_m_CommentINIReader> member;
public:
    CommentINIReader( );
    CommentINIReader( const std::string& filePath );
    void read( const std::string& filePath );
    CommentStructure randomComment( );
    std::map<std::string, std::string>& findField( const std::string& field );
    std::map<std::string, std::string>& operator[]( const std::string& field ) { return findField( field ); }
    std::map<std::string, std::map<std::string, std::string>>& data( );
private:
    static std::string _spaceErase( std::string lineStr );
    static std::string _commentErase( std::string lineStr );
    static bool _findField( std::string lineStr );
    static bool _findValue( std::string lineStr );
    static std::string _fieldName( std::string lineStr );
    static std::pair<std::string, std::string> _fieldValue( std::string lineStr );
private:
    friend class CommentINIWriter;
};