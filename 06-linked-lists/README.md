# Exercise 6 — Linked Lists: Singly, Doubly, Circular, Deque

> **Roll No:** CH.SC.U4CSE24041 &nbsp;|&nbsp; **Name:** Shaik Muzzammil &nbsp;|&nbsp; **Exercise #6 (PDF label 7)**

## Problem Statement

Four sub-exercises covering singly, doubly, and circular linked lists, plus a double-ended queue (deque) built on a doubly linked list. (CO2, BTL3)

## Files in this Folder

| File | Description |
|------|-------------|
| `singly_linked_list.c` | Singly LL: insert/delete at beginning, end, position; display |
| `doubly_linked_list.c` | Doubly LL: insert at end; display forward and backward |
| `circular_linked_list.c` | Circular LL: insert at end; delete from beginning; circular display |
| `deque.c` | Deque using doubly LL: insert/delete at both front and rear |

## Algorithm

Each variant uses the same Node pattern with different pointer topology: singly (next only), doubly (prev + next), circular (last->next = head). The deque reuses the doubly-linked node and maintains both `front` and `rear` pointers.

## Sample Input

```
Per program — see each *_output.txt for the exact menu sequence used.
```

## Expected Output (summary)

Each program is menu-driven and exercises every supported operation. See the matching *_screenshot.png for the full session.

## Complexity

O(1) insert/delete at ends; O(n) insert/delete at a position; O(n) space.

## How to Run

```bash
# from this folder
gcc -Wall -Wextra -std=c11 -o <binary> <source.c>
./<binary>
# then follow the on-screen menu
```

Or open `outputs/<binary>_screenshot.png` to see the captured terminal session, and
`outputs/<binary>_output.txt` for the plain-text version of the same.
