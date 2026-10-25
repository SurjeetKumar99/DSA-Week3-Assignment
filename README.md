# Data Structures & Algorithms — Week 3 Assignment
## Trees & Hashing

**Language:** C++17

## Topics
- Binary Tree and Binary Search Tree (BST)
- Recursive traversals: inorder, preorder, postorder
- Hashing and array-based hash tables
- Collision handling with linear probing

## Assignment 1 — Build a BST and Search for a Value
File: `src/01_bst_search.cpp`

A Binary Search Tree stores smaller values in the left subtree and larger values in the right subtree. This program inserts values and searches for a target. Duplicate values are ignored.

Average insert/search complexity is O(log n); worst case is O(n) for a skewed tree.

## Assignment 2 — Recursive Tree Traversals
File: `src/02_recursive_tree_traversals.cpp`

- Inorder: Left, Root, Right. In a BST, values are printed in sorted order.
- Preorder: Root, Left, Right.
- Postorder: Left, Right, Root.

Each traversal takes O(n) time.

## Assignment 3 — HashMap Using Arrays
File: `src/03_hashmap_using_arrays.cpp`

Implements an integer key-value map using fixed-size arrays and linear probing. Supports insert/update, search, deletion using tombstones, and display.

## Assignment 4 — Hash Table with Linear Probing
File: `src/04_linear_probing_hash_table.cpp`

Uses `key % TABLE_SIZE` as the hash function. When a slot is occupied, it checks the next slot until an empty position is found or the table is full.

## Mini Project — Contact Directory (BST Based)
File: `src/05_bst_contact_directory.cpp`

Stores contacts by name in a Binary Search Tree. Supports insert/update, search, delete, and alphabetical display using inorder traversal. Names are case-sensitive.

## Compile and run

Requires a C++17 compiler such as GCC. From the repository root:

```bash
g++ -std=c++17 src/01_bst_search.cpp -o bst_search
./bst_search
```

On Windows, run `bst_search.exe`. Repeat for the other source files, changing the filename and executable name.

## Sample test plan

| Program | Example input | Expected result |
|---|---|---|
| BST search | Insert 50, 30, 70, 20, 40; search 40 | Value found |
| Traversals | Insert 50, 30, 70, 20, 40 | Inorder: 20 30 40 50 70 |
| Array HashMap | Insert key 12, value 120; search key 12 | Value 120 found |
| Linear probing | Insert keys 10, 17, 24 with table size 7 | Keys occupy indices 3, 4, 5 |
| Contact directory | Add Alice, Bob, Charlie; display | Alphabetical order |

## Folder structure

```text
DSA-Week3-Assignment/
├── README.md
├── .gitignore
└── src/
    ├── 01_bst_search.cpp
    ├── 02_recursive_tree_traversals.cpp
    ├── 03_hashmap_using_arrays.cpp
    ├── 04_linear_probing_hash_table.cpp
    └── 05_bst_contact_directory.cpp
```

## Conclusion

This assignment practices BST insertion and searching, recursive tree traversals, array-based hashing, collision handling with linear probing, and a BST-based contact directory.
