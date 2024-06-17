//
// Created by Angel Zaragoza on 6/17/24.
//

#ifndef UNTITLED_QUEUELINKEDLIST_H
#define UNTITLED_QUEUELINKEDLIST_H

#include <stdbool.h>
#define MAX 10

typedef int SET[MAX];
typedef struct node{
    int data;
    struct node *link;
}Node, *NodePtr;

typedef struct{
    NodePtr front;
    NodePtr rear;
}QueueLinkedList;

void initQueueLinkedList(QueueLinkedList *Q);
void enqueueQueueLinkedList(QueueLinkedList *Q, int newData);
void dequeueQueueLinkedList(QueueLinkedList *Q);
int rear(QueueLinkedList Q);
int front(QueueLinkedList Q);
bool isEmpty(QueueLinkedList Q);
void displayQueueList(QueueLinkedList Q);

#endif //UNTITLED_QUEUELINKEDLIST_H
