# Exercise 13 — B-Tree of Order 3

> **Roll No:** CH.SC.U4CSE24041 &nbsp;|&nbsp; **Name:** Shaik Muzzammil &nbsp;|&nbsp; **Exercise #13 (PDF label 14)**

## Problem Statement

Construct a B-tree of order 3 and implement insertion and traversal algorithms. (CO3, BTL4)

## Files in this Folder

| File | Description |
|------|-------------|
| `btree.c` | Order-3 B-tree: max 2 keys per node, max 3 children. Insert promotes the middle key on overflow. |

## Algorithm

Define `struct BNode { int keys[3]; BNode *children[4]; int n; int leaf; }` (one extra slot to make splitting simple). `insert` checks the root: if full, create a new root and split the old root; otherwise call `insert_nonfull`. `insert_nonfull` either inserts into a leaf (shifting keys) or descends into the right child after splitting it if full. `split_child` moves the upper half of keys/children into a new node and promotes the middle key.

## Sample Input

```
1 10
1 20
1 5
1 6
1 12
1 30
1 7
1 17
2
5
```

## Expected Output (summary)

Inserts the keys 10, 20, 5, 6, 12, 30, 7, 17 in order. Each insert either places the key in a non-full leaf or triggers a split that promotes the middle key to the parent. Traversal prints the keys in ascending order: 5 6 7 10 12 17 20 30.

## Complexity

O(log n) insert and traverse (height is O(log₃ n)); O(n) space.

## How to Run

```bash
# from this folder
gcc -Wall -Wextra -std=c11 -o <binary> <source.c>
./<binary>
# then follow the on-screen menu
```

Or open `outputs/<binary>_screenshot.png` to see the captured terminal session, and
`outputs/<binary>_output.txt` for the plain-text version of the same.
