#pragma once

#include <string>
#include "gamelibrary.h"

class Cli
{
public:
    Cli();

    void Run();
    void PrintHelp();
    void HandleEvents();

private:
    void Process(std::string& line);
    bool exit_;

    GameLibrary game_library_;
};