# Question4 — IoT Gateway Connectivity Analyzer

We analyze IoT gateway connectivity on an undirected graph where each node is a gateway; each edge weight is average data-transfer time in milleseconds. We use BFS (queue-based) from a user-chosen start gateway.

**Gateway network:**

| Gateway 1 | Gateway 2 | Transfer time (ms) |
|-----------|-----------|--------------------|
| A | B | 6 |
| A | D | 12 |
| B | D | 5 |
| B | C | 11 |
| C | D | 17 |
| C | G | 25 |
| D | E | 22 |
| D | F | 15 |
| E | F | 10 |
| F | G | 22 |

To run our C program use:
```bash
gcc main.c q4.c -o q4

./q4
```

When prompted, enter a starting gateway (example: `D`). Invalid names are rejected gracefully.

## Data Structure

- Gateways `A`–`G` stored as vertices.
- Network stored as an adjacency matrix (`0` = no link).
- BFS uses a simple array-backed queue (`front` / `rear`).

## What the program does

1. **Gateway selection** read start gateway and validate it exists.
2. **BFS connectivity** traverse with a queue from that gateway and print discovery order.
3. **Direct neighbors** list one-hop gateways and their transfer times.
4. **Highest transfer time** among direct neighbors, report the gateway with the largest link time.

## Files

| File | Role |
|------|------|
| `main.h` | names, adjacency matrix, prototypes |
| `q4.c` | `index_of` + BFS / neighbor analysis |
| `main.c` | input validation and entry point |
