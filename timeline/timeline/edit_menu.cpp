#include <fstream>
#include <string>
#include "../timeline_static_library/namespace_utility.h"
#include <iostream>

void edit_menu()
{
	std::ifstream file("assets/edit.txt");
	if (!file) {
		std::cerr << "Unable to open file edit.txt" << '\n';
		return;
	}

	std::string line;
	while (std::getline(file, line)) {
		std::cout << line << '\n';
	}
	file.close();

	int* edit_menu_screen = nullptr;
	edit_menu_screen = new int;

	std::cout << "                              1: Edit Event" << '\n';
	std::cout << "                              2: Go Back" << '\n';

	while (true) {
		if (std::cin >> *edit_menu_screen && (*edit_menu_screen == 1 || *edit_menu_screen == 2)) {
			break;
		}
		else {
			std::cout << "Invalid input." << '\n';
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	switch (*edit_menu_screen)
	{
	case 1:
		//Add functionality to edit event
		break;

	case 2:
		delete edit_menu_screen;
		utility::scene.current_scene = utility::scene.menu;
		break;
	}
}
