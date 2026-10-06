#include "main.h"
#include <stdio.h>
#include <limits.h>

int name_to_index(char c) {
    if (c >= 'a' && c <= 'z')
        c = c - 'a' + 'A';

    for (int i = 0; i < vlimit; i++) {
        if (names[i] == c)
            return i;
    }
    return -1;
}

char index_to_name(int i) {
    if (i < 0 || i >= vlimit)
        return '?';
    return names[i];
}

static void print_path(int pred[], int v) {
    if (v == -1)
        return;

    if (pred[v] != -1) {
        print_path(pred, pred[v]);
        printf(" >> ");
    }
    
    printf("%c", names[v]);
}

void bellman_ford(int source, Edge edges[], int m) {
    int dist[vlimit];
    int pred[vlimit];

    for (int i = 0; i < vlimit; i++) {
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    dist[source] = 0;

    for (int i = 1; i <= vlimit - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int cost = edges[j].cost;

            if (dist[u] != INT_MAX && dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                pred[v] = u;
            }
        }
    }

    int negative_cycle = 0;

    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int cost = edges[j].cost;

        if (dist[u] != INT_MAX && dist[u] + cost < dist[v]) {
            negative_cycle = 1;
            break;
        }
    }

    printf("Source: %c\n", names[source]);
    puts("Destination\tShortest Cost\tPath\n");

    for (int v = 0; v < vlimit; v++) {
        if (v == source)
            continue;

        printf("%c\t\t", names[v]);

        if (dist[v] == INT_MAX) {
            puts("unreacheable\t-");
        } else {
            printf("%d\t\t", dist[v]);
            print_path(pred, v);
            printf("\n");
        }
    }

    if (negative_cycle) {
        puts("\nNegative-weight cycle detected");
        puts("Shortest-path results may be undefined");
    } else {
        puts("\nNo negative-weight cycle detected");
    }
}
