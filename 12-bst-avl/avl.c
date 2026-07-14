// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 12 (PDF label 13b) - AVL Tree
// Single (LL, RR) and Double (LR, RL) rotations after insertion

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int height;
    struct Node *left, *right;
} Node;

static int height(const Node *n) { return n ? n->height : 0; }
static int max(int a, int b) { return a > b ? a : b; }
static int balance_factor(const Node *n) { return n ? height(n->left) - height(n->right) : 0; }

static Node* new_node(int v) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = v; n->height = 1; n->left = n->right = NULL;
    return n;
}

/* Right rotation (LL case) */
static Node* right_rotate(Node *y) {
    Node *x  = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left  = T2;
    y->height = 1 + max(height(y->left),  height(y->right));
    x->height = 1 + max(height(x->left),  height(x->right));
    return x;
}

/* Left rotation (RR case) */
static Node* left_rotate(Node *x) {
    Node *y  = x->right;
    Node *T2 = y->left;
    y->left  = x;
    x->right = T2;
    x->height = 1 + max(height(x->left),  height(x->right));
    y->height = 1 + max(height(y->left),  height(y->right));
    return y;
}

Node* insert(Node *root, int v) {
    if (!root) return new_node(v);
    if (v < root->data)      root->left  = insert(root->left,  v);
    else if (v > root->data) root->right = insert(root->right, v);
    else                     return root;   /* duplicates not allowed */

    root->height = 1 + max(height(root->left), height(root->right));
    int bf = balance_factor(root);

    /* LL */
    if (bf > 1 && v < root->left->data)              return right_rotate(root);
    /* RR */
    if (bf < -1 && v > root->right->data)            return left_rotate(root);
    /* LR */
    if (bf > 1 && v > root->left->data)  { root->left  = left_rotate(root->left);  return right_rotate(root); }
    /* RL */
    if (bf < -1 && v < root->right->data){ root->right = right_rotate(root->right); return left_rotate(root); }

    return root;
}

void preorder(const Node *r) {
    if (!r) return;
    printf("%d ", r->data);
    preorder(r->left);
    preorder(r->right);
}

void inorder(const Node *r) {
    if (!r) return;
    inorder(r->left);
    printf("%d ", r->data);
    inorder(r->right);
}

void free_tree(Node *r) {
    if (!r) return;
    free_tree(r->left); free_tree(r->right); free(r);
}

int main(void) {
    Node *root = NULL;
    int choice, v;
    printf("=== AVL Tree ===\n");
    printf("1.Insert  2.Preorder  3.Inorder  4.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) { free_tree(root); return 0; }
        if (choice == 4) { printf("Exiting...\n"); free_tree(root); break; }
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &v); root = insert(root, v); break;
            case 2: printf("Preorder: "); preorder(root); printf("\n"); break;
            case 3: printf("Inorder : "); inorder(root);  printf("\n"); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
