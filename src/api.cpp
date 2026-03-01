#include "node.hpp"
#include "api.hpp"



//equivalent constructor

// LinkedList::LinkedList(int val) {
//     Node* newNode=new Node(val);
//     head=newNode;
//     length=1;
// }


LinkedList::LinkedList(int val):head(new Node(val)),length(1) {}

LinkedList::~LinkedList() {
    Node* temp=head;
    while (head) {
        head=head->next;
        delete temp;
        temp=head;
    }
}
