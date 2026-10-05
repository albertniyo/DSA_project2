#include "main.h"
#include <stdio.h>

int main() {
    patient heap[10] = {
        {"P01", "Amina", 72}, {"P02", "Daniel", 45}, 
        {"P03", "Eric", 91}, {"P04", "Grace", 63}, 
        {"P05", "Hassan", 88},{"P06", "Irene", 54}, 
        {"P07", "Jean", 76}
    };

    int n = 7;
    build_maxheap(heap, n);

    puts("Starting array: ");
    display_heap(heap, n);

    patient copy[10];
    int m = n;
    for (int i=0; i < n; i++) {
        copy[i] = heap[i];
    }

    puts("Treatment order from highest to lowest priority");
    while (m > 0) {
        patient p = extract_max(copy, &m);
        printf("%s %s - Priority %d\n", p.id, p.name, p.priority);
    }

    patient new = {"P08", "Kofi", 98};
    insert_patient(heap, &n, new);

    printf("Max heap after inserting %s with priority %d\n", new.name, new.priority);
    display_heap(heap, n);

    patient removed = extract_max(heap, &n);
    printf("Cleared patient %s of Id: %s\n", removed.name, removed.id);
    printf("Max-heap after remoning %s\n", removed.name);
    display_heap(heap, n);
    
    return 0;
}
