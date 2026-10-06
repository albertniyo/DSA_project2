# Question 1 — Airport Baggage Handling Priority Queue

We manage baggage containers with priority scores using an array-based Max-Heap so the highest priority is always processed first.

**Each heap element keeps:**
1. Container ID (uppercase letter: A, B, C, ...)
2. Priority score

**Priority scores used:**
`P = {56, 23, 91, 34, 72, 48, 85, 17, 63, 79, 42}` mapped to IDs `A` through `K`.

To run our C program use:
```bash
gcc main.c q1.c -o q1

./q1
```

The program builds the Max-Heap, inserts urgent container `X` with priority `100`, then removes it (extract-max), showing the heap after each step.

## Data Structure

Containers are stored in a fixed array of `baggage` structs (`id` + `priority`). Both fields move together on every swap so IDs stay tied to their scores.

## What the program does

1. **Build Max-Heap** start from the given array and heapify bottom-up with downward heapify.
2. **Insert X (100)** append at the end and bubble up (upward heapify) until the Max-Heap property holds.
3. **Remove X** extract the root, move the last element to the root, then downward heapify.

## Files

| File | Role |
|------|------|
| `main.h` | `baggage` struct and function prototypes |
| `q1.c` | heap build, insert, delete, display |
| `main.c` | demo of build >> insert X >> remove X |
