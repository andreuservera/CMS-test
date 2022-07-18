#pragma once

#include <filesystem>

class GameLibrary
{
public:
    GameLibrary();
    void Run();

private:
    bool ParseLibrary(std::filesystem::path rootDir);
    std::filesystem::path rootDir_;
};