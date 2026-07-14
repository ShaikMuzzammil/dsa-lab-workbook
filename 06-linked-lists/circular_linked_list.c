// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 6 (PDF label 7c) - Circular Linked List
// Insert at end, delete from beginning, display (circular traversal)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

static Node *last = NULL;   // last->next is always head

Node* new_node(int v) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = v; n->next = NULL;
    return n;
}

void insert_end(int v) {
    Node *n = new_node(v);
    if (!last) { n->next = n; last = n; }
    else {
        n->next = last->next;
        last->next = n;
        last = n;
    }
    printf("Inserted %d at end\n", v);
}

void delete_begin(void) {
    if (!last) { printf("List is empty\n"); return; }
    Node *first = last->next;
    if (first == last) { printf("Deleted %d\n", first->data); free(first); last = NULL; return; }
    last->next = first->next;
    printf("Deleted %d from beginning\n", first->data);
    free(first);
}

void display(void) {
    if (!last) { printf("List is empty\n"); return; }
    Node *p = last->next;
    printf("Circular List: ");
    do {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != last->next);
    printf("(back to head)\n");
}

void free_all(void) {
    if (!last) return;
    Node *p = last->next;
    while (p != last) { Node *t = p->next; free(p); p = t; }
    free(last);
    last = NULL;
}

int main(void) {
    int choice, v;
    printf("=== Circular Linked List ===\n");
    printf("1.InsertEnd  2.DeleteBegin  3.Display  4.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) { free_all(); return 0; }
        if (choice == 4) { printf("Exiting...\n"); free_all(); break; }
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &v); insert_end(v); break;
            case 2: delete_begin(); break;
            case 3: display(); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
