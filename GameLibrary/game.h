#pragma once

#include <filesystem>
#include <iostream>
#include <chrono>

class Game
{
public:
    Game();
    void Create(std::filesystem::path library_path, std::string name);
    void Update();
    void Parse();

    void Play();

    std::string GetName();

private:
    void InitializeXML();

    std::string name_;
    std::filesystem::path library_path_;
    std::chrono::duration<double> time_played_;
};