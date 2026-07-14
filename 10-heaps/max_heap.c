// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 10 (PDF label 11b) - Max-Heap
// Insert + Delete root (maximum element)

#include <stdio.h>

#define MAX 64

static int heap[MAX];
static int size = 0;

static int parent(int i) { return (i - 1) / 2; }
static int left  (int i) { return 2 * i + 1; }
static int right (int i) { return 2 * i + 2; }

static void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void insert_heap(int v) {
    if (size >= MAX) { printf("Heap is full\n"); return; }
    heap[size] = v;
    int i = size++;
    while (i > 0 && heap[i] > heap[parent(i)]) {
        swap(&heap[i], &heap[parent(i)]);
        i = parent(i);
    }
    printf("Inserted %d\n", v);
}

void heapify_down(int i) {
    int largest = i;
    int l = left(i), r = right(i);
    if (l < size && heap[l] > heap[largest]) largest = l;
    if (r < size && heap[r] > heap[largest]) largest = r;
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify_down(largest);
    }
}

void delete_max(void) {
    if (size == 0) { printf("Heap is empty\n"); return; }
    int root = heap[0];
    heap[0] = heap[size - 1];
    --size;
    heapify_down(0);
    printf("Deleted max = %d\n", root);
}

void display(void) {
    if (size == 0) { printf("Heap is empty\n"); return; }
    printf("Max-Heap array: ");
    for (int i = 0; i < size; ++i) printf("%d ", heap[i]);
    printf("\n");
}

int main(void) {
    int choice, v;
    printf("=== Max-Heap ===\n");
    printf("1.Insert  2.DeleteMax  3.Display  4.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) return 0;
        if (choice == 4) { printf("Exiting...\n"); break; }
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &v); insert_heap(v); break;
            case 2: delete_max(); break;
            case 3: display(); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
