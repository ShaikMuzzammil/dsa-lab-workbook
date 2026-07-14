# DSA Lab Workbook — Amrita Vishwa Vidyapeetham, Chennai Campus

> **Data Structures and Algorithms** — B.Tech CSE, Second Year
> Workbook solutions (Academic Year 2025-26), implemented in C (C11), compiled with GCC.

| | |
|---|---|
| **Student Name** | Shaik Muzzammil |
| **Roll No.** | CH.SC.U4CSE24041 |
| **Department** | CSE — A |
| **College** | Amrita Vishwa Vidyapeetham, Chennai Campus |
| **Academic Year** | 2024 – 2028 |
| **Lab In-Charge** | Dr. J. Umamageswaran |

---

## Repository Contents

This repository contains **complete C implementations** for every exercise in the DSA workbook, organised into one self-contained folder per exercise. Every folder has:

- the C source file(s) (with the roll number on the **first line** as a comment, as required by the workbook),
- an `outputs/` directory containing:
  - `<program>_output.txt` — raw terminal capture (compile + run + sample I/O), and
  - `<program>_screenshot.png` — a terminal-style **screenshot** of the same,
- a per-folder `README.md` describing the exercise, algorithm, sample input, and complexity.

### Folder Map

| # | Folder | Topic | Files |
|---|--------|-------|------|
| 00 | `00-pre-exercises/` | Warm-up C programs (loop, array, recursion basics) | 7 `.c` files |
| 01 | `01-adt-bank-account/` | Abstract Data Type — Bank Account | `adt_bank_account.c` |
| 02 | `02-stack-array/` | Stack using Array (push/pop/peek + overflow/underflow) | `stack_array.c` |
| 03 | `03-stack-list/` | Stack using Singly Linked List | `stack_list.c` |
| 04 | `04-queue-array/` | Queue using Array (enqueue/dequeue/front/rear) | `queue_array.c` |
| 05 | `05-queue-list/` | Queue using Linked List | `queue_list.c` |
| 06 | `06-linked-lists/` | Singly / Doubly / Circular Linked List + Deque | 4 `.c` files |
| 07 | `07-tree-traversal/` | Binary Tree — recursive + iterative pre/in/post-order | `tree_traversal.c` |
| 08 | `08-binary-tree-level-order/` | Binary Tree (linked) — BFS / level-order | `binary_tree_level_order.c` |
| 09 | `09-priority-queue/` | Priority Queue using Array **and** Linked List | 2 `.c` files |
| 10 | `10-heaps/` | Min-Heap **and** Max-Heap | 2 `.c` files |
| 11 | `11-skip-list/` | Skip List — insert/delete/search | `skip_list.c` |
| 12 | `12-bst-avl/` | Binary Search Tree **and** AVL Tree (4 rotations) | 2 `.c` files |
| 13 | `13-btree/` | B-Tree of order 3 — insert + traverse | `btree.c` |
| 14 | `14-dag-topological-sort/` | DAG + Topological Sort using DFS | `dag_topo_sort.c` |

**Totals:** 15 exercise folders + 1 pre-exercise folder, **27 C programs**, all compiling cleanly under `-Wall -Wextra -std=c11`.

---

## Quick Start

### Prerequisites
- GCC (any version ≥ 7; tested on GCC 14.2)
- GNU Make (optional — only if you want to use the provided Makefile)
- Python 3 (only if you want to regenerate the screenshots)

### Build & Run a Single Program
```bash
cd 02-stack-array
gcc -Wall -Wextra -std=c11 -o stack_array stack_array.c
./stack_array
# follow the on-screen menu
```

### Build Everything at Once
From the repository root:
```bash
make            # builds all 27 programs into their respective folders
make run        # runs each program with the sample input used in the screenshots
make clean      # removes all binaries
```

### View a Screenshot
Every folder has an `outputs/` directory. Open any `*_screenshot.png` to see what the program prints when run with the sample input. The matching `*_output.txt` is the plain-text version of the same content.

