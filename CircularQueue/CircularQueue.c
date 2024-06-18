//
// Created by Angel Zaragoza on 6/18/24.
//

#include "CircularQueue.h"
#include <stdbool.h>
#include <stdio.h>



void initQueue(CircularQ *Q) {
    Q->front = 0;
    Q->rear = MAX - 1;
}

void enqueue(CircularQ *Q, int data) {
    if (!isFull(*Q)) {
        Q->rear = (Q->rear + 1) % MAX;
        Q->data[Q->rear] = data;
    } else {
        printf("Queue is full.\n");
    }
}

int dequeue(CircularQ *Q) {
    int data;
    if (!isEmpty(*Q)) {
        data = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAX;
        return data;
    } else {
        printf("Queue is empty.\n");
        return -1; // Return -1 to indicate an error
    }
}

void displayQueue(CircularQ Q) {
    int i = Q.front;
    while (i != (Q.rear + 1) % MAX) {
        printf("Array[%d] = %d\n", i, Q.data[i]);
        i = (i + 1) % MAX;
    }
}

bool isEmpty(CircularQ Q) {
    return (Q.rear + 1) % MAX == Q.front;
}

bool isFull(CircularQ Q) {
    return (Q.rear + 2) % MAX == Q.front;
}