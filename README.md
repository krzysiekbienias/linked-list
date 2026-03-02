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