#include "main.h"
#include <stdio.h>

int main() {
    char input;

    printf("Enter starting gateway: ");
    if (scanf(" %c", &input) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (index_of(input) < 0) {
        printf("Invalid gateway name.\n");
        return 1;
    }

    bfs_conn_analysis(input);

    return 0;
}
