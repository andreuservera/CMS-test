#pragma once

#include <filesystem>
#include "game.h"
#include <vector>

class GameLibrary
{
public:
    GameLibrary();
    void Run();

private:
    void HandleUserInput();

    bool CreateLibrary(std::string name);
    void AddGame(std::string library_name, Game game);
    void ListGames();

    bool ReadLibrary(std::filesystem::path rootDir);
    std::filesystem::path rootDir_;

    std::vector<Game> games_;
};