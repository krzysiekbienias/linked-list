#include <string>
#include <vector>
#include "node.hpp"

Node* addTwoNumbers(Node* l1, Node*l2) {
    Node* res=new Node(0);
    Node* temp=res;
    int carry=0;
    int sum =0;

    int digit=0;
    while (l1!=nullptr || l2 !=nullptr) {
        int x=0;
        int y=0;
        if (l1!=nullptr) {
            x=l1->m_val;
            l1=l1->next;
        }
        if (l2!=nullptr) {
            y=l2->m_val;
            l2=l2->next;
        }
        sum=x+y+carry;
        carry=sum/10;   //5+9=14 14/10=1
        digit=sum%10;
        temp->next=new Node(digit);
        temp=temp->next;
    }
    if (carry>0) {
        temp->next  =new Node(carry);
    }
    return res->next;
}




