//
// Created by Angel Zaragoza on 7/5/24.
//

#ifndef BST_BST_H
#define BST_BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void initializeBST(NodePtr *T);
void insertProduct(NodePtr *T, Product prod);
void deleteProduct(NodePtr *T, char *prodName);
int isMember(NodePtr T, char *prodName);
void preorder(NodePtr T);
void inorder(NodePtr T);
void postorder(NodePtr T);
int deleteMin(NodePtr *T);
int deleteMax(NodePtr *T);
void bfs(NodePtr T);
void printTree(NodePtr T, int space);

#endif //BST_BST_H
