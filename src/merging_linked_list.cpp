#include <string>
#include <vector>


#include "node.hpp"

static int  lenOfList(Node * linkedList) {
    int size=0;
    while (linkedList!=nullptr) {
        linkedList=linkedList->next;
        size++;
    }
    return size;

}

Node* mergingLinkedLists(Node* linkedListOne, Node* linkedListTwo) {
    int len1=lenOfList(linkedListOne);
    int len2=lenOfList(linkedListTwo);
    Node* runnerOne=linkedListOne;
    Node* runnerTwo=linkedListTwo;
    int shift=0;
    int diff=0;
    if (len1>len2) {
        diff=len1-len2;
        while (shift<diff) {
            runnerOne=runnerOne->next;
            shift++;
        }
    }
    else if (len2>len1) {
        diff=len2-len1;
        while (shift<diff) {
            runnerTwo=runnerTwo->next;
            shift++;
        }
    }

    while (runnerOne!=nullptr || runnerTwo!=nullptr) {
        if (runnerOne==runnerTwo) return runnerOne;
        runnerOne=runnerOne->next;
        runnerTwo=runnerTwo->next;
    }
    return nullptr;

}
