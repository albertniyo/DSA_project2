#ifndef MAIN_H
#define MAIN_H

#define vlimit 7
static const char names[vlimit] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

static const int adj[vlimit][vlimit] = {
    {0, 6, 0, 12, 0, 0, 0},
    {6, 0, 11, 5, 0, 0, 0},
    {0, 11, 0, 17, 0, 0, 25},
    {12, 5, 17, 0, 22, 15, 0},
    {0, 0, 0, 22, 0, 10, 0},
    {0, 0, 0, 15, 10, 0, 22},
    {0, 0, 25, 0, 0, 22, 0}
};

int index_of(char c);
void bfs_conn_analysis(char start);

#endif
