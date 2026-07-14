// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise 14 (PDF label 15) - DAG + Topological Sorting using DFS

#include <stdio.h>
#include <stdlib.h>

#define MAX_V 32

typedef struct Node {
    int v;
    struct Node *next;
} Node;

static Node *adj[MAX_V];
static int  visited[MAX_V];
static int  stack[MAX_V];
static int  top_idx = 0;
static int  V = 0;

static void add_edge(int u, int v) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->v = v; n->next = adj[u];
    adj[u] = n;
}

static void dfs(int v) {
    visited[v] = 1;
    for (Node *p = adj[v]; p; p = p->next)
        if (!visited[p->v]) dfs(p->v);
    stack[top_idx++] = v;
}

static void topological_sort(void) {
    for (int i = 0; i < V; ++i) if (!visited[i]) dfs(i);
    printf("Topological Sort: ");
    while (top_idx > 0) printf("%d ", stack[--top_idx]);
    printf("\n");
}

static void free_graph(void) {
    for (int i = 0; i < V; ++i) {
        Node *p = adj[i];
        while (p) { Node *t = p->next; free(p); p = t; }
        adj[i] = NULL;
    }
}

int main(void) {
    int edges, u, v;
    printf("=== DAG Topological Sort (DFS) ===\n");
    printf("Enter number of vertices: ");
    if (scanf("%d", &V) != 1 || V <= 0 || V > MAX_V) { printf("Invalid\n"); return 1; }
    for (int i = 0; i < V; ++i) { adj[i] = NULL; visited[i] = 0; }

    printf("Enter number of directed edges: ");
    if (scanf("%d", &edges) != 1 || edges < 0) { printf("Invalid\n"); return 1; }
    printf("Enter %d edges (u v means u -> v):\n", edges);
    for (int i = 0; i < edges; ++i) {
        if (scanf("%d %d", &u, &v) != 2 || u < 0 || u >= V || v < 0 || v >= V) {
            printf("Invalid edge\n"); --i; continue;
        }
        add_edge(u, v);
    }

    printf("\nGraph adjacency list:\n");
    for (int i = 0; i < V; ++i) {
        printf("  %d ->", i);
        for (Node *p = adj[i]; p; p = p->next) printf(" %d", p->v);
        printf("\n");
    }
    printf("\n");
    topological_sort();
    free_graph();
    return 0;
}
