//
// Created by Angel Zaragoza on 6/18/24.
//

#ifndef CIRCULARQUEUE_CIRCULARQUEUE_H
#define CIRCULARQUEUE_CIRCULARQUEUE_H

#include <stdlib.h>
#include <stdbool.h>
#define MAX 7

typedef struct{
    int data[MAX];
    int front;
    int rear;
}CircularQ;

void initQueue(CircularQ* Q);
void enqueue(CircularQ* Q, int data);
int dequeue(CircularQ* Q);
void displayQueue(CircularQ Q);
bool isEmpty(CircularQ Q);
bool isFull(CircularQ Q);




#endif //CIRCULARQUEUE_CIRCULARQUEUE_H
