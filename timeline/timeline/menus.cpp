#include "manager.h"
#include "../timeline_static_library/namespace_utility.h"
#include <iostream>
#include <fstream>
#include <string>

void mainMenu() {
    std::ifstream file("./assets/main_menu.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
}