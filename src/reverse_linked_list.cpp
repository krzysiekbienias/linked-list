
#include <string>
#include <vector>
#include "node.hpp"


Node* reverseLinkedList(Node* head) {
    Node* prev=nullptr;
    Node * curr=head;

    while (curr!=nullptr) {
        Node * nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }
    return prev;

}