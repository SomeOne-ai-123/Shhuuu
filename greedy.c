#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 5  // Number of locations

int findMinCost(int graph[N][N], int start) {
    bool visited[N] = { false };
    int minCost = 0;
    int u = start;

    for (int count = 0; count < N - 1; count++) {
        visited[u] = true;
        int next = -1;
        int minDist = INT_MAX;

        for (int v = 0; v < N; v++) {
            if (!visited[v] && graph[u][v] < minDist) {
                minDist = graph[u][v];
                next = v;
            }
        }

        minCost += minDist;
        u = next;
    }

    // Return to start to complete the cycle
    minCost += graph[u][start];
    return minCost;
}

int main() {
    int graph[N][N] = {
        { 0, 29, 20, 21, 16 },
        { 29, 0, 15, 17, 18 },
        { 20, 15, 0, 28, 23 },
        { 21, 17, 28, 0, 12 },
        { 16, 18, 23, 12, 0 }
    };

    int startLocation = 0;
    int minCost = findMinCost(graph, startLocation);
    printf("Minimum cost starting from location %d is %d\n", startLocation, minCost);

    return 0;
}
