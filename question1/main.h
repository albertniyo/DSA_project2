#ifndef MAIN_H
#define MAIN_H

typedef struct{
    char id;
    int priority;
} baggage;

void build_maxheap(baggage a[], int n);
void insert_luggage(baggage a[], int *n, baggage item);
baggage heap_del(baggage a[], int *n);
void display_heap(const baggage a[], int n);

#endif
