// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 9 (PDF label 10a) - Priority Queue using Array
// Lower priority value = higher priority (dequeued first)

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
    int data;
    int priority;
} Element;

static Element queue[MAX];
static int size = 0;

void insert_el(int data, int priority) {
    if (size >= MAX) { printf("Queue is full\n"); return; }
    int i = size - 1;
    while (i >= 0 && queue[i].priority > priority) {
        queue[i+1] = queue[i];
        --i;
    }
    queue[i+1].data = data;
    queue[i+1].priority = priority;
    ++size;
    printf("Inserted (data=%d, priority=%d)\n", data, priority);
}

void delete_el(void) {
    if (size == 0) { printf("Queue is empty\n"); return; }
    Element e = queue[0];
    for (int i = 0; i < size - 1; ++i) queue[i] = queue[i+1];
    --size;
    printf("Deleted (data=%d, priority=%d)\n", e.data, e.priority);
}

void display(void) {
    if (size == 0) { printf("Queue is empty\n"); return; }
    printf("Priority Queue (front -> rear):\n");
    for (int i = 0; i < size; ++i)
        printf("  [data=%d, priority=%d]\n", queue[i].data, queue[i].priority);
}

int main(void) {
    int choice, d, p;
    printf("=== Priority Queue using Array ===\n");
    printf("(Lower priority value = higher priority)\n");
    printf("1.Insert  2.Delete  3.Display  4.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) return 0;
        if (choice == 4) { printf("Exiting...\n"); break; }
        switch (choice) {
            case 1: printf("data priority: "); scanf("%d %d", &d, &p); insert_el(d, p); break;
            case 2: delete_el(); break;
            case 3: display(); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
