//
// Created by Angel Zaragoza on 6/25/24.
//

#ifndef HASHING_OPENHASHING_H
#define HASHING_OPENHASHING_H

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    char LastName[24];
    char FirstName[16];
    int age;
}NameType;

typedef struct {
    NameType employee;
    char city[20];
    char jobTitle[20];
    int employeeID;
}EmployeeInfo;

typedef struct node {
    EmployeeInfo info;
    struct node *next;
}*Node;

typedef Node Dictionary[SIZE];

void initDictionary(Dictionary D);
int getHash(int employeeID);
void insertSortByAge(Dictionary D, EmployeeInfo newInfo);
void deleteByID(Dictionary D, int employeeID);
void visualize(Dictionary D);



#endif //HASHING_OPENHASHING_H
