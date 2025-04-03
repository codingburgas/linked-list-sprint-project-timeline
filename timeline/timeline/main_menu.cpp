#include <iostream>
#include <fstream>
#include <string>

void main_menu()
{
	if (std::ifstream file("./assets/main_menu.txt"); file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			std::cout << line << '\n';
		}
		file.close();
	}
	else
	{
		std::cerr << "Unable to open file" << '\n';
	}

	std::cout << "1: View Timeline" << '\n';
	std::cout << "2: Edit Timeline" << '\n';
	std::cout << "3: Exit" << '\n';
}
