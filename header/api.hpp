# pragma once

#include "node.hpp"

class LinkedList {
private:
    Node* head=nullptr;
    int length=0;

public:
    LinkedList(int val);

    ~LinkedList();
};