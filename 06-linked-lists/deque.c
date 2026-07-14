// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 6 (PDF label 7d) - Double-Ended Queue (Deque) using Doubly Linked List
// Insert/Delete at both front and rear

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

static Node *front = NULL, *rear = NULL;

Node* new_node(int v) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = v; n->prev = n->next = NULL;
    return n;
}

void ins_front(int v) {
    Node *n = new_node(v);
    if (!front) { front = rear = n; }
    else { n->next = front; front->prev = n; front = n; }
    printf("Inserted %d at front\n", v);
}

void ins_rear(int v) {
    Node *n = new_node(v);
    if (!rear) { front = rear = n; }
    else { n->prev = rear; rear->next = n; rear = n; }
    printf("Inserted %d at rear\n", v);
}

void del_front(void) {
    if (!front) { printf("Deque is empty\n"); return; }
    Node *t = front;
    printf("Deleted %d from front\n", t->data);
    front = front->next;
    if (!front) rear = NULL;
    else front->prev = NULL;
    free(t);
}

void del_rear(void) {
    if (!rear) { printf("Deque is empty\n"); return; }
    Node *t = rear;
    printf("Deleted %d from rear\n", t->data);
    rear = rear->prev;
    if (!rear) front = NULL;
    else rear->next = NULL;
    free(t);
}

void display(void) {
    if (!front) { printf("Deque is empty\n"); return; }
    printf("Deque (front -> rear): ");
    for (Node *p = front; p; p = p->next) printf("%d ", p->data);
    printf("\n");
}

void free_all(void) {
    Node *p = front;
    while (p) { Node *t = p->next; free(p); p = t; }
    front = rear = NULL;
}

int main(void) {
    int choice, v;
    printf("=== Deque (Doubly Linked List) ===\n");
    printf("1.InsFront 2.InsRear 3.DelFront 4.DelRear 5.Display 6.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) { free_all(); return 0; }
        if (choice == 6) { printf("Exiting...\n"); free_all(); break; }
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &v); ins_front(v); break;
            case 2: printf("Value: "); scanf("%d", &v); ins_rear(v);  break;
            case 3: del_front(); break;
            case 4: del_rear();  break;
            case 5: display();   break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
