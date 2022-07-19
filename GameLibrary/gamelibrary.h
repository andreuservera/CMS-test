#pragma once

#include <filesystem>

class GameLibrary
{
public:
    GameLibrary();
    void Run();

private:
    void HandleUserInput();

    void CreateLibrary(std::filesystem::path name);
    bool CreateLibrary(std::string name);

    bool ReadLibrary(std::filesystem::path rootDir);
    std::filesystem::path rootDir_;
};