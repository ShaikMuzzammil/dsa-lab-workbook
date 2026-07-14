# Pre-Exercises — Warm-up C Programs

> **Roll No:** CH.SC.U4CSE24041 &nbsp;|&nbsp; **Name:** Shaik Muzzammil &nbsp;|&nbsp; **Exercise #0 (Pre)**

## Problem Statement

Seven small warm-up programs covering loops, arrays, integer reversal, and a tiny Array ADT. These precede the main activity sheets and refresh basic C syntax before the data-structure work begins.

## Files in this Folder

| File | Description |
|------|-------------|
| `A_print_n_natural_numbers.c` | Print first N natural numbers using a for-loop |
| `B_sum_n_natural_numbers.c` | Sum of first N natural numbers using the formula N*(N+1)/2 |
| `C_sum_array.c` | Sum of values in an array (read n then n integers) |
| `D_max_in_array.c` | Find the maximum element in an array |
| `E_second_largest.c` | Find the second largest element in an array (single pass) |
| `F_reverse_integer.c` | Reverse the digits of an integer |
| `G_array_operations.c` | Menu-driven Array ADT: insert, delete, search, display |

## Algorithm

Direct loops / arithmetic; no recursion. Array operations use a fixed-size int[100] buffer with a 'size' counter.

## Sample Input

```
10
100
5
10 20 30 40 50
6
12 45 7 89 23 56
6
12 45 7 89 23 56
12345
(then a sequence of menu choices for G)
```

## Expected Output (summary)

Each program prints its computed result. For example, B prints 'Sum of first 100 natural numbers is: 5050'.

## Complexity

O(n) for array traversals; O(1) for the arithmetic sum formula.

## How to Run

```bash
# from this folder
gcc -Wall -Wextra -std=c11 -o <binary> <source.c>
./<binary>
# then follow the on-screen menu
```

Or open `outputs/<binary>_screenshot.png` to see the captured terminal session, and
`outputs/<binary>_output.txt` for the plain-text version of the same.
