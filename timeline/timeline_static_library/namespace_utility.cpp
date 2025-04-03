#include "namespace_utility.h"
#include <iostream>

namespace utility
{
	bool exit = false;
	struct_scene scene;

	void clear()
	{
		std::cout << "\033[2J\033[1;1H";
	}
} // namespace exit_key