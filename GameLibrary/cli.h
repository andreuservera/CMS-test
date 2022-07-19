#pragma once

#include <string>

class Cli
{
public:
    Cli();

    void PrintHelp();
    void HandleEvents();

private:
    void Process(std::string cmd);
    bool exit_;
};