#include "node.hpp"
#include "has_cycle.hpp"

bool hasCycle(Node* head) {
    Node* slow=head;
    Node* fast=head;
    while (fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast) {
            return true;
        }
    }
    
    
    return false;
}

