//
// Created by Angel Zaragoza on 6/17/24.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "QueueLinkedList.h"

void initQueueLinkedList(QueueLinkedList *Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

void enqueueQueueLinkedList(QueueLinkedList *Q, int newData) {
    NodePtr temp = malloc(sizeof(Node));
    if (temp != NULL) {
        temp->data = newData;
        temp->link = NULL;
        if (Q->rear == NULL) {
            Q->front = temp;
            Q->rear = temp;
        } else {
            Q->rear->link = temp;
            Q->rear = temp;
        }
    } else {
        printf("Memory allocation failed\n");
    }
}

void dequeueQueueLinkedList(QueueLinkedList *Q) {
    if (Q->front != NULL) {
        NodePtr temp = Q->front;
        Q->front = Q->front->link;
        if (Q->front == NULL) {
            Q->rear = NULL;
        }
        free(temp);
    } else {
        printf("Queue is empty, cannot dequeue\n");
    }
}

int rear(QueueLinkedList Q) {
    Q.rear != NULL ? printf("Rear value: %d\n", Q.rear->data) : printf("Queue is empty\n");
    return (Q.rear != NULL) ? Q.rear->data : -1;
}

int front(QueueLinkedList Q) {
    Q.front != NULL ? printf("Front value: %d\n", Q.front->data) : printf("Queue is empty\n");
    return (Q.front != NULL) ? Q.front->data : -1;
}

bool isEmpty(QueueLinkedList Q) {
    return Q.front == NULL;
}

void displayQueueList(QueueLinkedList Q) {
    NodePtr current = Q.front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->link;
    }
    printf("\n");
}
