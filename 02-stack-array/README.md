# Exercise 2 — Stack using Array

> **Roll No:** CH.SC.U4CSE24041 &nbsp;|&nbsp; **Name:** Shaik Muzzammil &nbsp;|&nbsp; **Exercise #2**

## Problem Statement

Implement a stack using an array. Provide push, pop, peek operations and handle overflow and underflow conditions. (CO2, BTL3)

## Files in this Folder

| File | Description |
|------|-------------|
| `stack_array.c` | Fixed-capacity stack (MAX=5) with overflow/underflow checks |

## Algorithm

Use `struct Stack { int arr[MAX]; int top; }`. `push` checks `top == MAX-1` for overflow, else `arr[++top] = x`. `pop` checks `top == -1` for underflow. `peek` returns `arr[top]`. `display` iterates from `top` down to 0.

## Sample Input

```
1 10
1 20
1 30
1 40
1 50
1 60
4
2
3
4
5
```

## Expected Output (summary)

Pushes 10..50; the 6th push reports 'Stack Overflow'. Display shows 50 40 30 20 10. Pop removes 50; peek shows 40. Final display shows the remaining 4 elements.

## Complexity

O(1) push/pop/peek; O(n) space.

## How to Run

```bash
# from this folder
gcc -Wall -Wextra -std=c11 -o <binary> <source.c>
./<binary>
# then follow the on-screen menu
```

Or open `outputs/<binary>_screenshot.png` to see the captured terminal session, and
`outputs/<binary>_output.txt` for the plain-text version of the same.
