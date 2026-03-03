#include <string>
#include <vector>
#include "node.hpp"

Node* removeKthNodeFromEnd(Node* head, int k) {
    Node* temp=head;
    int len=0;
    while (temp!=nullptr) {
        len++;
        temp=temp->next;
    }

    //p=n-k+1 ; n=5 k=2 ---> p=5-2+1 so 4th
    temp=head; //reset pointer to the beginning. is allowed ❓
    if (k==len) return head->next;
    int p=len-k-1; //to stop one before we want to remove to perform bypass ❤️
    while (p>0) {
        temp=temp->next;
        p--;
    }
    temp->next=temp->next->next;
    return head;
}