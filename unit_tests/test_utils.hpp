#pragma once

#include <initializer_list>
#include <vector>

#include "api.hpp"

// Convert Node chain to std::vector<int> for easy comparisons in tests.
inline std::vector<int> toVector(const Node* head) {
    std::vector<int> out;
    const Node* cur = head;
    while (cur != nullptr) {
        out.push_back(cur->m_val);
        cur = cur->next;
    }
    return out;
}

// Build a list quickly in tests without manual append loops.
// Example: buildList(ll, {3,5,5,6});
inline void buildList(LinkedList& ll, std::initializer_list<int> values) {
    for (int x : values) {
        ll.append(x);
    }
}

inline void freeList(Node* head) {
    while (head) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}