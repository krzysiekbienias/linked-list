#include <string>
#include <vector>
#include <node.hpp>


Node* middleNode(Node* head) {
    if (head==nullptr) {
        throw std::invalid_argument("List is empty");
    }

    Node* slow=head;
    Node* fast=head;

    while (fast!=nullptr && fast->next!=nullptr) {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}