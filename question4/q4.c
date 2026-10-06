#include "main.h"
#include <stdio.h>

int index_of(char c) {
    if (c >= 'a' && c <= 'z')
        c = c - 'a' + 'A';

    for (int i = 0; i < vlimit; i++) {
        if (names[i] == c)
            return i;
    }
    return -1;
}

void bfs_conn_analysis(char start) {
    int s = index_of(start);

    int visited[vlimit] = {0};
    int queue[vlimit];
    int front = 0;
    int rear = 0;

    visited[s] = 1;
    queue[rear++] = s;

    printf("BFS traversal starting from %c:\n", names[s]);

    while (front < rear) {
        int u = queue[front++];
        printf("%c ", names[u]);

        for (int v = 0; v < vlimit; v++) {
            if (adj[u][v] != 0 && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");

    printf("\nGateways directly connected to %c:\n", names[s]);

    int max_time = -1;
    int max_gateway = -1;

    for (int v = 0; v < vlimit; v++) {
        if (adj[s][v] != 0) {
            printf("%c - %d ms\n", names[v], adj[s][v]);
            if (adj[s][v] > max_time) {
                max_time = adj[s][v];
                max_gateway = v;
            }
        }
    }

    if (max_gateway != -1) {
        printf("\nHighest direct transfer time: %c - %d ms\n",
               names[max_gateway], max_time);
    }
}
