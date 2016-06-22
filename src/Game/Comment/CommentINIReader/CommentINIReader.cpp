#include "CommentINIReader.h"

#include "../CommentStructure/CommentStructure.hpp"

#include "../../AppEnv.h"

#include <fstream>

#include <chrono>

struct CommentINIReader::_m_CommentINIReader
{
    std::map<std::string, std::map<std::string, std::string>> data;
};

CommentINIReader::CommentINIReader( )
{
    member = std::make_shared<CommentINIReader::_m_CommentINIReader>( );
}

CommentINIReader::CommentINIReader( const std::string & filePath )
{
    member = std::make_shared<CommentINIReader::_m_CommentINIReader>( );
    read( filePath );
}

void CommentINIReader::read( const std::string & filePath )
{
    std::fstream input = std::fstream( filePath, std::ios::in );

    if ( input.is_open( ) )
    {
        std::string lineStr;
        std::string fieldBuffer;

        while ( std::getline( input, lineStr ) )
        {
            lineStr = _commentErase( _spaceErase( lineStr ) );
            if ( !lineStr.empty( ) )
            {
                if ( _findField( lineStr ) )
                {
                    fieldBuffer = _fieldName( lineStr );
                    member->data[fieldBuffer];
                }
                else
                {
                    if ( !fieldBuffer.empty( ) )
                    {
                        if ( _findValue( lineStr ) )
                        {
                            auto insert = _fieldValue( lineStr );
                            member->data[fieldBuffer][insert.first] = insert.second;
                        }
                    }
                }
            }
        }
        input.close( );
    }
    else
    {
        throw( !"Exception : CommentINIReader ~File is not found~\n" );
    }
    return;
}

CommentStructure CommentINIReader::randomComment( )
{
    Random rander;
    rander.setSeed( std::chrono::system_clock::now( ).time_since_epoch( ).count( ) );

    CommentStructure data;

    if ( member->data.empty( ) ) return data;

    auto size = static_cast<int>( member->data.size( ) - 1 );
    auto itr = member->data.begin( );
    for ( auto i = 0; i < rander( 0, size ); ++i ) itr++;

    data.comment = itr->first;
    data.size = itr->second["Size"];
    data.type = itr->second["Type"];
    data.color = itr->second["Color"];

    return data;
}

std::map<std::string, std::string>& CommentINIReader::findField( const std::string & field )
{
    return member->data[field];
}

std::map<std::string, std::map<std::string, std::string>>& CommentINIReader::data( )
{
    return member->data;
}

std::string CommentINIReader::_spaceErase( std::string lineStr )
{
    for ( size_t eraseStr = lineStr.find_first_of( " " ); eraseStr != std::string::npos; eraseStr = lineStr.find_first_of( " " ) )
    {
        lineStr.erase( eraseStr, 1 );
    }
    return lineStr;
}

std::string CommentINIReader::_commentErase( std::string lineStr )
{
    size_t beginComment;
    if ( ( beginComment = lineStr.find( ";" ) ) != std::string::npos )
    {
        return lineStr.substr( 0, beginComment );
    }
    return lineStr;
}

bool CommentINIReader::_findField( std::string lineStr )
{
    return lineStr.find( '[' ) != std::string::npos && lineStr.find( ']' ) != std::string::npos;
}

bool CommentINIReader::_findValue( std::string lineStr )
{
    lineStr = lineStr.substr( lineStr.find( '=' ) + 1 );

    if ( lineStr.find( '=' ) == std::string::npos ) return true;
    else return false;
}

std::string CommentINIReader::_fieldName( std::string lineStr )
{
    size_t beginField = lineStr.find( '[' );
    size_t endField = lineStr.find( ']' );
    size_t fieldNum = endField - beginField;
    return lineStr.substr( beginField + 1, fieldNum - 1 );
}

std::pair<std::string, std::string> CommentINIReader::_fieldValue( std::string lineStr )
{
    size_t equal = lineStr.find( '=' );

    std::string first, second;
    first = lineStr.substr( 0, equal );
    second = lineStr.substr( equal + 1 );

    return std::pair<std::string, std::string>( first, second );
}
