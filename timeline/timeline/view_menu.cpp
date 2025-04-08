#define NOMINMAX // Add this line before including Windows headers
#include "../timeline_static_library/namespace_utility.h"
#include "events.h" // Include the header file for LinkedList
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void loadTimeline(const std::string& filename, LinkedList& list) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        list.append(line);
    }
}

void saveTimeline(const std::string& filename, const LinkedList& list) {
    std::ofstream file(filename);
    std::shared_ptr<Node> temp = list.getHead(); // Use the getter method
    while (temp) {
        file << temp->data << std::endl;
        temp = temp->next;
    }
}

void view_menu()
{
    // Clear the console screen
    clearScreen();

    // Create instances of LinkedList for both files
    LinkedList viewList;
    LinkedList timelineList;

    // Load the data into the linked lists
    loadTimeline("./assets/view.txt", viewList);
    loadTimeline("./assets/timeline.txt", timelineList);

    // Print the contents of the linked lists
    viewList.print();
    std::cout << std::endl;

    timelineList.print();
    std::cout << std::endl;

    int* view_menu_screen = nullptr;
    view_menu_screen = new int;

    std::cout << "                              1: Select Event" << '\n';
    std::cout << "                              2: Go Back" << '\n';
    std::cout << "                              3: Add Event" << '\n';

    while (true) {
        if (std::cin >> *view_menu_screen && (*view_menu_screen == 1 || *view_menu_screen == 2 || *view_menu_screen == 3)) {
            break;
        }
        else {
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

    case 3:
        std::cin.ignore(); // Clear the newline character from the input buffer
        std::string newEvent;
        std::cout << "Enter the new event (format: YYYY-MM-DD Event Description): ";
        std::getline(std::cin, newEvent);
        timelineList.insert(newEvent);
        saveTimeline("./assets/timeline.txt", timelineList);
        delete view_menu_screen;
        utility::scene.current_scene = utility::scene.menu;
        break;
    }
}