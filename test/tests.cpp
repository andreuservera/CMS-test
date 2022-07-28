#include <gtest/gtest.h>

#include <filesystem>

#include "../GameLibrary/gamelibrary.h"
#include "../utils/utils.h"

TEST(gamelibrary, initialize)
{
    GameLibrary gamelibrary;
    gamelibrary.Initialize();

    std::filesystem::path root_dir = Utils::GetHomeFolder()
                                    + "/"
                                    + "MyGameLibrary";
    bool result = std::filesystem::exists(root_dir);
    
    EXPECT_TRUE(result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}