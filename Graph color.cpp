#include <stdbool.h>
#include <stdio.h>

#define V 4 // Number of vertices in the graph

// Function to check if it's safe to assign color c to vertex v
bool isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

// Recursive function to solve graph coloring problem
bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            color[v] = 0; // Backtrack
        }
    }

    return false;
}

// Function to print the solution (colors assigned to vertices)
void printSolution(int color[]) {
    printf("Solution Exists: Following are the assigned colors:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d ---> Color %d\n", i, color[i]);
}

// Function to solve graph coloring problem
bool graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(color);
    return true;
}

// Main function
int main() {
    int graph[V][V] = {{0, 1, 1, 1},
                       {1, 0, 1, 0},
                       {1, 1, 0, 1},
                       {1, 0, 1, 0}};
    int m = 3; // Number of colors
    graphColoring(graph, m);
    return 0;
}

