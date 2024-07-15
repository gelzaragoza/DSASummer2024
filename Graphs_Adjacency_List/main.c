#include <stdio.h>
#include "Adjacency_List.h"

int main(void) {
    AdjacencyList L;
    initializeList(L);

    addEdge(L, 'A', 'C');
    addEdge(L, 'A', 'F');

    addEdge(L, 'B', 'D');
    addEdge(L, 'B', 'E');

    addEdge(L, 'C', 'D');

    addEdge(L, 'D', 'E');
    addEdge(L, 'D', 'F');

    printAdjacencyList(L);

    return 0;
}
