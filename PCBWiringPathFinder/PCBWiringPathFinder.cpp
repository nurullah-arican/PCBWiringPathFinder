/*
 * Project: Shortest Path in PCB Grid
 * Description: This program finds the shortest route for a wire in a 14x14 PCB grid.
 *              The grid contains 20 unreachable tiles, a starting tile, and a target tile.
 *              The program uses a queue data structure to perform a BFS algorithm to find the shortest path.
 *
 * Date: 22.06.2024
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Queue.h"

using namespace std;

// Enum class for tile types
enum class TileType {
    UNREACHABLE = 'U',
    START = 'S',
    TARGET = 'T',
    EMPTY = 'e',
    WIRE = 'W'
};

const int GRID_SIZE = 14;

struct Point {
    int x, y;
};

// Global variables to hold the grid and start/target points
TileType grid[GRID_SIZE][GRID_SIZE];
Point start, target;

// Initializes the grid with empty tiles, sets unreachable tiles,
// and randomly places the START and TARGET tiles.
void initializeGrid() {
    srand(static_cast<unsigned>(time(0))); // Initialize the random number generator with the current time
    
    // Initialize all tiles as EMPTY
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = TileType::EMPTY;
        }
    }

    // Add 20 random UNREACHABLE tiles
    const int totalUnreachableTiles = 20;
    int placedUnreachableTiles = 0;
    while (placedUnreachableTiles < totalUnreachableTiles) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y] == TileType::EMPTY) {
            grid[x][y] = TileType::UNREACHABLE;
            placedUnreachableTiles++;
        }
    }
    
    // Set random START tile
    do {
        start = { rand() % GRID_SIZE, rand() % GRID_SIZE };
    } while (grid[start.x][start.y] != TileType::EMPTY);
    grid[start.x][start.y] = TileType::START;

    // Set random TARGET tile
    do {
        target = { rand() % GRID_SIZE, rand() % GRID_SIZE };
    } while (grid[target.x][target.y] != TileType::EMPTY);
    grid[target.x][target.y] = TileType::TARGET;
}

// Checks if the given (x, y) coordinates are within grid bounds and either EMPTY or TARGET.
bool isValid(int x, int y) {
    return (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && (grid[x][y] == TileType::EMPTY || grid[x][y] == TileType::TARGET));
}

// Finds the shortest path from the start tile to the target tile using a BFS algorithm.
void findShortestPath() {
    Queue<Point> queue;
    vector<vector<bool>> visited(GRID_SIZE, vector<bool>(GRID_SIZE, false));
    vector<vector<Point>> parent(GRID_SIZE, vector<Point>(GRID_SIZE, { -1, -1 }));
    bool found = false;

    // Directions: right, left, up, down
    const int numberOfDirections = 4;
    int dx[numberOfDirections] = { 1, -1, 0, 0 };
    int dy[numberOfDirections] = { 0, 0, 1, -1 };

    // Initialize BFS with the start point
    queue.enqueue(start);
    visited[start.x][start.y] = true;

    while (!queue.isEmpty() && !found) {
        Point currentPoint = queue.front();
        queue.dequeue();

        // Check all four possible directions
        for (int directionIndex = 0; directionIndex < numberOfDirections; ++directionIndex) {
            int newX = currentPoint.x + dx[directionIndex];
            int newY = currentPoint.y + dy[directionIndex];

            // If the new position is valid and not visited
            if (isValid(newX, newY) && !visited[newX][newY]) {
                queue.enqueue({ newX, newY });
                visited[newX][newY] = true;
                parent[newX][newY] = currentPoint;

                // If the target is found, set the found flag to true and break
                if (grid[newX][newY] == TileType::TARGET) {
                    found = true;
                    break;
                }
            }
        }
    }

    // Backtrack from the target to the start to mark the path
    if (found) {
        // Initialize the current point as the target
        Point current = target;

        // Trace the path back to the start
        while (current.x != start.x || current.y != start.y) {
            // Skip marking the TARGET tile
            if (grid[current.x][current.y] != TileType::TARGET) {
                grid[current.x][current.y] = TileType::WIRE;
            }
            // Move to the parent of the current tile
            current = parent[current.x][current.y];
        }
    }
    else {
        cout << "Path not found!" << endl;
    }
}

// Prints the current state of the grid.
void printGrid() {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int column = 0; column < GRID_SIZE; column++) {
            cout << static_cast<char>(grid[row][column]) << " ";
        }
        cout << endl;
    }
}

int main()
{
    initializeGrid();
    findShortestPath();
    printGrid();
    return 0;
}
