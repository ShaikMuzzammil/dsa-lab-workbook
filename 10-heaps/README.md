# Exercise 10 — Heaps (Min-Heap + Max-Heap)

> **Roll No:** CH.SC.U4CSE24041 &nbsp;|&nbsp; **Name:** Shaik Muzzammil &nbsp;|&nbsp; **Exercise #10 (PDF label 11)**

## Problem Statement

Implement a min-heap and a max-heap. Support insert and delete-root operations in both. (CO2, BTL3)

## Files in this Folder

| File | Description |
|------|-------------|
| `min_heap.c` | Min-heap on an array; insert uses heapify-up, delete-root uses heapify-down |
| `max_heap.c` | Max-heap on an array; symmetric to the min-heap |

## Algorithm

Use an array `heap[]` indexed from 0 with `parent(i)=(i-1)/2`, `left(i)=2i+1`, `right(i)=2i+2`. `insert` appends at the end and bubbles up while the heap property is violated. `delete_root` swaps the root with the last element, decrements size, and sifts down.

## Sample Input

```
Per program: insert 50, 30, 40, 10, 20; display; delete-root twice; display; exit.
```

## Expected Output (summary)

Min-heap after inserts: 10 20 40 50 30. Two delete-min operations remove 10 then 20; remaining: 30 50 40. Max-heap after inserts: 50 40 30 10 20. Two delete-max remove 50 then 40; remaining: 30 10 20.

## Complexity

O(log n) insert and delete-root; O(n) space.

## How to Run

```bash
# from this folder
gcc -Wall -Wextra -std=c11 -o <binary> <source.c>
./<binary>
# then follow the on-screen menu
```

Or open `outputs/<binary>_screenshot.png` to see the captured terminal session, and
`outputs/<binary>_output.txt` for the plain-text version of the same.
