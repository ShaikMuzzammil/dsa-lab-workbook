// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 1 - Abstract Data Type (ADT) for a Bank Account
// Operations: Create_Account, Deposit, Withdraw, Check_Balance

#include <stdio.h>
#include <string.h>

typedef struct {
    int    account_number;
    char   name[50];
    double balance;
} Account;

void create_account(Account *a, int acc_no, const char *name, double initial) {
    a->account_number = acc_no;
    strncpy(a->name, name, sizeof(a->name) - 1);
    a->name[sizeof(a->name) - 1] = '\0';
    a->balance = initial;
    printf("Account created: %d | %s | Balance: %.2lf\n",
           a->account_number, a->name, a->balance);
}

void deposit(Account *a, double amount) {
    if (amount <= 0) { printf("Invalid deposit amount\n"); return; }
    a->balance += amount;
    printf("Deposited %.2lf | Updated Balance: %.2lf\n", amount, a->balance);
}

void withdraw(Account *a, double amount) {
    if (amount <= 0)            { printf("Invalid withdrawal amount\n"); return; }
    if (amount > a->balance)    { printf("Insufficient Balance\n"); return; }
    a->balance -= amount;
    printf("Withdrawn %.2lf | Updated Balance: %.2lf\n", amount, a->balance);
}

void check_balance(const Account *a) {
    printf("Account No: %d | Holder: %s | Balance: %.2lf\n",
           a->account_number, a->name, a->balance);
}

int main(void) {
    Account acc;
    int choice, acc_no;
    char name[50];
    double amount, initial;

    printf("=== Bank Account ADT ===\n");
    printf("Creating a new account first.\n");
    printf("Enter Account Number: ");    scanf("%d", &acc_no);
    printf("Enter Name: ");              scanf("%s", name);
    printf("Enter Initial Balance: ");   scanf("%lf", &initial);
    create_account(&acc, acc_no, name, initial);

    printf("\n1. Deposit  2. Withdraw  3. Check Balance  4. Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) return 0;
        if (choice == 4) { printf("Exiting...\n"); break; }
        switch (choice) {
            case 1: printf("Amount to deposit: ");  scanf("%lf", &amount);
                    deposit(&acc, amount); break;
            case 2: printf("Amount to withdraw: "); scanf("%lf", &amount);
                    withdraw(&acc, amount); break;
            case 3: check_balance(&acc); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
