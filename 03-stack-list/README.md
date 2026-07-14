# Exercise 3 — Stack using Linked List

> **Roll No:** CH.SC.U4CSE24041 &nbsp;|&nbsp; **Name:** Shaik Muzzammil &nbsp;|&nbsp; **Exercise #3 (PDF label 4)**

## Problem Statement

Develop a stack using a singly linked list. Perform all stack operations and demonstrate memory efficiency. (CO2, BTL3)

## Files in this Folder

| File | Description |
|------|-------------|
| `stack_list.c` | Dynamic stack using malloc'd nodes; frees nodes on pop |

## Algorithm

Define `struct Node { int data; Node *next; }`. A global `top` pointer. `push` mallocs a new node, points its `next` to current `top`, updates `top`. `pop` saves `top->data`, moves `top` to `top->next`, frees the old node. `peek`/`display` traverse from `top`.

## Sample Input

```
1 5
1 10
1 15
4
2
3
4
5
```

## Expected Output (summary)

Pushes 5, 10, 15. Display: 15 10 5. Pop removes 15. Peek shows 10. Final display: 10 5.

## Complexity

O(1) push/pop/peek; O(n) space (grows on demand).

## How to Run

```bash
# from this folder
gcc -Wall -Wextra -std=c11 -o <binary> <source.c>
./<binary>
# then follow the on-screen menu
```

Or open `outputs/<binary>_screenshot.png` to see the captured terminal session, and
`outputs/<binary>_output.txt` for the plain-text version of the same.
