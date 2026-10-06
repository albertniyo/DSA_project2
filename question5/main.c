#include "main.h"
#include <stdio.h>

int main(void) {
    Edge edges[] = {
        {0, 1, 6},    // A -> B
        {0, 3, 16},   // A -> D
        {1, 2, 6},    // B -> C
        {1, 3, 6},    // B -> D
        {1, 9, 7},    // B -> J
        {2, 6, -9},   // C -> G
        {3, 4, 7},    // D -> E
        {3, 9, 8},    // D -> J
        {4, 5, 10},   // E -> F
        {4, 8, -2},   // E -> I
        {5, 6, 4},    // F -> G
        {5, 8, 2},    // F -> I
        {6, 7, 13},   // G -> H
        {8, 5, 2},    // I -> F
        {9, 4, 3}     // J -> E
    };

    int m = sizeof(edges) / sizeof(edges[0]);

    char input;
    char source = 'A';

    printf("Enter source data center (A-J): ");
    if (scanf(" %c", &input) == 1) {
        source = input;
    }

    int s = name_to_index(source);
    if (s < 0) {
        printf("Invalid data-center name\n");
        return 1;
    }

    bellman_ford(s, edges, m);

    return 0;
}
