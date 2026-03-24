#include <string>
#include <vector>


#include "node.hpp"

Node *insertAtIndex(Node *head, int n, int i) {
    if (head == nullptr) {
        head = new Node(n);
        return head;
    }
    if (i == 0) {
        Node *newNode = new Node(n);
        newNode->next = head;
        return newNode;
    }
    int pos = 0;
    Node *runner = head;
    while (runner->next != nullptr and pos < i - 1) {
        runner = runner->next;
        pos++;
    }
    Node *newNode = new Node(n);
    newNode->next = runner->next;
    runner->next = newNode;
    return head;
}