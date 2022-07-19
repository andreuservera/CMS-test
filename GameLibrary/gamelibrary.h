#pragma once

#include <filesystem>
#include <vector>

#include "game.h"
#include "cli.h"

class GameLibrary
{
public:
    GameLibrary();
    void Run();

private:
    bool CreateLibrary(std::string name);
    void AddGame(std::string library_name, Game game);
    void ListGames();

    bool ReadLibrary(std::filesystem::path rootDir);
    std::filesystem::path rootDir_;

    std::vector<Game> games_;

    Cli cli;
};