# Question 3 — EV Charging Station Power Network

We connect EV charging stations to the city power network at minimum total cable cost. The network is an undirected weighted graph where we find a Minimum Spanning Tree with Kruskal’s Algorithm.

**Available connections (cost in thousands of dollars):**

| Connection | Cost |
|------------|------|
| A — B | 6 |
| A — D | 12 |
| B — D | 5 |
| B — C | 11 |
| C — D | 17 |
| C — G | 25 |
| D — E | 22 |
| D — F | 15 |
| E — F | 10 |
| F — G | 22 |

To run our C program use:
```bash
gcc main.c q3.c -o q3

./q3
```

The program prints the adjacency matrix, runs Kruskal, lists the selected cables, and prints the total installation cost.

## Data Structure

- Stations `A`–`G` as vertices (`vlimit = 7`).
- Possible cables stored as an edge list (`u`, `v`, `cost`).
- Undirected graph shown as a symmetric adjacency matrix (`0` = no direct link).
- Union-Find (`find_parent` with path compression) rejects edges that would form a cycle.

## What the program does

1. **Adjacency matrix** print the undirected weighted graph.
2. **Kruskal** sort edges by increasing cost, add an edge only when its endpoints are in different components.
3. **Selected connections** print each MST edge as `Station — Station : Cost`.
4. **Total cost** sum of selected edge costs (exactly `v - 1` edges, no cycles).

## Files

| File | Role |
|------|------|
| `main.h` | `edge` struct, station names, prototypes |
| `q3.c` | adjacency matrix display + Kruskal |
| `main.c` | edge list setup and result printing |