---

## How Each Program is Structured

Every C file follows the same template:

```c
// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise N - <Title>

#include <stdio.h>
...
int main(void) {
    /* menu-driven interactive demo */
}
```

- The **first line is always the roll number**, as required by the workbook ("Code Editor: include Roll No in First line").
- Programs are **menu-driven** (deposit/withdraw, push/pop, enqueue/dequeue, insert/delete, …) so the same binary demonstrates every operation.
- Memory allocated with `malloc` is always released before exit (no leaks under `valgrind`).

---

## Complexity Summary

| # | Exercise | Time (worst case) | Space |
|---|----------|------------------|-------|
| 1 | ADT Bank Account | O(1) per op | O(1) |
| 2 | Stack (Array) | O(1) push/pop/peek | O(n) |
| 3 | Stack (List) | O(1) push/pop/peek | O(n) |
| 4 | Queue (Array) | O(1) enq/deq | O(n) |
| 5 | Queue (List) | O(1) enq/deq | O(n) |
| 6 | Linked Lists | O(n) insert/delete at pos; O(1) at ends | O(n) |
| 7 | Tree Traversal | O(n) for all 6 variants | O(h) recursive / O(n) iterative |
| 8 | Level-Order | O(n) | O(w) where w = max width |
| 9 | Priority Queue | O(n) insert (array), O(1) delete; or O(n) insert, O(1) delete (list) | O(n) |
| 10 | Heaps | O(log n) insert / delete-root | O(n) |
| 11 | Skip List | O(log n) expected search/insert/delete | O(n) |
| 12 | BST | O(h) — O(log n) balanced, O(n) skewed | O(n) |
| 12 | AVL | O(log n) insert + O(1) rotations | O(n) |
| 13 | B-Tree (order 3) | O(log n) insert/traverse | O(n) |
| 14 | DAG Topo Sort (DFS) | O(V + E) | O(V) |

---

## Repository Layout

```
dsa-lab-workbook/
├── README.md                      ← this file
├── Makefile                       ← build / run / clean
├── .gitignore                     ← ignores binaries
├── 00-pre-exercises/
│   ├── A_print_n_natural_numbers.c
│   ├── B_sum_n_natural_numbers.c
│   ├── C_sum_array.c
│   ├── D_max_in_array.c
│   ├── E_second_largest.c
│   ├── F_reverse_integer.c
│   ├── G_array_operations.c
│   ├── README.md
│   └── outputs/
│       ├── A_print_n_output.txt
│       ├── A_print_n_screenshot.png
│       └── … (one pair per program)
├── 01-adt-bank-account/
│   ├── adt_bank_account.c
│   ├── README.md
│   └── outputs/
├── 02-stack-array/
│   └── …
├── …
└── 14-dag-topological-sort/
    └── …
```

---

## Regenerating the Screenshots

The screenshots in each `outputs/` folder were generated programmatically (so they are deterministic and reproducible). If you edit any C file and want to refresh the screenshots:

```bash
# from the repo root
python3 /home/z/my-project/scripts/build_and_capture.py
```

The script:
1. recompiles every program with `gcc -Wall -Wextra -std=c11`,
2. pipes a fixed sample input into each binary,
3. captures stdout + stderr into `<program>_output.txt`, and
4. renders a macOS-style dark terminal PNG into `<program>_screenshot.png`.

---

## Author

**Shaik Muzzammil** — Roll No. CH.SC.U4CSE24041
CSE — A, Amrita Vishwa Vidyapeetham, Chennai Campus
Academic Year 2024–2028

## Acknowledgements

- Lab In-Charge: **Dr. J. Umamageswaran**
- Course: Data Structures and Algorithms (Second Year B.Tech CSE)
- Workbook source: *DSA Work Book, Academic Year 2025-26*

## License

This repository is submitted as academic coursework. You may read and learn from it, but please do not copy verbatim for your own submission.
"# dsa-lab-workbook" 
