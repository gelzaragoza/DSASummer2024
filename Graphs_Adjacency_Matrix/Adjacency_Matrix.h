//
// Created by Angel Zaragoza on 7/15/24.
//

#ifndef GRAPHS_ADJACENCY_MATRIX_H
#define GRAPHS_ADJACENCY_MATRIX_H
#define SIZE 5

typedef struct {
    int adjacencyMatrix[SIZE][SIZE];
    int numOfVertices;
}Graph;

Graph *initializeGraph(int numOfVertices);
void addEdge(Graph *graph, char head, char tail);
void printGraph(Graph graph);


#endif //GRAPHS_ADJACENCY_MATRIX_H
