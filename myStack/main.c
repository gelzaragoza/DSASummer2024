#include <stdio.h>
#include "StackArray.h"
#include "StackLinkedList.h"

int main(void) {

    StackArrayList Stack, newStack;

    initStackArray(&Stack);
    initStackArray(&newStack);


    stack_push(&Stack, 3);
    stack_push(&Stack, 5);
    stack_push(&Stack, 4);
    stack_push(&Stack, 2);

    printf("Stack Array \n");
    display(Stack);
    visualizeStack(Stack);

   // stack_pop(&Stack);

    printf("\nUpdated Array \n");
    display(Stack);
    visualizeStack(Stack);

    printf("Get All Even\n");
    newStack = getAllEven(&Stack);

    display(newStack);
    visualizeStack(newStack);

    printf("STACK LINKED LIST\n");

    StackLinkedList StackLL;

    initStackLL(&StackLL);

    stack_pushLL(&StackLL, 13);
    stack_pushLL(&StackLL, 12);
    stack_pushLL(&StackLL, 17);
    stack_pushLL(&StackLL, 20);

    displayLL(StackLL);

    return 0;
}
