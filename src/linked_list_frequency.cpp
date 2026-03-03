#include <string>
#include <vector>
#include <node.hpp>
#include <unordered_map>

Node *frequenciesOfElements(Node *head) {
    std::unordered_map<int, int> um;
    Node *dummy = new Node(0);
    Node *runner = dummy;

    Node *temp = head;

    while (temp != nullptr) {
        um[temp->m_val]++;
        temp = temp->next;
    }
    for (const auto &[k,v]: um) {
        runner->next = new Node(v);
        runner = runner->next;
    }
    return dummy->next;
}
