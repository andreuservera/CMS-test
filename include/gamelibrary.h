#pragma once

#include <filesystem>

class GameLibrary
{
public:
    GameLibrary();

private:
    bool ParseLibrary(std::filesystem::path rootDir);
    std::filesystem::path rootDir_;
};