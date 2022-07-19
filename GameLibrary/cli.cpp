#include "cli.h"

#include <iostream>

Cli::Cli() : exit_(0)
{
}

void Cli::PrintHelp()
{
    std::cout << std::endl;
    std::cout << "Commands: "<< std::endl;
    std::cout << "\t" << "addgame <gamename>" << std::endl
        << "\t" << "deletegame <gamename>" << std::endl
        << "\t" << "playgame <gamename>" << std::endl
        << "\t" << "list" << std::endl << std::endl;
}

void Cli::HandleEvents()
{
    std::cout << "Type help to list available commands..." << std::endl;

    while (!exit_)
    {
        std::cout << ">>> ";
        std::string line;
        std::getline(std::cin, line);
        Process(line);
    }
}

void Cli::Process(std::string cmd)
{
    if (cmd.compare("exit") == 0)
    {
        exit_ = true;
    }
    else if (cmd.compare("help") == 0)
    {
        PrintHelp();
    }
    else
    {
        std::cout << "Unknown command: " << cmd << std::endl;
    }
}
