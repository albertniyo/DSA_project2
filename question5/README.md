# Question5 — Cloud Service Data Routing Analyzer

We find the minimum cumulative transfer cost from a source data center to every other center on a weighted **directed** graph. Some routes have negative costs, so we use Bellman–Ford instead of Dijkstra.

**Directed routes :**

| From | To | Cost |
|------|----|------|
| A | B | 6 |
| A | D | 16 |
| B | C | 6 |
| B | D | 6 |
| B | J | 7 |
| C | G | -9 |
| D | E | 7 |
| D | J | 8 |
| E | F | 10 |
| E | I | -2 |
| F | G | 4 |
| F | I | 2 |
| G | H | 13 |
| I | F | 2 |
| J | E | 3 |

To run our C program use:
```bash
gcc main.c q5.c -o q5

./q5
```

Enter a source data center (`A`–`J`). Default intended source for the assignment is `A`. Invalid names exit cleanly.

## Data Structure

- Data centers `A`–`J` as vertices (`vlimit = 10`).
- Routes stored as a directed edge list (`u`, `v`, `cost`).
- Distance + predecessor arrays so we can reconstruct each shortest path.
- Extra relaxation pass detects a negative-weight cycle reachable from the source.

## What the program does

1. **Graph model** directed weighted edge list suitable for shortest paths.
2. **Bellman–Ford** relax all edges `|V| - 1` times from the chosen source.
3. **Negative weights** handled naturally.
4. **Negative-cycle check** one more pass; report if a reachable negative cycle exists.
5. **Routing table** for each destination as shortest cost + path.

## Files

| File | Role |
|------|------|
| `main.h` | Edge, station names, prototypes |
| `q5.c` | Bellman–Ford, path print, cycle detection |
| `main.c` | edge list, source input, run algorithm |
