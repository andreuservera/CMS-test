#pragma once

#include <filesystem>
#include <iostream>
#include <chrono>
#include <unordered_map>
#include <any>

class Game
{
public:
    Game();
    void Create(std::string name);
    void Update();
    void Parse(std::filesystem::path library_path);
    void PrintAttributes();

    void Play();

    void SetName(std::string name);
    std::string GetName();

private:
    void InitializeXML();

    std::string name_;
    std::filesystem::path library_path_;
    double time_played_;
};