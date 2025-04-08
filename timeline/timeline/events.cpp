#include "events.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iomanip> // Include this header for std::get_time
#include <cstdio>  // Include this header for sscanf_s

void LinkedList::append(const std::string& data, const std::string& extendedInfo) {
    std::shared_ptr<Node> newNode = std::make_shared<Node>(data, extendedInfo);
    if (!head) {
        head = newNode;
    }
    else {
        std::shared_ptr<Node> temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList::print() const {
    std::shared_ptr<Node> temp = head;
    while (temp) {
        std::cout << temp-> data << " " << temp->extendedInfo << std::endl; // Print extended information
        temp = temp->next;
    }
}

void LinkedList::insert(const std::string& data) {
    append(data);
    sort();
}

void LinkedList::sort() {
    if (!head || !head->next) return;

    std::vector<std::shared_ptr<Node>> nodes;
    std::shared_ptr<Node> temp = head;
    while (temp) {
        nodes.push_back(temp);
        temp = temp->next;
    }

    std::sort(nodes.begin(), nodes.end(), [](const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
        return compareDates(a->data, b->data);
        });

    head = nodes[0];
    temp = head;
    for (size_t i = 1; i < nodes.size(); ++i) {
        temp->next = nodes[i];
        temp = temp->next;
    }
    temp->next = nullptr;
}

std::shared_ptr<Node> LinkedList::getHead() const {
    return head;
}

bool LinkedList::compareDates(const std::string& date1, const std::string& date2) {
    auto parseDate = [](const std::string& date) {
        std::tm tm = {};
        sscanf_s(date.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);
        tm.tm_year -= 1900;
        tm.tm_mon -= 1;
        return std::mktime(&tm);
        };

    std::time_t time1 = parseDate(date1);
    std::time_t time2 = parseDate(date2);
    return std::difftime(time1, time2) < 0;
}

void LinkedList::remove(const std::string& data) {
    if (!head) return;

    if (head->data == data) {
        head = head->next;
        return;
    }

    std::shared_ptr<Node> temp = head;
    while (temp->next && temp->next->data != data) {
        temp = temp->next;
    }

    if (temp->next) {
        temp->next = temp->next->next;
    }
}

void LinkedList::edit(const std::string& oldData, const std::string& newData) {
    std::shared_ptr<Node> temp = head;
    while (temp) {
        if (temp->data == oldData) {
            temp->data = newData;
            sort(); // Re-sort the list if the date has changed
            return;
        }
        temp = temp->next;
    }
}

void LinkedList::select(const std::string& data) {
    std::shared_ptr<Node> temp = head;
    while (temp) {
        if (temp->data == data) {
            std::cout << "Event: " << temp->data << std::endl;
            std::cout << "Extended Information: " << temp->extendedInfo << std::endl;
            std::cout << "Enter new extended information: ";
            std::getline(std::cin, temp->extendedInfo);
            return;
        }
        temp = temp->next;
    }
    std::cout << "Event not found." << std::endl;
}