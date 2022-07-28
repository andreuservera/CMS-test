#pragma once

#include <string>
#include <wordexp.h>

namespace Utils
{

inline std::string GetHomeFolder()
{
    wordexp_t p;
    char** w;

    wordexp("$HOME" , &p, 0 );
    w = p.we_wordv;
    std::string result = *w;

    wordfree( &p );

    std::cout << "Home folder: "<< result << "\n";
    return result;
}

}