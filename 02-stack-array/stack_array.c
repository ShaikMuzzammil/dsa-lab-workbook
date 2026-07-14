// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 2 - Stack using Array
// Operations: push, pop, peek, display with overflow/underflow handling

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void init(Stack *s)        { s->top = -1; }
int  is_empty(const Stack *s) { return s->top == -1; }
int  is_full (const Stack *s) { return s->top == MAX - 1; }

void push(Stack *s, int x) {
    if (is_full(s)) { printf("Stack Overflow\n"); return; }
    s->arr[++(s->top)] = x;
    printf("Pushed %d\n", x);
}

void pop(Stack *s) {
    if (is_empty(s)) { printf("Stack Underflow\n"); return; }
    printf("Popped %d\n", s->arr[(s->top)--]);
}

void peek(const Stack *s) {
    if (is_empty(s)) { printf("Stack is empty\n"); return; }
    printf("Top element = %d\n", s->arr[s->top]);
}

void display(const Stack *s) {
    if (is_empty(s)) { printf("Stack is empty\n"); return; }
    printf("Stack (top -> bottom): ");
    for (int i = s->top; i >= 0; --i) printf("%d ", s->arr[i]);
    printf("\n");
}

int main(void) {
    Stack s; init(&s);
    int choice, x;
    printf("=== Stack using Array (MAX=%d) ===\n", MAX);
    printf("1.Push  2.Pop  3.Peek  4.Display  5.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) return 0;
        if (choice == 5) { printf("Exiting...\n"); break; }
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &x); push(&s, x); break;
            case 2: pop(&s); break;
            case 3: peek(&s); break;
            case 4: display(&s); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
