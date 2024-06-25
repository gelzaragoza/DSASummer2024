//
// Created by Angel Zaragoza on 6/19/24.
//

#ifndef FIRSTCOMEFIRSTSERVE_CPUSCHEDULING_FCFS_H
#define FIRSTCOMEFIRSTSERVE_CPUSCHEDULING_FCFS_H

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
} Process;

typedef struct {
    int front, rear, capacity;
    Process* processes;
} Queue;

Queue* createQueue(unsigned capacity);
int isFull(Queue* queue);
int isEmpty(Queue* queue);
void enqueue(Queue* queue, Process process);
Process dequeue(Queue* queue);
void findWaitingTime(Queue* queue, int n, int wt[]);
void findTurnAroundTime(Queue* queue, int n, int wt[], int tat[]);
void findAvgTime(Queue* queue, int n);
void printGanttChart(Queue* queue, int n);

#endif //FIRSTCOMEFIRSTSERVE_CPUSCHEDULING_FCFS_H
