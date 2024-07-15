#include <stdio.h>
#include "Adjacency_Matrix.h"


int main(void) {
    Graph *graph = initializeGraph(5);

    addEdge(graph, 'A', 'C');
    addEdge(graph, 'A', 'E');

    addEdge(graph, 'B', 'D');
    addEdge(graph, 'B', 'F');

    addEdge(graph, 'C', 'D');

    addEdge(graph, 'D', 'E');
    addEdge(graph, 'D', 'F');

    printGraph(*graph);

    return 0;
}
