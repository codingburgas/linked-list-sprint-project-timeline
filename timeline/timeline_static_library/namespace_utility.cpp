#include "namespace_utility.h"
#include <iostream>

namespace utility
{
	bool exit = false;
	struct_scene scene;

    void clear()
    {
#if defined(_WIN32) || defined(_WIN64)
        std::system("cls");
#else
        std::system("clear");
#endif
    }
} // namespace exit_key