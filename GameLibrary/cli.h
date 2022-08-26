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
    void ParseCliInput(std::string& input, std::string& cmd, std::string& arg);
    bool exit_;

    GameLibrary game_library_;
};