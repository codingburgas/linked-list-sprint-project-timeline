#ifndef EVENTS_H
#define EVENTS_H

#include <string>
#include <memory>

struct Node {
    std::string data;
    std::string extendedInfo;
    std::shared_ptr<Node> next;
    Node(const std::string& data, const std::string& extendedInfo = "") : data(data), extendedInfo(extendedInfo), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    void append(const std::string& data, const std::string& extendedInfo = "");
    void print() const;
    void insert(const std::string& data);
    void sort();
    void remove(const std::string& data);
    void edit(const std::string& oldData, const std::string& newData);
    void select(const std::string& data);
    std::shared_ptr<Node> getHead() const;

private:
    std::shared_ptr<Node> head;
    static bool compareDates(const std::string& date1, const std::string& date2);
};

#endif // EVENTS_H