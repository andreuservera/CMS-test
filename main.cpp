#include <iostream>
#include "GameLibrary/cli.h"

int main(int argc, char *argv[]) {
    std::cout <<    " __  __          _____                        _      _ _                          \n"
                    "|  \\/  |        / ____|                      | |    (_) |                         \n"
                    "| \\  / |_   _  | |  __  __ _ _ __ ___   ___  | |     _| |__  _ __ __ _ _ __ _   _ \n"
                    "| |\\/| | | | | | | |_ |/ _` | '_ ` _ \\ / _ \\ | |    | | '_ \\| '__/ _` | '__| | | |\n"
                    "| |  | | |_| | | |__| | (_| | | | | | |  __/ | |____| | |_) | | | (_| | |  | |_| |\n"
                    "|_|  |_|\\__, |  \\_____|\\__,_|_| |_| |_|\\___| |______|_|_.__/|_|  \\__,_|_|   \\__, |\n"
                    "         __/ |                                                               __/ |\n"
                    "         |___/                                                               |___/\n";

    Cli cli;
    cli.Run();

    return 0;
}
