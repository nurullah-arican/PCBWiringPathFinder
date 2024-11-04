# Shortest Path in PCB Grid

This project finds the shortest route for a wire in a 14x14 PCB grid using a Breadth-First Search (BFS) algorithm. The grid contains unreachable tiles, a starting tile, and a target tile. The program uses a queue data structure to traverse the grid and determine the shortest path from the start to the target.

## Project Overview

- **Grid Size:** 14x14
- **Tiles:**
  - `S` - Start Tile
  - `T` - Target Tile
  - `U` - Unreachable Tile
  - `e` - Empty Tile
  - `W` - Wire (path from Start to Target)

The program places the `START` and `TARGET` tiles randomly within the grid and fills 20 tiles as unreachable. It then performs a BFS algorithm to find the shortest path between the start and target tiles, marking the path with `W` if it exists.

## Features

- **Random Grid Generation:** The grid is initialized with random placement of unreachable tiles, start, and target tiles.
- **Breadth-First Search (BFS):** The algorithm uses BFS to ensure that the shortest path is found.
- **Path Marking:** If a path is found, it is marked on the grid with `W` to visualize the route.

## Usage

### Requirements

- **C++ Compiler:** The code requires a C++ compiler that supports C++11 or higher.

### Compilation and Execution

1. Compile the code with a C++ compiler:
   ```bash
   g++ -o PCBShortestPath PCBShortestPath.cpp
2. Run the program: 
  ./PCBShortestPath

## Output
The program will print the grid after attempting to find the shortest path from the start to the target tile. If a path is found, it will be marked with W; otherwise, a message will indicate that no path was found.

