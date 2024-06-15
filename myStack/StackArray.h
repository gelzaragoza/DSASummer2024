//
// Created by Angel Zaragoza on 6/14/24.
//

#ifndef MYSTACK_STACKARRAY_H
#define MYSTACK_STACKARRAY_H

#include <stdbool.h>
#define MAX 10

typedef struct{
    int data[MAX];
    int top;
}StackArrayList;

void initStackArray(StackArrayList *S);
bool stack_push(StackArrayList *S, int data);
bool stack_pop(StackArrayList *S);
int stack_peek(StackArrayList S);
bool isEmpty(StackArrayList S);
bool isFull(StackArrayList S);
void display(StackArrayList S);
void visualizeStack(StackArrayList S);

/**Create a function that would get all even numbers
 * and return as new stack removing the old stack**/

StackArrayList getAllEven(StackArrayList *S);

#endif //MYSTACK_STACKARRAY_H

