//
// Created by Angel Zaragoza on 7/15/24.
//

#ifndef GRAPHS_ADJACENCY_LIST_ADJACENCY_LIST_H
#define GRAPHS_ADJACENCY_LIST_ADJACENCY_LIST_H
#define SIZE 5


#include <stdio.h>
#include <stdlib.h>
#include "Adjacency_List.h"



typedef struct node {
    char data;
    struct node *next;
}*Node;

typedef Node AdjacencyList[SIZE];

void initializeList(AdjacencyList L);
void addEdge(AdjacencyList L, char head, char tail);
void printAdjacencyList(AdjacencyList L);

#endif //GRAPHS_ADJACENCY_LIST_ADJACENCY_LIST_H
