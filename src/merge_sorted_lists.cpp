#include <string>
#include <vector>


#include "node.hpp"

Node* mergeLinkedLists(Node* headOne, Node* headTwo) {
    Node  dummy=  Node(0);
    Node *curr =&dummy;
    while (headOne!=nullptr && headTwo!=nullptr) {
        if (headOne->m_val<=headTwo->m_val) {
            curr->next=headOne;
            headOne=headOne->next;
        }
        else {
            curr->next=headTwo;
            headTwo=headTwo->next;
        }
        curr=curr->next;

    }
    //sprzatanie resztek 🧹
    if (headOne!=nullptr) {
        curr->next=headOne;
    }
    else {
        curr->next=headTwo;
    }
    return dummy.next;
}