# Exercise 1 — Abstract Data Type (ADT) for a Bank Account

> **Roll No:** CH.SC.U4CSE24041 &nbsp;|&nbsp; **Name:** Shaik Muzzammil &nbsp;|&nbsp; **Exercise #1**

## Problem Statement

Design and implement an ADT for a simple bank account system with operations: create_account, deposit, withdraw, and check_balance. (CO1, BTL2)

## Files in this Folder

| File | Description |
|------|-------------|
| `adt_bank_account.c` | Menu-driven Bank Account ADT with deposit, withdraw, balance check |

## Algorithm

Define `struct Account { account_number, name, balance }`. Implement `create_account`, `deposit`, `withdraw` (with insufficient-balance check), and `check_balance` as functions taking a pointer to the struct. A `while(1)` menu dispatches to each operation.

## Sample Input

```
101 Muzzammil 1000
1 500
2 200
3
4
```

## Expected Output (summary)

Creates account #101 with balance 1000, deposits 500 (balance 1500), withdraws 200 (balance 1300), prints balance, then exits.

## Complexity

O(1) per operation; O(1) space (single account).

## How to Run

```bash
# from this folder
gcc -Wall -Wextra -std=c11 -o <binary> <source.c>
./<binary>
# then follow the on-screen menu
```

Or open `outputs/<binary>_screenshot.png` to see the captured terminal session, and
`outputs/<binary>_output.txt` for the plain-text version of the same.
