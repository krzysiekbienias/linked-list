# pragma once

#include "node.hpp"
#include <ostream>

class LinkedList {
private:
    Node* m_head=nullptr;
    int m_length=0;

public:
    LinkedList();
    explicit LinkedList(int val);

    ~LinkedList();
    Node* getHead()const;

    void append(int val);

    bool isEmpty();

    int getSize();


    friend std::ostream &operator<<(std::ostream &os, const LinkedList &list);


    //not allowed on copying alternatively add copy constructor --> later
    LinkedList(const LinkedList &) = delete;

    LinkedList &operator=(const LinkedList &) = delete;
};

