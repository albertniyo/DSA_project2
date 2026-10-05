#ifndef MAIN_H
#define MAIN_H

#define vlimit 7
#define max_nber 20

typedef struct {
    int u;
    int v;
    int cost;
} edge;

static const char names[vlimit] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

void display_adj_matrix();
int kruskal_algo(edge ed[], int m, edge final[]);

#endif
