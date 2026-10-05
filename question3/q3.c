#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int cmp_edge(const void *a, const void *b) {
    const edge *x = a;
    const edge *y = b;
    return x->cost - y->cost;
}

static int find_parent(int parent[], int i) {
    while (parent[i] != i) {
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}

void display_adj_matrix() {
    int adj[vlimit][vlimit] = {
        {0, 6, 0, 12, 0, 0, 0},
        {6, 0, 11, 5, 0, 0, 0},
        {0, 11, 0, 17, 0, 0, 25},
        {12, 5, 17, 0, 22, 15, 0},
        {0, 0, 0, 22, 0, 10, 0},
        {0, 0, 0, 15, 10, 0, 22},
        {0, 0, 25, 0, 0, 22, 0}
    };

    printf("\nEV charging-station network\n  adjacency matrix \n  ");
    for (int i = 0; i < vlimit; i++)
        printf("%c ", names[i]);
    printf("\n");

    for (int i = 0; i < vlimit; i++) {
        printf("%c ", names[i]); // printing row per row
        for (int j = 0; j < vlimit; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int kruskal_algo(edge ed[], int m, edge final[]) {
    int parent[vlimit];
    for (int i = 0; i < vlimit; i++)
        parent[i] = i;

    qsort(ed, m, sizeof(edge), cmp_edge);

    int k = 0;
    for (int i = 0; i < m; i++) {
        int ru = find_parent(parent, ed[i].u);
        int rv = find_parent(parent, ed[i].v);

        if (ru != rv) {
            final[k++] = ed[i];
            parent[ru] = rv;
        }
    }
    return k;
}
