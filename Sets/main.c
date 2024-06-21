#include <stdio.h>
#include "SetArray.h"

int main(void) {
    SET A, B, unionSet, intersectionSet;

    A.count = 0;
    B.count = 0;

    addElement(&A, 1);
    addElement(&A, 2);
    addElement(&A, 3);

    addElement(&B, 3);
    addElement(&B, 4);
    addElement(&B, 5);

    printf("Set A: ");
    displaySet(A);

    printf("Set B: ");
    displaySet(B);

    unionSet = getUnion(A, B);
    printf("Union of A and B: ");
    displaySet(unionSet);

    intersectionSet = getIntersection(A, B);
    printf("Intersection of A and B: ");
    displaySet(intersectionSet);

    printf("Delete 1 in Set A: ");
    deleteElement(&A, 1);
    displaySet(A);

    printf("Delete 4 in Set B: ");
    deleteElement(&B, 4);
    displaySet(B);

    return 0;
}
