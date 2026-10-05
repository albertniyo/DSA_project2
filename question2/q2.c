#include "main.h"
#include <stdio.h>

// swaping helper function
static void swap(patient *a, patient *b) {
    patient t = *a;
    *a = *b;
    *b = t;
}

// heapify downward helper function
static void down_heapify(patient a[], int n, int i) {
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

void build_maxheap(patient a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        down_heapify(a, n, i);
    }
}

void insert_patient(patient a[], int *n, patient item) {
    int i = *n;
    a[i] = item;
    (*n)++;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (a[parent].priority >= a[i].priority) {
            break;
        }
        swap(&a[parent], &a[i]);
        i = parent;
    }
}

patient extract_max(patient a[], int *n) {
    patient out = a[0];
    (*n)--;

    if (*n > 0) {
        a[0] = a[*n];
        down_heapify(a, *n, 0);
    }

    return out;
}

void display_heap(const patient a[], int n) {
    puts("Heap Array ");
    for (int i=0; i < n; i++) {
        printf("%c - %s - %s - %d\n", i, a[i].id, a[i].name, a[i].priority);
    }
}
