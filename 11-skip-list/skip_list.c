// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 11 (PDF label 12) - Skip List
// Operations: insert, delete, search (probabilistic levelling)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVEL 6
#define P         0.5

typedef struct Node {
    int data;
    int level;
    struct Node **forward;
} Node;

static Node *head;
static int   level;

static Node* new_node(int data, int lvl) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->level = lvl;
    n->forward = (Node**)calloc(lvl + 1, sizeof(Node*));
    return n;
}

static int random_level(void) {
    int lvl = 0;
    while ((rand() / (double)RAND_MAX) < P && lvl < MAX_LEVEL) ++lvl;
    return lvl;
}

void init_sl(void) {
    head = new_node(-1, MAX_LEVEL);
    level = 0;
}

Node* search(int key) {
    Node *cur = head;
    for (int i = level; i >= 0; --i) {
        while (cur->forward[i] && cur->forward[i]->data < key)
            cur = cur->forward[i];
    }
    cur = cur->forward[0];
    if (cur && cur->data == key) return cur;
    return NULL;
}

void insert(int key) {
    Node *update[MAX_LEVEL + 1];
    Node *cur = head;
    for (int i = level; i >= 0; --i) {
        while (cur->forward[i] && cur->forward[i]->data < key)
            cur = cur->forward[i];
        update[i] = cur;
    }
    cur = cur->forward[0];
    if (cur && cur->data == key) { printf("%d already exists\n", key); return; }

    int rlevel = random_level();
    if (rlevel > level) {
        for (int i = level + 1; i <= rlevel; ++i) update[i] = head;
        level = rlevel;
    }
    Node *n = new_node(key, rlevel);
    for (int i = 0; i <= rlevel; ++i) {
        n->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = n;
    }
    printf("Inserted %d (level %d)\n", key, rlevel);
}

void delete(int key) {
    Node *update[MAX_LEVEL + 1];
    Node *cur = head;
    for (int i = level; i >= 0; --i) {
        while (cur->forward[i] && cur->forward[i]->data < key)
            cur = cur->forward[i];
        update[i] = cur;
    }
    cur = cur->forward[0];
    if (!cur || cur->data != key) { printf("%d not found\n", key); return; }
    for (int i = 0; i <= level; ++i) {
        if (update[i]->forward[i] != cur) break;
        update[i]->forward[i] = cur->forward[i];
    }
    free(cur->forward);
    free(cur);
    while (level > 0 && !head->forward[level]) --level;
    printf("Deleted %d\n", key);
}

void display(void) {
    printf("Skip List (level %d):\n", level);
    for (int i = level; i >= 0; --i) {
        printf("  L%d: ", i);
        for (Node *p = head->forward[i]; p; p = p->forward[i])
            printf("%d -> ", p->data);
        printf("NULL\n");
    }
}

void free_sl(void) {
    Node *p = head->forward[0];
    while (p) { Node *t = p->forward[0]; free(p->forward); free(p); p = t; }
    free(head->forward); free(head);
}

int main(void) {
    srand((unsigned)time(NULL));
    init_sl();
    int choice, v;
    printf("=== Skip List ===\n");
    printf("1.Insert  2.Delete  3.Search  4.Display  5.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) { free_sl(); return 0; }
        if (choice == 5) { printf("Exiting...\n"); free_sl(); break; }
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &v); insert(v); break;
            case 2: printf("Value: "); scanf("%d", &v); delete(v); break;
            case 3: printf("Value: "); scanf("%d", &v);
                    printf(search(v) ? "Found %d\n" : "%d not found\n", v);
                    break;
            case 4: display(); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
