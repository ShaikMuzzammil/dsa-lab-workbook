# Exercise 4 — Queue using Array

> **Roll No:** CH.SC.U4CSE24041 &nbsp;|&nbsp; **Name:** Shaik Muzzammil &nbsp;|&nbsp; **Exercise #4 (PDF label 5)**

## Problem Statement

Implement a queue using arrays. Include enqueue, dequeue, and front/rear display functionalities. (CO2, BTL3)

## Files in this Folder

| File | Description |
|------|-------------|
| `queue_array.c` | Linear queue (MAX=5) with overflow/underflow and front/rear accessors |

## Algorithm

`struct Queue { int arr[MAX]; int front, rear; }`. `enqueue` checks `rear == MAX-1` for overflow. `dequeue` checks `front == -1 || front > rear` for underflow, then increments `front`. When the queue empties (`front > rear`), reset both indices to -1.

## Sample Input

```
1 10
1 20
1 30
5
3
4
2
2
5
6
```

## Expected Output (summary)

Enqueues 10, 20, 30. Display: 10 20 30. Front=10, Rear=30. Two dequeues remove 10 and 20. Final display: 30. Exit.

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
