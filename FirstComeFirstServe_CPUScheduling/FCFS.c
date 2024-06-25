//
// Created by Angel Zaragoza on 6/19/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->processes = (Process*)malloc(queue->capacity * sizeof(Process));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->rear == queue->capacity - 1);
}

int isEmpty(Queue* queue) {
    return (queue->front > queue->rear);
}

void enqueue(Queue* queue, Process process) {
    if (isFull(queue)) {
        printf("Queue is full, cannot enqueue.\n");
        return;
    }
    queue->processes[++queue->rear] = process;
}

Process dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        Process dummy = { -1, -1, -1 };
        return dummy;
    }
    return queue->processes[queue->front++];
}

void findWaitingTime(Queue* queue, int n, int wt[]) {
    int service_time[n];
    service_time[0] = queue->processes[0].arrival_time;
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        service_time[i] = service_time[i - 1] + queue->processes[i - 1].burst_time;
        wt[i] = service_time[i] - queue->processes[i].arrival_time;

        if (wt[i] < 0) {
            service_time[i] += -wt[i];
            wt[i] = 0;
        }
    }
}

void findTurnAroundTime(Queue* queue, int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = queue->processes[i].burst_time + wt[i];
    }
}

void printGanttChart(Queue* queue, int n) {
    printf("\nGANTT CHART\n");
    for (int i = 0; i < n; i++) {
        printf("  ");
        for (int j = 0; j < queue->processes[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < queue->processes[i].burst_time - 1; j++) printf(" ");
        printf(" P%d ", queue->processes[i].id);
        for (int j = 0; j < queue->processes[i].burst_time - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n  ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < queue->processes[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n%d", queue->processes[0].arrival_time);
    int prev_time = queue->processes[0].arrival_time;
    for (int i = 0; i < n; i++) {
        prev_time += queue->processes[i].burst_time;
        printf("%*d", queue->processes[i].burst_time * 2, prev_time);
    }
    printf("\n");
}

void findAvgTime(Queue* queue, int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(queue, n, wt);
    findTurnAroundTime(queue, n, wt, tat);

    printf("\nFirst Come First Serve - CPU Scheduling\n\n");
    printf("INPUT PROCESS\n");
    printf("Total Number: %d\n\n", n);
    printf("OUTPUT INFORMATION\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("WT Total: %d\n", total_wt);
    printf("WT Average: %.2f\n", (float)total_wt / (float)n);
    printf("TT Total: %d\n", total_tat);
    printf("TT Average: %.2f\n\n", (float)total_tat / (float)n);

    printf("PROCESS TABLE\n");
    printf("\n     %10s     |  %5s  |  %5s  |  %5s  |  %5s  \n", "Process", "Burst Time", "Arrival Time", "Waiting Time", "Turnaround Time");
    for (int i = 0; i < n; i++) {
        printf("     %10d     |  %10d  |  %12d  |  %12d  |  %10d  \n", queue->processes[i].id, queue->processes[i].burst_time, queue->processes[i].arrival_time, wt[i], tat[i]);
    }

    printGanttChart(queue, n);
}