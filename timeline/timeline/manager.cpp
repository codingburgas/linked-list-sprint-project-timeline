#include <iostream>
#include "manager.h"
#include "../timeline_static_library/namespace_utility.h"

void scene_manager()
{
	int screen;
	while (utility::exit == false) {
	switch (utility::scene.current_scene)
	{
	case utility::scene.menu:
		clear();
		main_menu();
		std::cin >> screen;
		if (screen == 1)
		{
			utility::scene.current_scene = utility::scene.view;
		}
		else if (screen == 2)
		{
			utility::scene.current_scene = utility::scene.edit;
		}
		break;
	case utility::scene.view:
		clear();
		deleteThisTestToo();
		std::cin >> screen;
		if (screen == 1)
		{
			utility::scene.current_scene = utility::scene.menu;
		}

		break;
	case utility::scene.edit:
		clear();
		deleteThisTestAlso();
		std::cin >> screen;
		if (screen == 1)
		{
			utility::scene.current_scene = utility::scene.menu;
		}
		break;


	}
};
}