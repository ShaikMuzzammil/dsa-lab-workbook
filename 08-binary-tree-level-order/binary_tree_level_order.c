// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 8 (PDF label 9) - Binary Tree Linked Structure + Level-Order Traversal

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* new_node(int v) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = v; n->left = n->right = NULL;
    return n;
}

/* Simple array-based queue for level-order traversal */
#define QCAP 64
typedef struct {
    Node *a[QCAP];
    int front, rear;
} Queue;
void q_init(Queue *q) { q->front = q->rear = -1; }
int  q_empty(const Queue *q) { return q->front == -1 || q->front > q->rear; }
void q_push(Queue *q, Node *n) {
    if (q->rear == QCAP - 1) return;
    if (q->front == -1) q->front = 0;
    q->a[++(q->rear)] = n;
}
Node* q_pop(Queue *q) {
    if (q_empty(q)) return NULL;
    Node *r = q->a[q->front++];
    if (q->front > q->rear) q->front = q->rear = -1;
    return r;
}

void level_order(Node *root) {
    if (!root) { printf("(empty)\n"); return; }
    Queue q; q_init(&q);
    q_push(&q, root);
    printf("Level-order: ");
    while (!q_empty(&q)) {
        Node *cur = q_pop(&q);
        printf("%d ", cur->data);
        if (cur->left)  q_push(&q, cur->left);
        if (cur->right) q_push(&q, cur->right);
    }
    printf("\n");
}

void free_tree(Node *r) {
    if (!r) return;
    free_tree(r->left);
    free_tree(r->right);
    free(r);
}

int main(void) {
    /* Build:
              1
            /   \
           2     3
          / \     \
         4   5     6
                    \
                     7
    */
    Node *root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->right->right = new_node(6);
    root->right->right->right = new_node(7);

    printf("Binary Tree (linked structure):\n");
    printf("        1\n      /   \\\n     2     3\n    / \\     \\\n   4  5      6\n              \\\n               7\n\n");
    level_order(root);
    free_tree(root);
    return 0;
}
