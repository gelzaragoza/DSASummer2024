#include <stdio.h>
#include "CloseHashing.h"

int main(void) {

    Dictionary D;

    initDictionary(D);

    EmployeeInfo empInfo = {{"Zaragoza", "Angelica", 24}, "Mactan", "Designer", 16101416 };
    EmployeeInfo empInfo1 = {{"Pino", "Mike", 23}, "Cabancalan", "Developer", 1812312} ;
    EmployeeInfo empInfo2 = {{"Tamala", "Paul", 25}, "Basak", "Developer", 1512313} ;
    EmployeeInfo empInfo3 = {{"Pedrigal", "Lara", 24}, "Lahug", "Developer", 1212316} ;


    insert(D, empInfo);
    insert(D, empInfo1);
    insert(D, empInfo2);
    insert(D, empInfo3);


    visualize(D);

    deleteByID(D, 1212316);

    printf("\nAfter deletion:\n");
    visualize(D);

    return 0;
}
