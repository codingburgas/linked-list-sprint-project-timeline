#include "../timeline_static_library/namespace_utility.h"
#include <iostream>
#include <fstream>
#include <string>

void view_menu()
{
	 

    std::ifstream file("./assets/view.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << '\n';
        }
        file.close();
    }
    else {
        std::cout << "Unable to open file." << '\n';
    }

    int* view_menu_screen = nullptr;
    view_menu_screen = new int;

    std::cout << std::endl;

    std::cout << "                              1: Select Event" << '\n';
    std::cout << "                              2: Go Back" << '\n';

    while (true) {
        if (std::cin >> *view_menu_screen && (*view_menu_screen == 1 || *view_menu_screen == 2)) {
            break;
        } else {
            std::cout << "Invalid input." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    switch (*view_menu_screen)
    {
        case 1:
            // Add functionality to select event
            break;

        case 2:
            delete view_menu_screen;
            utility::scene.current_scene = utility::scene.menu;
            break;
    }

    
   
}
