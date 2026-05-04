#include "node.hpp"
#include "delete_middle.hpp"

Node* deleteMiddle(Node* head) {
    Node dummy(0);
    dummy.next=head;
    Node* slow=&dummy;
    Node* fast=head;
    while(fast!=nullptr&& fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    //now slow is exatly one before middle
    slow->next=slow->next->next;
    return dummy.next;

}
