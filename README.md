# Linked List – API Design & Interview-Oriented Algorithms

This project develops linked lists along two parallel tracks:

## 1️⃣ Data Structure API 🛠️

A clean and reusable LinkedList API focused on:
- memory ownership and destructor safety,
- pointer correctness,
- clear separation of responsibilities,
- and testability.

The API represents how a linked list would be implemented in a real codebase — with proper encapsulation and lifecycle management.

## 2️⃣ Interview-Oriented Standalone Algorithms 👨🏻‍🎓

At the same time, the project isolates algorithmic logic into standalone functions operating directly on `Node*`.

This allows solving classic interview problems (middle node, remove duplicates, etc.) exactly as they appear on platforms like LeetCode — without coupling them to the full API.

By separating the structure from the algorithms, we gain:

- realistic production-style API design,
- clean pointer-based problem solving,
- better testability,
- and clearer reasoning about complexity and ownership.

This dual approach builds both engineering discipline and interview readiness.

---

## ✅ Solved Problems

| Problem | File | Key Technique |
|---|---|---|
| Remove Duplicates from Sorted List | `src/remove_duplicates_from_sorted_list.cpp` | Single pass, skip duplicates |
| Remove Duplicates from Unsorted List | `src/remove_duplicates_unsorted.cpp` | Hash map frequency count |
| Middle Node | `src/middle_node.cpp` | Slow/fast pointers |
| Insert Node at Index | `src/insert_node.cpp` | Pointer traversal |
| Is Palindrome | `src/is_palindrome.cpp` | Reverse second half |
| Reverse Linked List | `src/reverse_linked_list.cpp` | Iterative pointer reversal |
| Remove Kth Node from End | `src/remove_kth_node.cpp` | Length + pointer arithmetic |
| Add Two Numbers | `src/add_two_numbers.cpp` | Digit-by-digit with carry |
| Linked List Frequency | `src/linked_list_frequency.cpp` | Hash map |
| Merge Two Sorted Lists | `src/merge_sorted_lists.cpp` | Dummy node merge |
| Merge (Intersection by Pointer) | `src/merging_linked_list.cpp` | Length equalisation |
| Remove Elements by Value | `src/remove_element.cpp` | Sentinel node |
| Has Cycle | `src/has_cycle.cpp` | Floyd's tortoise & hare (phase 1) |
| Find Cycle Origin | `src/find_cycle_origin.cpp` | Floyd's tortoise & hare (phase 1 + 2) |
| Delete Middle Node | `src/delete_middle.cpp` | Dummy + slow/fast to stop before middle |