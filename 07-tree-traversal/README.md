# Exercise 7 — Tree Traversal (Recursive + Iterative)

> **Roll No:** CH.SC.U4CSE24041 &nbsp;|&nbsp; **Name:** Shaik Muzzammil &nbsp;|&nbsp; **Exercise #7 (PDF label 8)**

## Problem Statement

Construct a binary tree and implement recursive and iterative preorder, inorder, and postorder traversals. (CO2, BTL3)

## Files in this Folder

| File | Description |
|------|-------------|
| `tree_traversal.c` | Builds a 7-node binary tree and prints all 6 traversal variants |

## Algorithm

Define `struct Node { int data; Node *left, *right; }`. Recursive traversals follow the classic Root/L/R visit orders. Iterative preorder uses one stack (push right then left). Iterative inorder walks left, pops, then goes right. Iterative postorder uses two stacks: push root to s1, pop from s1 and push to s2, push children to s1; finally drain s2.

## Sample Input

```
(none — the tree is hard-coded)
```

## Expected Output (summary)

Recursive and iterative variants produce identical results:
- Preorder : 1 2 4 5 3 6 7
- Inorder  : 4 2 5 1 6 3 7
- Postorder: 4 5 2 6 7 3 1

## Complexity

O(n) time and O(h) stack space for every variant (h = tree height).

## How to Run

```bash
# from this folder
gcc -Wall -Wextra -std=c11 -o <binary> <source.c>
./<binary>
# then follow the on-screen menu
```

Or open `outputs/<binary>_screenshot.png` to see the captured terminal session, and
`outputs/<binary>_output.txt` for the plain-text version of the same.
