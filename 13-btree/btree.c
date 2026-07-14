// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 13 (PDF label 14) - B-Tree of order 3
// Insertion and inorder traversal

#include <stdio.h>
#include <stdlib.h>

#define T 2   /* minimum degree; max keys = 2T-1 = 3, order = 4 in classic terms.
                 The PDF specifies order-3 (max 2 keys, max 3 children). */

/* For order-3 B-tree: max 2 keys, max 3 children */
#define MAX_KEYS   2
#define MAX_CHILD  3

typedef struct BNode {
    int keys[MAX_KEYS + 1];          /* 1 extra for split overflow */
    struct BNode *children[MAX_CHILD + 1];
    int n;
    int leaf;
} BNode;

static BNode* new_bnode(int leaf) {
    BNode *n = (BNode*)malloc(sizeof(BNode));
    n->n = 0; n->leaf = leaf;
    for (int i = 0; i <= MAX_KEYS; ++i) n->keys[i] = 0;
    for (int i = 0; i <= MAX_CHILD; ++i) n->children[i] = NULL;
    return n;
}

static void split_child(BNode *x, int i) {
    BNode *y = x->children[i];
    BNode *z = new_bnode(y->leaf);

    /* order-3: y has 2 keys (max). After split, y keeps key[0], z gets key[1] */
    z->n = 1;
    z->keys[0] = y->keys[1];
    if (!y->leaf) {
        z->children[0] = y->children[1];
        z->children[1] = y->children[2];
    }
    y->n = 1;  /* keep only key[0] */

    /* shift x's children right to insert z */
    for (int j = x->n; j >= i + 1; --j) x->children[j+1] = x->children[j];
    x->children[i+1] = z;
    for (int j = x->n - 1; j >= i; --j) x->keys[j+1] = x->keys[j];
    x->keys[i] = y->keys[1];   /* promote middle key */
    x->n++;
}

static void insert_nonfull(BNode *x, int k) {
    int i = x->n - 1;
    if (x->leaf) {
        while (i >= 0 && x->keys[i] > k) { x->keys[i+1] = x->keys[i]; --i; }
        x->keys[i+1] = k;
        x->n++;
    } else {
        while (i >= 0 && x->keys[i] > k) --i;
        ++i;
        if (x->children[i]->n == MAX_KEYS) {
            split_child(x, i);
            if (x->keys[i] < k) ++i;
        }
        insert_nonfull(x->children[i], k);
    }
}

BNode* insert(BNode *root, int k) {
    if (!root) {
        root = new_bnode(1);
        root->keys[0] = k;
        root->n = 1;
        return root;
    }
    if (root->n == MAX_KEYS) {
        BNode *s = new_bnode(0);
        s->children[0] = root;
        split_child(s, 0);
        insert_nonfull(s, k);
        return s;
    }
    insert_nonfull(root, k);
    return root;
}

void traverse(const BNode *root) {
    if (!root) return;
    int i;
    for (i = 0; i < root->n; ++i) {
        if (!root->leaf) traverse(root->children[i]);
        printf("%d ", root->keys[i]);
    }
    if (!root->leaf) traverse(root->children[i]);
}

void free_btree(BNode *root) {
    if (!root) return;
    for (int i = 0; i <= root->n; ++i) free_btree(root->children[i]);
    free(root);
}

int main(void) {
    BNode *root = NULL;
    int choice, v;
    printf("=== B-Tree (order 3, max 2 keys/node) ===\n");
    printf("1.Insert  2.Traverse  3.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) { free_btree(root); return 0; }
        if (choice == 3) { printf("Exiting...\n"); free_btree(root); break; }
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &v); root = insert(root, v); break;
            case 2: printf("Traversal: "); traverse(root); printf("\n"); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
