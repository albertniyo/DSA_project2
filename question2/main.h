#ifndef MAIN_H
#define MAIN_H

typedef struct{
    char id[8];
    char name[12];
    int priority;
} patient;

void build_maxheap(patient *a, int n);
void insert_patient(patient *a, int *n, patient item);
patient extract_max(patient a[], int *n);
void display_heap(const patient a[], int n);

#endif
