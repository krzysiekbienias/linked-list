#include "node.hpp" 

Node* removeElements(Node* head, int val) {
    if (head ==nullptr) {
        return nullptr;
    }
    Node dummy = Node(0);
    dummy.next=head;
    Node* runner=&dummy;
    while (runner!=nullptr && runner->next!=nullptr) {
        if (runner->next->m_val==val) {
            runner->next=runner->next->next;
        }
        else {
            runner=runner->next;
        }
    }
    return dummy.next;  
}
