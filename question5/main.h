#ifndef MAIN_H
#define MAIN_H

#define vlimit 10
#define max 32
static const char names[vlimit] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

typedef struct {
    int u;
    int v;
    int cost;
} Edge;

int name_to_index(char c);
char index_to_name(int i);
void bellman_ford(int source, Edge edges[], int m);

#endif
