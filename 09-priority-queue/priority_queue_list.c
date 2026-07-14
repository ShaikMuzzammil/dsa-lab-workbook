// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 9 (PDF label 10b) - Priority Queue using Linked List
// Lower priority value = higher priority (dequeued first)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node *next;
} Node;

static Node *front = NULL;

void insert_el(int data, int priority) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data; n->priority = priority; n->next = NULL;

    if (!front || front->priority > priority) {
        n->next = front; front = n;
    } else {
        Node *p = front;
        while (p->next && p->next->priority <= priority) p = p->next;
        n->next = p->next; p->next = n;
    }
    printf("Inserted (data=%d, priority=%d)\n", data, priority);
}

void delete_el(void) {
    if (!front) { printf("Queue is empty\n"); return; }
    Node *t = front;
    printf("Deleted (data=%d, priority=%d)\n", t->data, t->priority);
    front = front->next;
    free(t);
}

void display(void) {
    if (!front) { printf("Queue is empty\n"); return; }
    printf("Priority Queue (front -> rear):\n");
    for (Node *p = front; p; p = p->next)
        printf("  [data=%d, priority=%d]\n", p->data, p->priority);
}

void free_all(void) { Node *p = front; while (p) { Node *t = p->next; free(p); p = t; } front = NULL; }

int main(void) {
    int choice, d, p;
    printf("=== Priority Queue using Linked List ===\n");
    printf("(Lower priority value = higher priority)\n");
    printf("1.Insert  2.Delete  3.Display  4.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) { free_all(); return 0; }
        if (choice == 4) { printf("Exiting...\n"); free_all(); break; }
        switch (choice) {
            case 1: printf("data priority: "); scanf("%d %d", &d, &p); insert_el(d, p); break;
            case 2: delete_el(); break;
            case 3: display(); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
