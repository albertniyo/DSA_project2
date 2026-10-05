#include "main.h"
#include <stdio.h>

int main(void) {
    edge edges[] = {
        {0, 1, 6},   // A - B
        {0, 3, 12},  // A - D
        {1, 3, 5},   // B - D
        {1, 2, 11},  // B - C
        {2, 3, 17},  // C - D
        {2, 6, 25},  // C - G
        {3, 4, 22},  // D - E
        {3, 5, 15},  // D - F
        {4, 5, 10},  // E - F
        {5, 6, 22}   // F - G
    };

    int m = sizeof(edges) / sizeof(edges[0]);

    display_adj_matrix();

    edge final[max_nber];
    int k = kruskal_algo(edges, m, final);

    printf("\nSelected connections:\n");
    int total = 0;
    for (int i = 0; i < k; i++) {
        printf("%c - %c : %d\n",
               names[final[i].u], names[final[i].v], final[i].cost);
        total += final[i].cost;
    }

    printf("\nTotal installation cost: %d thousand dollars\n", total);

    return 0;
}
