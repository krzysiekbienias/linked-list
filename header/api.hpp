# pragma once

#include "node.hpp"

class LinkedList {
private:
    Node* m_head=nullptr;
    int m_length=0;

public:
    LinkedList();
    explicit LinkedList(int val);

    ~LinkedList();
    void append(int val);

    bool isEmpty();

    int getSize();



    //not allowed on copying alternative add copy cinstrukctor --> later
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

};

