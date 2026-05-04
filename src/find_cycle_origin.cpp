#include "node.hpp"
#include "find_cycle_origin.hpp"

Node* findCycleOrigin(Node* head) {
    if (head==nullptr) {
        return nullptr;
    }
    Node * slow=head;
    Node * fast=head;

    while (fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            break;
        }
    }
    slow=head;
    while (slow!=fast){
    slow=slow->next;
    fast=fast->next;
    }
    return slow;
}
