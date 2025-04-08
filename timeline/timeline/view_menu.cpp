#define NOMINMAX // Add this line before including Windows headers
#include "../timeline_static_library/namespace_utility.h"
#include "events.h" // Include the header file for LinkedList
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream> // Include this header for std::istringstream

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
        std::string data, extendedInfo;
        std::istringstream iss(line);
        std::getline(iss, data, '|'); // Use '|' as a delimiter
        std::getline(iss, extendedInfo);
        list.append(data, extendedInfo);
    }
}

void saveTimeline(const std::string& filename, const LinkedList& list) {
    std::ofstream file(filename);
    std::shared_ptr<Node> temp = list.getHead(); // Use the getter method
    while (temp) {
        file << temp->data << "|" << temp->extendedInfo << std::endl; // Save extended information
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
    std::cout << "                              2: Add Event" << '\n';
    std::cout << "                              3: Delete Event" << '\n';
    std::cout << "                              4: Edit Event" << '\n';
    std::cout << "                              5: Go Back" << '\n';

    while (true) {
        if (std::cin >> *view_menu_screen && (*view_menu_screen == 1 || *view_menu_screen == 2 || *view_menu_screen == 3 || *view_menu_screen == 4 || *view_menu_screen == 5)) {
            break;
        }
        else {
            std::cout << "Invalid input." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::string newEvent; // Declare outside the switch statement
    std::string eventToDelete; // Declare outside the switch statement
    std::string oldEvent; // Declare outside the switch statement
    std::string updatedEvent; // Declare outside the switch statement
    std::string eventToSelect; // Declare outside the switch statement

    switch (*view_menu_screen)
    {
    case 1:
        std::cin.ignore(); // Clear the newline character from the input buffer
        std::cout << "Enter the event to select (format: YYYY-MM-DD Event Description): ";
        std::getline(std::cin, eventToSelect);
        timelineList.select(eventToSelect);
        saveTimeline("./assets/timeline.txt", timelineList);
        delete view_menu_screen;
        utility::scene.current_scene = utility::scene.menu;
        break;

    case 2:
        std::cin.ignore(); // Clear the newline character from the input buffer
        std::cout << "Enter the new event (format: YYYY-MM-DD Event Description): ";
        std::getline(std::cin, newEvent);
        timelineList.insert(newEvent);
        saveTimeline("./assets/timeline.txt", timelineList);
        delete view_menu_screen;
        utility::scene.current_scene = utility::scene.menu;
        break;

    case 3:
        std::cin.ignore(); // Clear the newline character from the input buffer
        std::cout << "Enter the event to delete (format: YYYY-MM-DD Event Description): ";
        std::getline(std::cin, eventToDelete);
        timelineList.remove(eventToDelete);
        saveTimeline("./assets/timeline.txt", timelineList);
        delete view_menu_screen;
        utility::scene.current_scene = utility::scene.menu;
        break;

    case 4:
        std::cin.ignore(); // Clear the newline character from the input buffer
        std::cout << "Enter the event to edit (format: YYYY-MM-DD Event Description): ";
        std::getline(std::cin, oldEvent);
        std::cout << "Enter the updated event (format: YYYY-MM-DD Event Description): ";
        std::getline(std::cin, updatedEvent);
        timelineList.edit(oldEvent, updatedEvent);
        saveTimeline("./assets/timeline.txt", timelineList);
        delete view_menu_screen;
        utility::scene.current_scene = utility::scene.menu;
        break;

    case 5:
        delete view_menu_screen;
        utility::scene.current_scene = utility::scene.menu;
        break;
    }
}