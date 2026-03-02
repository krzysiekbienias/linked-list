#include "node.hpp"
#include "api.hpp"



//equivalent constructor

// LinkedList::LinkedList(int val) {
//
//     head=newNode;
//     length=1;
// }

LinkedList::LinkedList():m_head(nullptr),m_length(0) {}
LinkedList::LinkedList(int val):m_head(new Node(val)),m_length(1) {}


LinkedList::~LinkedList() {
    Node* temp=m_head;
    while (m_head) {
        m_head=m_head->next;
        delete temp;
        temp=m_head;
    }
}


void LinkedList::append(int val) {
    Node * newNode= new Node(val);
    if (m_head==nullptr) {
        m_head=newNode;
        m_length=1;
        return;
    }
    Node * current=m_head;
    while (current->next!=nullptr) {
        current=current->next;

    }
    current->next=newNode;
    m_length++;

}

bool LinkedList::isEmpty() {
    return m_length==0;
}

int LinkedList::getSize() {
    return m_length;
}


