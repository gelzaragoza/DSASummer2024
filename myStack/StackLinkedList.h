//
// Created by Angel Zaragoza on 6/15/24.
//

#ifndef MYSTACK_STACKLINKEDLIST_H
#define MYSTACK_STACKLINKEDLIST_H
#include <stdbool.h>
#define MAX 10

typedef struct node{
    int data;
    struct node*next;
}Node, *StackLinkedList;

void initStackLL(StackLinkedList *S);
bool stack_pushLL(StackLinkedList *S, int data);
bool stack_popLL(StackLinkedList *S);
int stack_peekLL(StackLinkedList S);
bool isEmptyLL(StackLinkedList S);
void displayLL(StackLinkedList S);

#endif //MYSTACK_STACKLINKEDLIST_H
