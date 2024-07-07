//
// Created by Angel Zaragoza on 7/5/24.
//

#ifndef BST_BST_H
#define BST_BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char prodName[20];
    float prodPrice;
    int prodQty;
    Date expDate;
} Product;

typedef struct node {
    Product item;
    struct node *Left, *Right;
} NodeType, *NodePtr;

// Queue for BFS
typedef struct queueNode {
    NodePtr treeNode;
    struct queueNode *next;
} QueueNode, *QueueNodePtr;

typedef struct {
    QueueNodePtr front;
    QueueNodePtr rear;
} Queue;

void initializeBST(NodePtr *T);
void insertProduct(NodePtr *T, Product prod);
void deleteProduct(NodePtr *T, char *prodName);
bool isMember(NodePtr T, char *prodName);
void preorder(NodePtr T);
void inorder(NodePtr T);
void postorder(NodePtr T);
int deleteMin(NodePtr *T);
int deleteMax(NodePtr *T);
void bfs(NodePtr T);
void printTree(NodePtr T, int space);

// Queue functions
void initializeQueue(Queue *q);
bool isQueueEmpty(Queue q);
void enqueue(Queue *q, NodePtr treeNode);
NodePtr dequeue(Queue *q);

#endif //BST_BST_H
