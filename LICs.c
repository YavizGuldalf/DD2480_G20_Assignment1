#include "decide.h"
#include <stdio.h>
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

    for(i = 0; i < NUMPOINTS-1; i++){
        x1 = X[i];
        x2 = X[i+1];
        y1 = Y[i];
        y2 = Y[i+1];
        d = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

        //Use function for floating point comparision
        if(DOUBLECOMPARE(d,PARAMETERS.LENGTH1) == GT){
            return true;
        }
    }
    return false;
}

double distance (double x1, double x2, double y1, double y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

double largest_3 (double a, double b, double c) {
    if(a > b && a > c)
        return a;
    else if (b > c)
        return b;
    else
        return c;
}

//LIC 1
boolean check_lic_1 () {
    for(int i = 0; i < 97; i++) {
        double ab = distance(*(X+i), *(X+i+1), *(Y+i), *(Y+i+1));
        double bc = distance(*(X+i+1), *(X+i+2), *(Y+i+1), *(Y+i+2));
        double ac = distance(*(X+i), *(X+i+2), *(Y+i), *(Y+i+2));

        double diameter = largest_3(ab, ac, ab);

        if(diameter < PARAMETERS.RADIUS1*2)
            return 1;
    }

    return 0;
}

/*
* Check the condition for LIC 2, which is if there exists at least one set 
* of three consecutive data points which form an angle such that:
* angle < (PI - EPSILON)
* or
* angle > (PI + EPSILON)
* 
* @return true if the condition is met, false otherwise.
*/
boolean check_lic_2(void){
    for(int i=0; i<NUMPOINTS-2; i++){
        double x1 = X[i];
        double y1 = Y[i];
        double x2 = X[i+1];
        double y2 = Y[i+1];
        double x3 = X[i+2];
        double y3 = Y[i+2];

        if((x1 == x2) && (y1 == y2)){
            continue;
        } else if((x3 == x2) && (y3 == y2)){
            continue;
        }

        // Method inspired by https://stackoverflow.com/a/31334882/19188850
        // Returns a number between -pi and pi (Whether the interval is closed, half-closed or open should be tested)
        double angle =  atan2(y1 - y2, x1 - x2) - atan2(y3 - y2, x3 - x2);

        if(angle < 0){
            // This needs to be tested, might need to get replaced by angle += 2*PI;
            angle = -angle;
        }

        if(DOUBLECOMPARE(angle, PI - PARAMETERS.EPSILON) == LT){
            return true;
        } else if(DOUBLECOMPARE(angle, PI + PARAMETERS.EPSILON) == GT){
            return true;
        }

    }
    return false;
}

double triangle_area (double a, double b, double c) {
    double s = (a+b+c)/2;

    return sqrt(s*((s-a)*(s-b)*(s-c)));
}

//LIC 3
boolean check_lic_3 () {
    for(int i = 0; i < 97; i++) {
        double ab = distance(*(X+i), *(X+i+1), *(Y+i), *(Y+i+1));
        double bc = distance(*(X+i+1), *(X+i+2), *(Y+i+1), *(Y+i+2));
        double ac = distance(*(X+i), *(X+i+2), *(Y+i), *(Y+i+2));

        if(ab == 0 || ac == 0 || bc == 0)
            continue;

        double area = triangle_area(ab,ac,bc);

        if(area > PARAMETERS.AREA1)
            return 1;
    }

    return 0;
}