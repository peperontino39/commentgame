#include "CommentINIWriter.h"

#include "../CommentINIReader/CommentINIReader.h"

#include <fstream>

void CommentINIWriter::write( const std::string & filePath, std::map<std::string, std::map<std::string, std::string>> data )
{
    std::fstream output = std::fstream( filePath, std::ios::out );

    if ( output.is_open( ) )
    {
        std::map<std::string, std::map<std::string, std::string>>::iterator fieldItr;
        for ( fieldItr = data.begin( ); fieldItr != data.end( ); fieldItr++ )
        {
            output << _fieldWrite( fieldItr->first ) << std::endl;

            std::map<std::string, std::string>::iterator valueItr;
            for ( valueItr = fieldItr->second.begin( ); valueItr != fieldItr->second.end( ); valueItr++ )
            {
                if ( _grammarValueCheck( *valueItr ) )
                {
                    output << _valuesWrite( std::pair<std::string, std::string>( valueItr->first, valueItr->second ) ) << std::endl;
                }
            }
        }
        output << std::endl;
    }
    else
    {
        throw( !"Exception : CommentINIWriter ~File is not found~\n" );
    }
    return;
}

std::string CommentINIWriter::_fieldWrite( const std::string & field )
{
    return '[' + field + "]";
}

bool CommentINIWriter::_grammarValueCheck( const std::pair<std::string, std::string>& value )
{
    return value.first != "" && value.second != "";
}

std::string CommentINIWriter::_valuesWrite( const std::pair<std::string, std::string>& values )
{
    return values.first + " = " + values.second;
}

