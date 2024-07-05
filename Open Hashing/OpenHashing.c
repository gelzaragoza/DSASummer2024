//
// Created by Angel Zaragoza on 6/25/24.
//

#include "OpenHashing.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


void initDictionary(Dictionary D){
    int i;

    for (i = 0; i < SIZE ; i++) {
        D[i] = NULL;
    }
}

int getHash(int employeeID){
    return employeeID % SIZE;
}

void insertSortByAge(Dictionary D, EmployeeInfo newInfo){
    Node *trav, temp;

    int hashIndex = getHash(newInfo.employeeID);

    for (trav = &D[hashIndex]; *trav != NULL && (*trav)->info.employee.age < newInfo.employee.age &&
        (*trav)->info.employeeID != newInfo.employeeID ; &(*trav)->next) {}
    if (*trav == NULL || (*trav)->info.employeeID != newInfo.employeeID){
        temp = (Node) malloc(sizeof(struct node));
        if (temp!=NULL){
            temp->info = newInfo;
            temp->next = *trav;
            *trav = temp;
        }
    }
}

void deleteByID(Dictionary D, int employeeID){

}
void visualize(Dictionary D){
    int i;
    printf("%-10s %-10s\n", "INDEX", "INFO");
    for(i = 0; i < SIZE; i++) {
        printf("%-10d", i);
        if(D[i] == NULL) {
            printf("%-10s", "EMPTY");
        } else {
            Node trav;
            for(trav = D[i]; trav != NULL; trav = trav->next) {
                printf("%10s, %10s | %5d | %10s | %10s | %10d", trav->info.employee.LastName, trav->info.employee.FirstName, trav->info.employee.age, trav->info.city, trav->info.jobTitle, trav->info.employeeID);
                if(trav->next != NULL) {
                    printf(" --> ");
                }
            }
        }
        printf("\n");
    }
}
