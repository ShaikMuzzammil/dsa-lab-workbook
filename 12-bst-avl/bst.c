// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 12 (PDF label 13a) - Binary Search Tree (BST)
// Operations: insert, search, delete, inorder display

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

Node* insert(Node *root, int v) {
    if (!root) return new_node(v);
    if (v < root->data)      root->left  = insert(root->left,  v);
    else if (v > root->data) root->right = insert(root->right, v);
    return root;
}

Node* search(Node *root, int v) {
    if (!root) return NULL;
    if (v == root->data) return root;
    if (v <  root->data) return search(root->left,  v);
    return search(root->right, v);
}

Node* min_node(Node *root) {
    while (root->left) root = root->left;
    return root;
}

Node* delete(Node *root, int v) {
    if (!root) return NULL;
    if (v < root->data)      root->left  = delete(root->left,  v);
    else if (v > root->data) root->right = delete(root->right, v);
    else {
        if (!root->left)  { Node *r = root->right; free(root); return r; }
        if (!root->right) { Node *l = root->left;  free(root); return l; }
        Node *succ = min_node(root->right);
        root->data = succ->data;
        root->right = delete(root->right, succ->data);
    }
    return root;
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void free_tree(Node *r) {
    if (!r) return;
    free_tree(r->left); free_tree(r->right); free(r);
}

int main(void) {
    Node *root = NULL;
    int choice, v;
    printf("=== Binary Search Tree ===\n");
    printf("1.Insert  2.Search  3.Delete  4.Inorder  5.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) { free_tree(root); return 0; }
        if (choice == 5) { printf("Exiting...\n"); free_tree(root); break; }
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &v); root = insert(root, v); break;
            case 2: printf("Value: "); scanf("%d", &v);
                    printf(search(root, v) ? "Found %d\n" : "%d not found\n", v);
                    break;
            case 3: printf("Value: "); scanf("%d", &v); root = delete(root, v); break;
            case 4: printf("Inorder: "); inorder(root); printf("\n"); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
