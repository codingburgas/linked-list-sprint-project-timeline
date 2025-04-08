#ifndef EVENTS_H
#define EVENTS_H

#include <string>
#include <memory>

struct Node {
    std::string data;
    std::shared_ptr<Node> next;
    Node(const std::string& data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    void append(const std::string& data);
    void print() const;
    void insert(const std::string& data);
    void sort();
    std::shared_ptr<Node> getHead() const; // Declaration inside the class

private:
    std::shared_ptr<Node> head;
    static bool compareDates(const std::string& date1, const std::string& date2);
};

#endif // EVENTS_H