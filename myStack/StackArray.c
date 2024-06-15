//
// Created by Angel Zaragoza on 6/14/24.
//
#include <stdio.h>
#include <stdbool.h>
#include "StackArray.h"

void initStackArray(StackArrayList *S)
{
     S->top = -1;
}
bool stack_push(StackArrayList *S, int newData)
{
    if(S->top != MAX-1){
        S->data[++(S->top)] = newData;
    }
}
bool stack_pop(StackArrayList *S)
{
    if(S->top != -1){
        S->top--;
    }
}
int stack_peek(StackArrayList S)
{
    return (S.top != -1)? S.data[S.top]: -1;
}
bool isEmpty(StackArrayList S)
{
    return (S.top == -1 )? true: false;
}
bool isFull(StackArrayList S)
{
    return (S.top == MAX)? true: false;
}
void display(StackArrayList S)
{
    StackArrayList temp;
    initStackArray(&temp);

    while (!isEmpty(S)){
        stack_push(&temp, stack_peek(S));
        stack_pop(&S);
    }

    while (!isEmpty(temp)){
        printf("%d \n", temp.data[temp.top]);
        stack_push(&S, stack_peek(temp));
        stack_pop(&temp);
    }
}
void visualizeStack(StackArrayList S)
{
    int i;

    printf("INDEX \t | \t VALUE\n");
    printf("%d \t \t | \t %d  %s\n", S.top, S.data[S.top], "--> TOP");
    for ( i = S.top-1; i >= 0 ; --i) {
        printf("%d \t \t | \t %d \n", i, S.data[i]);
    }

}

StackArrayList getAllEven(StackArrayList *S)
{
    StackArrayList temp, newStack;

    initStackArray(&temp);
    initStackArray(&newStack);

    while(!isEmpty(*S)){
        stack_push(&temp, stack_peek(*S));
        stack_pop(S);
    }

    while(!isEmpty(temp)){
        if(temp.data[temp.top] % 2 == 0){
            stack_push(&newStack, stack_peek(temp));
            stack_pop(&temp);
        }else {
            stack_push(S, stack_peek(temp));
            stack_pop(&temp);
        }
    }
    return newStack;
}

