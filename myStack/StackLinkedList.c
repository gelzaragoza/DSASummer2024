//
// Created by Angel Zaragoza on 6/15/24.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "StackLinkedList.h"

void initStackLL(StackLinkedList *S)
{
    *S = NULL;
}
bool stack_pushLL(StackLinkedList *S, int data)
{
    StackLinkedList temp = malloc(sizeof(Node));
    if(temp != NULL){
        temp->data = data;
        temp->next = *S;
        *S = temp;
    }
}
bool stack_popLL(StackLinkedList *S)
{
    StackLinkedList temp;

    if(*S!=NULL){
        temp = *S;
        *S = temp->next;
        free(temp);
    }
}
int stack_peekLL(StackLinkedList S)
{
    return (S!=NULL)? S->data: -1;
}
bool isEmptyLL(StackLinkedList S)
{
    return (S==NULL)? true: false;
}
void displayLL(StackLinkedList S)
{
    printf("Linked List Head = ");
    for (; S != NULL; S=S->next) {
        printf("%d -> ", S->data);
    }
    printf("NULL \n");

}
