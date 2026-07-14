// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 3 (PDF label 4) - Stack using Singly Linked List
// Operations: push, pop, peek, display with dynamic memory

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

static Node *top = NULL;

void push(int x) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) { printf("Memory allocation failed\n"); return; }
    n->data = x;
    n->next = top;
    top = n;
    printf("Pushed %d\n", x);
}

void pop(void) {
    if (!top) { printf("Stack Underflow\n"); return; }
    Node *t = top;
    printf("Popped %d\n", t->data);
    top = top->next;
    free(t);
}

void peek(void) {
    if (!top) { printf("Stack is empty\n"); return; }
    printf("Top element = %d\n", top->data);
}

void display(void) {
    if (!top) { printf("Stack is empty\n"); return; }
    printf("Stack (top -> bottom): ");
    for (Node *p = top; p; p = p->next) printf("%d ", p->data);
    printf("\n");
}

void free_all(void) {
    Node *p = top;
    while (p) { Node *t = p->next; free(p); p = t; }
    top = NULL;
}

int main(void) {
    int choice, x;
    printf("=== Stack using Linked List ===\n");
    printf("1.Push  2.Pop  3.Peek  4.Display  5.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) { free_all(); return 0; }
        if (choice == 5) { printf("Exiting...\n"); free_all(); break; }
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &x); push(x); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
