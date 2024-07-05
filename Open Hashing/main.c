#include <stdio.h>
#include "OpenHashing.h"

int main(void) {

    Dictionary D;

    initDictionary(D);

    EmployeeInfo empInfo = {{"Zaragoza", "Angelica", 24}, "Mactan", "Designer", 16101416 };
    EmployeeInfo empInfo1 = {{"Pino", "Mike", 23}, "Cabancalan", "Developer", 1812312} ;
    EmployeeInfo empInfo2 = {{"Tamala", "Paul", 25}, "Basak", "Developer", 1512313} ;
    EmployeeInfo empInfo3 = {{"Pedrigal", "Lara", 24}, "Lahug", "Developer", 1212316} ;


    insertSortByAge(D, empInfo);
    insertSortByAge(D, empInfo1);
    insertSortByAge(D, empInfo2);
    insertSortByAge(D, empInfo3);


    visualize(D);

    return 0;
}
