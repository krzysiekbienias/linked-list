#include <string>
#include <vector>
#include <unordered_map>
#include "node.hpp"


Node* deleteDuplicatesUnsorted(Node* head) {
    std::unordered_map<int,int> counts;
    Node* current=head;
    while (current!=nullptr) {
        counts[current->m_val]++;
        current=current->next;
    }
    Node dummy=Node(0);
    Node *dummyPtr=&dummy;
    dummyPtr->next=head; //put dummy before head
    current=head;//bring current back on the head
    Node* prev=dummyPtr;
    while (current!=nullptr) {
        if (counts[current->m_val]>1) {
            Node* toDelete=current;
            prev->next=current->next;
            delete toDelete;
            current=prev->next;
        }
        else {
            //⚠️ Order matters
            prev=current; // 🤓the same effect like prev=prev->next
            current=current->next;
        }
    }
    return dummy.next;
}