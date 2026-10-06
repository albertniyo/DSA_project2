# Question2 — Hospital Emergency Triage Priority System

We manage emergency patients with an array-based Max-Heap so higher triage scores are treated first.

**Each heap element keeps:**
1. Patient ID
2. Patient name
3. Priority score

**Patients waiting:**

| ID | Name | Priority |
|----|------|----------|
| P01 | Amina | 72 |
| P02 | Daniel | 45 |
| P03 | Eric | 91 |
| P04 | Grace | 63 |
| P05 | Hassan | 88 |
| P06 | Irene | 54 |
| P07 | Jean | 76 |

To run our C program use:
```bash
gcc main.c q2.c -o q2

./q2
```

The program builds the Max-Heap, prints treatment order by repeated extract-max, inserts Kofi (Id of `P08` and priority of `98`), then clears that patient and shows the heap again.

## Data Structure

Patients live in a fixed array of `patient` structs (`id`, `name`, `priority`). Swaps move the whole struct so ID, name, and score stay together.

## What the program does

1. **Build Max-Heap** convert the patient list into a valid Max-Heap (highest priority will be at the root).
2. **Treatment order** copy the heap and repeatedly extract the max to list patients from highest to lowest priority.
3. **Insert P08 (Kofi, 98)** insert and restore the Max-Heap property with upward heapify.
4. **Clear P08** extract-max and then downward heapify.

## Files

| File | Role |
|------|------|
| `main.h` | `patient` struct and prototypes |
| `q2.c` | heap build, insert, extract-max, display |
| `main.c` | build >> treatment order >> insert >> clear |
