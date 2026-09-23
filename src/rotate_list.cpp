#include <string>
#include <vector>


#include "node.hpp"


Node* rotateRight(Node* head, int k) {
       int len=1;
       
       if (head==nullptr || head->next==nullptr ){
        return head;
       }
       Node* temp=head;
       while(temp->next!=nullptr){
          temp=temp->next;
          len++;
       } 
       
       int rotate=k%len;
       if(rotate==0){
        return head;
       }
       //make cycle
       temp->next=head;
       Node* newTail=head;
       for (int i = 0; i < len-rotate-1; i++) {
        newTail=newTail->next;
       }
       Node * newHead=newTail->next;
       newTail->next=nullptr;
       return newHead;

}
