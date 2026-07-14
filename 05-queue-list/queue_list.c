// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 5 (PDF label 6) - Queue using Linked List
// Operations: enqueue, dequeue, display_front, display_rear, display

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

static Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) { printf("Memory allocation failed\n"); return; }
    n->data = x; n->next = NULL;
    if (!front) front = rear = n;
    else        { rear->next = n; rear = n; }
    printf("Enqueued %d\n", x);
}

void dequeue(void) {
    if (!front) { printf("Queue Underflow\n"); return; }
    Node *t = front;
    printf("Dequeued %d\n", t->data);
    front = front->next;
    free(t);
    if (!front) rear = NULL;
}

void display_front(void) {
    if (!front) { printf("Queue is empty\n"); return; }
    printf("Front = %d\n", front->data);
}

void display_rear(void) {
    if (!rear) { printf("Queue is empty\n"); return; }
    printf("Rear = %d\n", rear->data);
}

void display(void) {
    if (!front) { printf("Queue is empty\n"); return; }
    printf("Queue (front -> rear): ");
    for (Node *p = front; p; p = p->next) printf("%d ", p->data);
    printf("\n");
}

void free_all(void) {
    Node *p = front;
    while (p) { Node *t = p->next; free(p); p = t; }
    front = rear = NULL;
}

int main(void) {
    int choice, x;
    printf("=== Queue using Linked List ===\n");
    printf("1.Enqueue  2.Dequeue  3.Front  4.Rear  5.Display  6.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) { free_all(); return 0; }
        if (choice == 6) { printf("Exiting...\n"); free_all(); break; }
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &x); enqueue(x); break;
            case 2: dequeue(); break;
            case 3: display_front(); break;
            case 4: display_rear(); break;
            case 5: display(); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
