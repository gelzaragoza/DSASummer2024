//
// Created by Angel Zaragoza on 6/21/24.
//

#ifndef SETS_SETARRAY_H
#define SETS_SETARRAY_H

#define MAX 10

typedef struct{
    int data[MAX];
    int count;
}SET;

SET getIntersection(SET A, SET B);
SET getUnion(SET A, SET B);
void addElement(SET* selectSet, int data);
void deleteElement(SET* selectSet, int data);
void displaySet(SET selectSet);


#endif //SETS_SETARRAY_H
