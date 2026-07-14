# Exercise 14 — DAG + Topological Sort (DFS)

> **Roll No:** CH.SC.U4CSE24041 &nbsp;|&nbsp; **Name:** Shaik Muzzammil &nbsp;|&nbsp; **Exercise #14 (PDF label 15)**

## Problem Statement

Create a directed acyclic graph (DAG) and implement topological sorting using Depth First Search. (CO3, BTL4)

## Files in this Folder

| File | Description |
|------|-------------|
| `dag_topo_sort.c` | Adjacency-list DAG; DFS pushes finished vertices onto a stack; pop gives topo order |

## Algorithm

Represent the graph as an array of adjacency lists (`Node *adj[V]`). Maintain `visited[V]` and a result `stack[V]`. `dfs(v)` marks v visited, recurses into all unvisited neighbours, then pushes v onto the stack. `topological_sort` calls `dfs` on every unvisited vertex, then pops the stack to print the order.

## Sample Input

```
6
7
5 2
5 0
4 0
4 1
2 3
3 1

```

## Expected Output (summary)

Builds a 6-vertex DAG with edges 5→2, 5→0, 4→0, 4→1, 2→3, 3→1. Prints the adjacency list, then a valid topological order (e.g. 5 4 2 3 1 0).

## Complexity

O(V + E) time; O(V) space for visited[] and the stack.

## How to Run

```bash
# from this folder
gcc -Wall -Wextra -std=c11 -o <binary> <source.c>
./<binary>
# then follow the on-screen menu
```

Or open `outputs/<binary>_screenshot.png` to see the captured terminal session, and
`outputs/<binary>_output.txt` for the plain-text version of the same.
