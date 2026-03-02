#include <string>
#include <vector>
#include <api.hpp>


Node* removeDuplicatesFromSortedList(Node* head) {
    Node* current=head;
    while (current!=nullptr && current->next!=nullptr) {
        if (current->m_val==current->next->m_val) {
            Node* duplicate=current->next;
            current->next=current->next->next;
            delete duplicate;
        }
        else
            current=current->next;
    }
    return head;

}