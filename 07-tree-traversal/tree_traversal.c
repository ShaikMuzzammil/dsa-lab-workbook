// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 7 (PDF label 8) - Tree Traversal
// Recursive + Iterative Preorder, Inorder, Postorder

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

/* Recursive traversals */
void rec_preorder (const Node *r) { if (!r) return; printf("%d ", r->data); rec_preorder(r->left);  rec_preorder(r->right); }
void rec_inorder  (const Node *r) { if (!r) return; rec_inorder(r->left);  printf("%d ", r->data); rec_inorder(r->right); }
void rec_postorder(const Node *r) { if (!r) return; rec_postorder(r->left); rec_postorder(r->right); printf("%d ", r->data); }

/* Iterative traversals using explicit stack */
#define CAP 64
typedef struct { const Node *a[CAP]; int top; } Stack;
void s_init(Stack *s) { s->top = -1; }
int  s_empty(const Stack *s) { return s->top == -1; }
void s_push(Stack *s, const Node *n) { if (s->top < CAP-1) s->a[++(s->top)] = n; }
const Node* s_pop(Stack *s) { return s->top >= 0 ? s->a[(s->top)--] : NULL; }

void iter_preorder(const Node *r) {
    if (!r) return;
    Stack s; s_init(&s); s_push(&s, r);
    while (!s_empty(&s)) {
        const Node *cur = s_pop(&s);
        printf("%d ", cur->data);
        if (cur->right) s_push(&s, cur->right);
        if (cur->left)  s_push(&s, cur->left);
    }
}

void iter_inorder(const Node *r) {
    Stack s; s_init(&s);
    const Node *cur = r;
    while (cur || !s_empty(&s)) {
        while (cur) { s_push(&s, cur); cur = cur->left; }
        cur = s_pop(&s);
        printf("%d ", cur->data);
        cur = cur->right;
    }
}

void iter_postorder(const Node *r) {
    if (!r) return;
    Stack s1, s2; s_init(&s1); s_init(&s2);
    s_push(&s1, r);
    while (!s_empty(&s1)) {
        const Node *cur = s_pop(&s1);
        s_push(&s2, cur);
        if (cur->left)  s_push(&s1, cur->left);
        if (cur->right) s_push(&s1, cur->right);
    }
    while (!s_empty(&s2)) {
        const Node *cur = s_pop(&s2);
        printf("%d ", cur->data);
    }
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
          / \   / \
         4   5 6   7
    */
    Node *root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->right->left = new_node(6);
    root->right->right = new_node(7);

    printf("Tree:\n        1\n      /   \\\n     2     3\n    / \\   / \\\n   4  5  6  7\n\n");

    printf("Recursive Preorder : "); rec_preorder(root);  printf("\n");
    printf("Iterative Preorder : "); iter_preorder(root);  printf("\n\n");

    printf("Recursive Inorder  : "); rec_inorder(root);   printf("\n");
    printf("Iterative Inorder  : "); iter_inorder(root);   printf("\n\n");

    printf("Recursive Postorder: "); rec_postorder(root); printf("\n");
    printf("Iterative Postorder: "); iter_postorder(root); printf("\n");

    free_tree(root);
    return 0;
}
