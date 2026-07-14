# Exercise 9 — Priority Queue (Array + List)

> **Roll No:** CH.SC.U4CSE24041 &nbsp;|&nbsp; **Name:** Shaik Muzzammil &nbsp;|&nbsp; **Exercise #9 (PDF label 10)**

## Problem Statement

Implement a priority queue using (a) an array and (b) a linked list. Lower priority value = higher priority (dequeued first). (CO2, BTL3)

## Files in this Folder

| File | Description |
|------|-------------|
| `priority_queue_array.c` | Sorted insertion into a fixed array of (data, priority) pairs |
| `priority_queue_list.c` | Sorted insertion into a linked list of (data, priority) nodes |

## Algorithm

Both implementations keep the queue sorted by ascending priority. Insert scans for the correct position and shifts (array) or relinks pointers (list). Delete always removes the front element (highest priority).

## Sample Input

```
Per program: insert (taskA, p=3), (taskB, p=1), (taskC, p=2), display, delete, delete, display, exit.
```

## Expected Output (summary)

After inserting the three tasks, the queue is ordered by priority: taskB(1) → taskC(2) → taskA(3). Two deletes remove taskB then taskC, leaving only taskA.

## Complexity

Array: O(n) insert (due to shifting), O(n) delete (due to shifting), O(n) space. List: O(n) insert (search), O(1) delete, O(n) space.

## How to Run

```bash
# from this folder
gcc -Wall -Wextra -std=c11 -o <binary> <source.c>
./<binary>
# then follow the on-screen menu
```

Or open `outputs/<binary>_screenshot.png` to see the captured terminal session, and
`outputs/<binary>_output.txt` for the plain-text version of the same.
