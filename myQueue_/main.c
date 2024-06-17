#include <stdio.h>
#include <stdbool.h>
#include "QueueLinkedList.h"

int main(void){

    SET setArray = {1,2,3,4,5};

    QueueLinkedList QueueLL;

    initQueueLinkedList(&QueueLL);

    int i;

    for (i = 0; i < MAX / 2; i++) {
        enqueueQueueLinkedList(&QueueLL, setArray[i]);
    }
    printf(("Queue: \n"));
    displayQueueList(QueueLL);



    front(QueueLL);
    rear(QueueLL);

    printf(("After dequeue: \n"));
    dequeueQueueLinkedList(&QueueLL);
    displayQueueList(QueueLL);

    front(QueueLL);
    rear(QueueLL);


    return 0;
}
