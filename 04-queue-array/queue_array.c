// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 4 (PDF label 5) - Queue using Array
// Operations: enqueue, dequeue, display_front, display_rear, display

#include <stdio.h>

#define MAX 5

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void init(Queue *q) { q->front = -1; q->rear = -1; }
int  is_empty(const Queue *q) { return q->front == -1 || q->front > q->rear; }
int  is_full (const Queue *q) { return q->rear == MAX - 1; }

void enqueue(Queue *q, int x) {
    if (is_full(q)) { printf("Queue Overflow\n"); return; }
    if (q->front == -1) q->front = 0;
    q->arr[++(q->rear)] = x;
    printf("Enqueued %d\n", x);
}

void dequeue(Queue *q) {
    if (is_empty(q)) { printf("Queue Underflow\n"); return; }
    printf("Dequeued %d\n", q->arr[q->front++]);
    if (q->front > q->rear) { q->front = q->rear = -1; }
}

void display_front(const Queue *q) {
    if (is_empty(q)) { printf("Queue is empty\n"); return; }
    printf("Front = %d\n", q->arr[q->front]);
}

void display_rear(const Queue *q) {
    if (is_empty(q)) { printf("Queue is empty\n"); return; }
    printf("Rear = %d\n", q->arr[q->rear]);
}

void display(const Queue *q) {
    if (is_empty(q)) { printf("Queue is empty\n"); return; }
    printf("Queue (front -> rear): ");
    for (int i = q->front; i <= q->rear; ++i) printf("%d ", q->arr[i]);
    printf("\n");
}

int main(void) {
    Queue q; init(&q);
    int choice, x;
    printf("=== Queue using Array (MAX=%d) ===\n", MAX);
    printf("1.Enqueue  2.Dequeue  3.Front  4.Rear  5.Display  6.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) return 0;
        if (choice == 6) { printf("Exiting...\n"); break; }
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &x); enqueue(&q, x); break;
            case 2: dequeue(&q); break;
            case 3: display_front(&q); break;
            case 4: display_rear(&q); break;
            case 5: display(&q); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
