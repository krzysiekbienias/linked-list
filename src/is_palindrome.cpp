#include <string>
#include <vector>
#include "node.hpp"

bool isPalindrome(Node* head) {
    std::vector<int> vec;
    //empty and single node list is palindrome;
    if (head==nullptr || head->next==nullptr) return true;
    Node* temp =head;
    while (temp!=nullptr) {
        vec.push_back(temp->m_val);
        temp=temp->next;
    }
    //bring back pointe to the beginning
    temp=head;
    while (temp!=nullptr) {
        if (vec.empty() || temp->m_val!=vec.back()) return false;
        vec.pop_back();
        temp=temp->next;
    }
    return true;
}