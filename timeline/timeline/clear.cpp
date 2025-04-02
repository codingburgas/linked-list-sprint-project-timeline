#include "manager.h"
#include "../timeline_static_library/namespace_utility.h"
#include <iostream>

void clear()
{
    std::cout << "\033[2J\033[1;1H";
}

void deleteThisTest()
{
	std::cout << "This is a test function press 1 to switch" << std::endl;
}

void deleteThisTestToo()
{
	std::cout << "This is a test function also" << std::endl;
}

void deleteThisTestAlso()
{
	std::cout << "This is a test function like the other two" << std::endl;
}