// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 6 (PDF label 7a) - Singly Linked List
// Insertion/Deletion at beginning, end, and specific position; display

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

static Node *head = NULL;

Node* new_node(int v) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = v; n->next = NULL;
    return n;
}

void ins_begin(int v) {
    Node *n = new_node(v);
    n->next = head; head = n;
    printf("Inserted %d at beginning\n", v);
}

void ins_end(int v) {
    Node *n = new_node(v);
    if (!head) { head = n; }
    else {
        Node *p = head;
        while (p->next) p = p->next;
        p->next = n;
    }
    printf("Inserted %d at end\n", v);
}

void ins_pos(int v, int pos) {
    if (pos < 1) { printf("Invalid position (use 1-based)\n"); return; }
    if (pos == 1) { ins_begin(v); return; }
    Node *p = head;
    for (int i = 1; i < pos - 1 && p; ++i) p = p->next;
    if (!p) { printf("Position out of range\n"); return; }
    Node *n = new_node(v);
    n->next = p->next; p->next = n;
    printf("Inserted %d at position %d\n", v, pos);
}

void del_begin(void) {
    if (!head) { printf("List is empty\n"); return; }
    Node *t = head;
    printf("Deleted %d from beginning\n", t->data);
    head = head->next; free(t);
}

void del_end(void) {
    if (!head) { printf("List is empty\n"); return; }
    Node *p = head;
    if (!p->next) { printf("Deleted %d from end\n", p->data); free(p); head = NULL; return; }
    while (p->next->next) p = p->next;
    printf("Deleted %d from end\n", p->next->data);
    free(p->next); p->next = NULL;
}

void del_pos(int pos) {
    if (!head) { printf("List is empty\n"); return; }
    if (pos < 1) { printf("Invalid position\n"); return; }
    if (pos == 1) { del_begin(); return; }
    Node *p = head;
    for (int i = 1; i < pos - 1 && p->next; ++i) p = p->next;
    if (!p->next) { printf("Position out of range\n"); return; }
    Node *t = p->next;
    printf("Deleted %d from position %d\n", t->data, pos);
    p->next = t->next; free(t);
}

void display(void) {
    if (!head) { printf("List is empty\n"); return; }
    printf("List: ");
    for (Node *p = head; p; p = p->next) printf("%d -> ", p->data);
    printf("NULL\n");
}

void free_all(void) { Node *p = head; while (p) { Node *t = p->next; free(p); p = t; } head = NULL; }

int main(void) {
    int choice, v, pos;
    printf("=== Singly Linked List ===\n");
    printf("1.InsBegin 2.InsEnd 3.InsPos 4.DelBegin 5.DelEnd 6.DelPos 7.Display 8.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) { free_all(); return 0; }
        if (choice == 8) { printf("Exiting...\n"); free_all(); break; }
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &v); ins_begin(v); break;
            case 2: printf("Value: "); scanf("%d", &v); ins_end(v);  break;
            case 3: printf("Value Pos: "); scanf("%d %d", &v, &pos); ins_pos(v, pos); break;
            case 4: del_begin(); break;
            case 5: del_end();   break;
            case 6: printf("Pos: "); scanf("%d", &pos); del_pos(pos); break;
            case 7: display();   break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
