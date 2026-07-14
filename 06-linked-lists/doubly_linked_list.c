// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 6 (PDF label 7b) - Doubly Linked List
// Forward and backward traversal

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

static Node *head = NULL, *tail = NULL;

Node* new_node(int v) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = v; n->prev = n->next = NULL;
    return n;
}

void insert_end(int v) {
    Node *n = new_node(v);
    if (!head) { head = tail = n; }
    else {
        tail->next = n; n->prev = tail;
        tail = n;
    }
    printf("Inserted %d at end\n", v);
}

void display_forward(void) {
    if (!head) { printf("List is empty\n"); return; }
    printf("Forward : ");
    for (Node *p = head; p; p = p->next) printf("%d -> ", p->data);
    printf("NULL\n");
}

void display_backward(void) {
    if (!tail) { printf("List is empty\n"); return; }
    printf("Backward: ");
    for (Node *p = tail; p; p = p->prev) printf("%d -> ", p->data);
    printf("NULL\n");
}

void free_all(void) {
    Node *p = head;
    while (p) { Node *t = p->next; free(p); p = t; }
    head = tail = NULL;
}

int main(void) {
    int choice, v;
    printf("=== Doubly Linked List ===\n");
    printf("1.InsertEnd  2.DisplayForward  3.DisplayBackward  4.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) { free_all(); return 0; }
        if (choice == 4) { printf("Exiting...\n"); free_all(); break; }
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &v); insert_end(v); break;
            case 2: display_forward();  break;
            case 3: display_backward(); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
