#include "../timeline_static_library/namespace_utility.h"
#include <iostream>

void view_menu()
{
	int* view_menu_screen = nullptr;
	view_menu_screen = new int;

	std::cout << "1: Select Event" << '\n';
	std::cout << "2: Go Back" << '\n';

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
			//Add functionality to select event
			break;

		case 2:
			delete view_menu_screen;
			utility::scene.current_scene = utility::scene.menu;
			break;
	}
}
