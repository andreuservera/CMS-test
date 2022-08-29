#pragma once

#include <filesystem>
#include <vector>

#include "game.h"


// User should have a folder to store data in $HOME.
// The name of the folder is MyGameLibrary
// That is, the root dir should be $HOME/MyGameLibrary

class GameLibrary
{
public:
    GameLibrary();
    void Initialize();
    void AddGame(Game game);
    std::vector<Game> GetGames(){ return games_; };
    std::vector<Game>* GetGamesPtr(){ return &games_; }

private:
    std::filesystem::path root_dir_;

    void SetRootDir();
    bool CheckForMainFolder();
    void CreateMainFolder();

    //bool CreateLibrary();
    void ListGames();

    bool ReadLibrary(std::filesystem::path rootDir);

    std::vector<Game> games_;
};