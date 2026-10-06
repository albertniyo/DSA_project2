#include "main.h"
#include <stdio.h>

int main() {

    baggage heap[20] = {
        {'A', 56}, {'B', 23}, {'C', 91}, {'D', 34},
        {'E', 72}, {'F', 48}, {'G', 85}, {'H', 17},
        {'I', 63}, {'J', 79}, {'K', 42}
    };

    int n = 11;

    build_maxheap(heap, n);

    puts("Max-heap after build: ");
    display_heap(heap, n);

    // adding a new luggage
    baggage new = {'X', 100};
    insert_luggage(heap, &n, new);
    puts("\nMax-Heap after inserting X:100");
    display_heap(heap, n);

    baggage removed = heap_del(heap, &n);
    printf("\nMax-Heap after removing %c:%d\n", removed.id, removed.priority);
    display_heap(heap, n);
    
    return 0;
}
