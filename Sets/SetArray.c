//
// Created by Angel Zaragoza on 6/21/24.
//

#include "SetArray.h"
#include <stdio.h>

SET getIntersection(SET A, SET B) {
    SET returnSet = {.count = 0};
    int x, y;

    for (x = 0; x < A.count; x++) {
        for (y = 0; y < B.count && A.data[x] != B.data[y]; ++y) {}
        if (y < B.count && A.data[x] == B.data[y]) {
            returnSet.data[returnSet.count++] = A.data[x];
        }
    }
    return returnSet;
}

SET getUnion(SET A, SET B) {
    SET returnSet = {.count = 0};
    int x, y;

    for (x = 0; x < A.count; x++) {
        returnSet.data[returnSet.count++] = A.data[x];
    }

    for (x = 0; x < B.count; x++) {
        int found = 0;
        for (y = 0; y < returnSet.count; y++) {
            if (B.data[x] == returnSet.data[y]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            returnSet.data[returnSet.count++] = B.data[x];
        }
    }
    return returnSet;
}

void addElement(SET* selectSet, int data) {
    int x;
    for (x = 0; x < selectSet->count; x++) {
        if (selectSet->data[x] == data) {
            return; // Element already in the set
        }
    }
    if (selectSet->count < MAX) {
        selectSet->data[selectSet->count++] = data;
    }
}

void deleteElement(SET* selectSet, int data) {
    int x, y;
    for (x = 0; x < selectSet->count; x++) {
        if (selectSet->data[x] == data) {
            for (y = x; y < selectSet->count - 1; y++) {
                selectSet->data[y] = selectSet->data[y + 1];
            }
            selectSet->count--;
            return;
        }
    }
}

void displaySet(SET selectSet) {
    int x;
    printf("{");
    for (x = 0; x < selectSet.count; x++) {
        if (x > 0) {
            printf(", ");
        }
        printf("%d", selectSet.data[x]);
    }
    printf("}\n");
}
