#include "main.h"
#include <stdio.h>

int main() {

    baggage heap[20] = {
        {'A', 56}, {'B', 23}, {'C', 91}, {'D', 34},
        {'E', 72}, {'F', 48}, {'G', 85}, {'H', 17},
        {'I', 63}, {'J', 79}, {'K', 42}
    };

    int n = 11;

    puts("Starting array: ");
    display_heap(heap, n);

    build_maxheap(heap, n);

    puts("Max-heap after build: ");
    display_heap(heap, n);

    // adding a new luggage
    baggage new = {'X', 100};
    insert_luggage(heap, &n, new);
    printf("Max heap after inserting luggage %c:%d\n", new.id, new.priority);
    display_heap(heap, n);

    // remowing a luggage
    baggage removed = heap_del(heap, &n);
    printf("Remove luggage %c:%d\n", removed.id, removed.priority);
    display_heap(heap, n);
    
    return 0;
}
