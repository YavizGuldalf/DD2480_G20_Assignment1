#include "decide.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
* Checks the condition for LIC 0, which is if two consecutive data points
* have a distance greater than LENGTH1 between each other. The method
* returns true when this condition is first found. 
*
* @return true if the condition is met, false otherwise.
*/
boolean check_lic_0(void){
    int i;
    double x1,x2,y1,y2,d;

    //Static versions for the variables are currently used
    for(i = 0; i < NUMPOINTS2-1; i++){
        x1 = X2[i];
        x2 = X2[i+1];
        y1 = Y2[i];
        y2 = Y2[i+1];
        d = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

        //Use function for floating point comparision
        if(DOUBLECOMPARE(d,PARAMETERS2.LENGTH1) == GT){
            return true;
        }
    }
    return false;
}