# Exercise 12 — BST & AVL Tree

> **Roll No:** CH.SC.U4CSE24041 &nbsp;|&nbsp; **Name:** Shaik Muzzammil &nbsp;|&nbsp; **Exercise #12 (PDF label 13)**

## Problem Statement

(a) Create a binary search tree with insert, delete, and search. (b) Implement an AVL tree with single and double rotations after insertion. (CO3, BTL4)

## Files in this Folder

| File | Description |
|------|-------------|
| `bst.c` | BST with recursive insert, search, delete (inorder-successor case), and inorder display |
| `avl.c` | AVL tree with LL, RR, LR, RL rotations after each insert |

## Algorithm

BST: classic recursive insert/search/delete with the three deletion cases (leaf, one child, two children using the inorder successor). AVL: each insert updates heights, computes balance factor, and applies LL (right rotate), RR (left rotate), LR (left-rotate left child then right-rotate root), or RL (right-rotate right child then left-rotate root).

## Sample Input

```
BST: insert 50,30,70,20,40,60,80; inorder; delete 40; delete 30; inorder; exit. AVL: insert 10,20,30,40,50,25; preorder; inorder; exit.
```

## Expected Output (summary)

BST inorder before deletes: 20 30 40 50 60 70 80. After deleting 40 and 30: 20 50 60 70 80. AVL after inserting the 6 values stays balanced; preorder shows the rotated structure.

## Complexity

BST: O(h) per op — O(log n) balanced, O(n) skewed. AVL: O(log n) per op guaranteed. Both: O(n) space.

## How to Run

```bash
# from this folder
gcc -Wall -Wextra -std=c11 -o <binary> <source.c>
./<binary>
# then follow the on-screen menu
```

Or open `outputs/<binary>_screenshot.png` to see the captured terminal session, and
`outputs/<binary>_output.txt` for the plain-text version of the same.
