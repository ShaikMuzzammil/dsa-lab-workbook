# Exercise 11 — Skip List

> **Roll No:** CH.SC.U4CSE24041 &nbsp;|&nbsp; **Name:** Shaik Muzzammil &nbsp;|&nbsp; **Exercise #11 (PDF label 12)**

## Problem Statement

Design and implement a Skip List to store ordered elements. Include insert, delete, and search operations. (CO3, BTL4)

## Files in this Folder

| File | Description |
|------|-------------|
| `skip_list.c` | Probabilistic skip list with MAX_LEVEL=6 and p=0.5 |

## Algorithm

Define `struct Node { int data; int level; Node **forward; }`. Maintain `head` (sentinel with max level) and current `level`. `insert` searches at each level, records an `update[]` array, picks a random level via coin flips, and relinks forward pointers. `delete` reverses the links. `search` descends level by level.

## Sample Input

```
1 10
1 20
1 15
1 5
4
3 15
2 10
4
5
```

## Expected Output (summary)

Inserts 10, 20, 15, 5 (each at a random level). Display shows all levels. Search 15 → found. Delete 10. Display again. Exit.

## Complexity

O(log n) expected time for search/insert/delete; O(n) space.

## How to Run

```bash
# from this folder
gcc -Wall -Wextra -std=c11 -o <binary> <source.c>
./<binary>
# then follow the on-screen menu
```

Or open `outputs/<binary>_screenshot.png` to see the captured terminal session, and
`outputs/<binary>_output.txt` for the plain-text version of the same.
