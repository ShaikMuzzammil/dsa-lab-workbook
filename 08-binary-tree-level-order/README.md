# Exercise 8 — Binary Tree Linked Structure + Level-Order

> **Roll No:** CH.SC.U4CSE24041 &nbsp;|&nbsp; **Name:** Shaik Muzzammil &nbsp;|&nbsp; **Exercise #8 (PDF label 9)**

## Problem Statement

Create a binary tree using a linked structure and display the level-order (BFS) traversal. (CO2, BTL3)

## Files in this Folder

| File | Description |
|------|-------------|
| `binary_tree_level_order.c` | Builds a 7-node linked binary tree and prints BFS order |

## Algorithm

Define `struct Node { int data; Node *left, *right; }`. Maintain a simple array-based queue of node pointers. `level_order` enqueues the root, then while the queue is non-empty: dequeues a node, prints it, and enqueues its left and right children if present.

## Sample Input

```
(none — the tree is hard-coded)
```

## Expected Output (summary)

Level-order: 1 2 3 4 5 6 7

## Complexity

O(n) time, O(w) space where w is the maximum width of the tree.

## How to Run

```bash
# from this folder
gcc -Wall -Wextra -std=c11 -o <binary> <source.c>
./<binary>
# then follow the on-screen menu
```

Or open `outputs/<binary>_screenshot.png` to see the captured terminal session, and
`outputs/<binary>_output.txt` for the plain-text version of the same.
