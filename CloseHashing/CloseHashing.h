//
// Created by Angel Zaragoza on 7/5/24.
//

#ifndef CLOSEHASHING_CLOSEHASHING_H
#define CLOSEHASHING_CLOSEHASHING_H
#define SIZE 10
#define EMPTY '-'
#define DELETE '#'

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
    char status;
}EmployeeInfo;

typedef EmployeeInfo Dictionary[SIZE];

void initDictionary(Dictionary D);
int getHash(int employeeID);
void insert(Dictionary D, EmployeeInfo newInfo);
void deleteByID(Dictionary D, int employeeID);
void visualize(Dictionary D);


#endif //CLOSEHASHING_CLOSEHASHING_H
