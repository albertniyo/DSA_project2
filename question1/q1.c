#include "main.h"
#include <stdio.h>

// swaping helper function
static void swap(baggage *a, baggage *b) {
    baggage t = *a;
    *a = *b;
    *b = t;
}

// heapify downward helper function
static void down_heapify(baggage a[], int n, int i) {
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int max = i;

        if (left < n && a[left].priority > a[max].priority) {
            max = left;
        }
        if (right < n && a[right].priority > a[max].priority){
            max = right;
        }

        if (max != i) {
            swap(&a[i], &a[max]);
            i = max;
        } else {
            break;
        }
    }
}

// heapify upward helper function
static void up_heapify(baggage a[], int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (a[parent].priority >= a[i].priority) {
            break;
        }
        swap(&a[parent], &a[i]);
        i = parent;
    }
}

void build_maxheap(baggage a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        down_heapify(a, n, i);
    }
}

void insert_luggage(baggage a[], int *n, baggage item) {
    int i = *n;
    a[i] = item;
    (*n)++;
    up_heapify(a, i);
}

baggage heap_del(baggage a[], int *n) {
    baggage out = a[0];
    (*n)--;

    if (*n > 0) {
        a[0] = a[*n];
        down_heapify(a, *n, 0);
    }

    return out;
}

void display_heap(const baggage a[], int n) {
    puts("Heap Array ");
    for (int i=0; i < n; i++) {
        printf("[%d] %c: %d\n", i, a[i].id, a[i].priority);
    }

    // minimal tree view by levels
    puts("\nHeap Tree ");
    int level = 0;
    int i = 0;
    while (i < n) {
        int count = 1 << level;
        for (int j = 0; j < count && i < n; j++, i++) {
            printf("%c:%d ", a[i].id, a[i].priority);
        }
        puts("");
        level++;
    }
}
