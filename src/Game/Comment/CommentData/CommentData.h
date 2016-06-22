#pragma once

#include "../CommentStructure/CommentStructure.hpp"

# include <memory>
# include <vector>
# include <string>

class CommentData
{
    struct _m_CommentData;
    std::shared_ptr<_m_CommentData> member;
private:
    CommentData( );
    static CommentData& Geti( );
public:
    static CommentStructure find( const std::string& behavior );
};