#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

int main() {
    int n = 5;
    Process processes[] = {
            {1, 1, 2},
            {2, 0, 3},
            {3, 2, 4},
            {4, 5, 1},
            {5, 0, 2},
            {6, 3, 3}

    };

    Queue* queue = createQueue(n);

    for (int i = 0; i < n; i++) {
        enqueue(queue, processes[i]);
    }

    findAvgTime(queue, n);

    return 0;
}