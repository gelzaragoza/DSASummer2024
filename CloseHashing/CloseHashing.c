//
// Created by Angel Zaragoza on 7/5/24.
//


#include <stdio.h>
#include "CloseHashing.h"

void initDictionary(Dictionary D) {
    int i;
    for(i = 0; i < SIZE; i++) {
        D[i].status = EMPTY;
    }
}

int hash(int employeeID) {
    return employeeID % SIZE;
}

void insert(Dictionary D, EmployeeInfo info) {
    int hashVal = hash(info.employeeID);
    int index = hashVal;
    int start = index;

    while(D[index].employeeID != info.employeeID && D[index].status != EMPTY && D[index].status != DELETE){
        index = (index + 1) % SIZE;
        if(index == start) {
            printf("Error 404: Dictionary is full. Unable to insert new info with Employee ID: %d", info.employeeID);
            return;
        }
    }
    if(D[index].status == EMPTY || D[index].status == DELETE) {
        D[index] = info;
    } else if (D[index].employeeID == info.employeeID) {
        printf("Error 404: Duplicate Employee ID: %d\n", info.employeeID);
        return;
    }
}

void deleteByID(Dictionary D, int employeeID) {
    int hashVal = hash(employeeID);
    int index = hashVal;
    int start = index;

    while(D[index].employeeID != employeeID) {
        index = (index + 1) % SIZE;
        if(index == start) {
            printf("Error 404: Unable to find EmployeeID.: %d\n", employeeID);
            return;
        }
    }

    if(D[index].employeeID == employeeID) {
        D[index].status = DELETE;
    }
}

void visualize(Dictionary D) {
    int i;
    printf("%-10s %-10s\n", "INDEX", "DATA");
    for(i = 0; i < SIZE; i++) {
        printf("%-10d", i);
        if(D[i].status == EMPTY) {
            printf("%-10s", "EMPTY");
        } else if(D[i].status == DELETE) {
            printf("%-10s", "DELETED");
        } else {
            printf("%-8s, %-8s %-8d | %-8s, %-8s %-8d", D[i].employee.LastName, D[i].employee.FirstName, D[i].employee.age, D[i].city, D[i].jobTitle, D[i].employeeID);
        }
        printf("\n");
    }
}