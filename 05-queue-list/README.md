# Exercise 5 — Queue using Linked List

> **Roll No:** CH.SC.U4CSE24041 &nbsp;|&nbsp; **Name:** Shaik Muzzammil &nbsp;|&nbsp; **Exercise #5 (PDF label 6)**

## Problem Statement

Create a queue using a linked list. Ensure dynamic memory allocation and implement all basic queue operations. (CO2, BTL3)

## Files in this Folder

| File | Description |
|------|-------------|
| `queue_list.c` | Dynamic queue with separate front and rear pointers |

## Algorithm

`struct Node { int data; Node *next; }` plus global `front` and `rear` pointers. `enqueue` mallocs a node, links `rear->next` to it (or sets both `front` and `rear` if empty). `dequeue` removes `front`, advances `front`, frees the node; if `front` becomes NULL, also reset `rear`.

## Sample Input

```
1 100
1 200
1 300
5
3
4
2
2
5
6
```

## Expected Output (summary)

Enqueues 100, 200, 300. Display shows the queue in FIFO order. Two dequeues remove 100 and 200. Final display: 300.

## Complexity

O(1) enqueue/dequeue; O(n) space.

## How to Run

```bash
# from this folder
gcc -Wall -Wextra -std=c11 -o <binary> <source.c>
./<binary>
# then follow the on-screen menu
```

Or open `outputs/<binary>_screenshot.png` to see the captured terminal session, and
`outputs/<binary>_output.txt` for the plain-text version of the same.
