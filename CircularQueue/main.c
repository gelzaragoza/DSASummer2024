#include "CircularQueue.h"
#include <stdio.h>

int main(void) {
    CircularQ Q;
    initQueue(&Q);
    enqueue(&Q, 10);
    enqueue(&Q, 20);
    enqueue(&Q, 30);
    enqueue(&Q, 40);
    enqueue(&Q, 50);

    displayQueue(Q);

    printf("\nAfter dequeue:\n\n");
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);

    displayQueue(Q);

    return 0;
}