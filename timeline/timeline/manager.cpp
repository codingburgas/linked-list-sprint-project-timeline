#include <iostream>
#include "manager.h"
#include "menus.h"
#include "../timeline_static_library/namespace_utility.h"

void scene_manager()
{
	int* main_menu_screen = nullptr;
	main_menu_screen = new int;
	while (utility::exit == false)
	{
		switch (utility::scene.current_scene)
		{
		case utility::scene.menu:
			utility::clear();

			main_menu();
			while (true) {
				std::cin >> *main_menu_screen;
				if (*main_menu_screen >= 1 && *main_menu_screen <= 3) {
					break;
				}
				else {
					std::cout << "Invalid option" << '\n';
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
			switch (*main_menu_screen)
			{
			case 1:
				utility::scene.current_scene = utility::scene.view;
				break;

			case 2:
				utility::scene.current_scene = utility::scene.edit;
				break;

			case 3:
				utility::scene.current_scene = utility::scene.exit_enum;
				break;
			}
			break;

		case utility::scene.view:
			utility::clear();

			view_menu();
			break;

		case utility::scene.edit:
			utility::clear();

			edit_menu();
			break;

		case utility::scene.exit_enum:
			utility::clear();

			delete main_menu_screen;
			std::cout << "Exiting..." << '\n';
			utility::exit = true;
			break;
		}
	}
}