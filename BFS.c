#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct {
    int numNodes;
    int adjMatrix[MAX_NODES][MAX_NODES];
} Graph;

void initializeGraph(Graph* g, int numNodes) {
    g->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int u, int v) {
    g->adjMatrix[u][v] = 1;
    g->adjMatrix[v][u] = 1; // Assuming undirected graph
}

void bfs(Graph* g, int startNode) {
    int visited[MAX_NODES] = {0};
    int queue[MAX_NODES], front = 0, rear = 0;

    visited[startNode] = 1;
    queue[rear++] = startNode;

    printf("Reachable nodes from node %d: ", startNode);

    while (front < rear) {
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        for (int i = 0; i < g->numNodes; i++) {
            if (g->adjMatrix[currentNode][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    Graph g;
    int numNodes = 6;

    initializeGraph(&g, numNodes);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 4);
    addEdge(&g, 4, 5);

    int startNode = 0;
    bfs(&g, startNode);

    return 0;
}
