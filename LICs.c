#include "decide.h"
#include <stdio.h>
#include <stdbool.h>

double distance_by_index(int, int);

/*
* Checks the condition for LIC 0, which is if two consecutive data points
* have a distance greater than LENGTH1 between each other. The method
* returns true when this condition is first found. 
*
* @return true if the condition is met, false otherwise.
*/
boolean check_lic_0(void){
    if(X == NULL || Y == NULL){
        return false;
    }

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

//LIC 4
boolean check_lic_4 (void) {
    if(PARAMETERS.QPTS < 2 || PARAMETERS.QPTS > NUMPOINTS || 
    PARAMETERS.QUADS < 1 || PARAMETERS.QUADS > 3)
        return false;

    boolean quad_1, quad_2, quad_3, quad_4;

    for(int i = 0; i < NUMPOINTS - PARAMETERS.QPTS; i++) {
        quad_1 = 0; quad_2 = 0; quad_3 = 0; quad_4 = 0;

        for(int j = 0; j < PARAMETERS.QPTS; j++) {
            if(*(X+j) >= 0 && *(Y+j) >= 0) {
                quad_1 = 1;
            } else if(*(X+j) > 0 && *(Y+j) < 0) {
                quad_2 = 1;
            } else if(*(X+j) < 0 && *(Y+j) > 0) {
                quad_3 = 1;
            } else {
                quad_4 = 1;
            }
        }

        if((quad_1 + quad_2 + quad_3 + quad_4) > PARAMETERS.QUADS)
            return true;
    }

    return false;
}

/*
* Checks the condition for LIC 5, which is if two consecutive data points
* (X[i] and X[j], i = j-1) fulfil the condition X[j] - X[i] < 0
*
* @return true if the condition is met, false otherwise.
*/
boolean check_lic_5(void){
    if(X == NULL || Y == NULL){
        return false;
    }
    int i;
    double xi,xj;

    for(i = 0; i < NUMPOINTS-1; i++){
        xi = X[i];
        xj = X[i+1];

        //Use function for floating point comparision
        if(DOUBLECOMPARE((xj-xi),0.0) == LT){
            return true;
        }
    }
    return false;
}

boolean check_lic_7(void){
    // The below check also handles the case where NUMPOINTS < 3
    if(1 > PARAMETERS.KPTS || PARAMETERS.KPTS > NUMPOINTS-2){
        return false;
    }

    if(X == NULL || Y == NULL){
        return false;
    }

    for(int p1Index = 0; p1Index + PARAMETERS.KPTS + 1 < NUMPOINTS; p1Index++){
        int p2Index = p1Index + PARAMETERS.KPTS + 1;
        double distance = distance_by_index(p1Index, p2Index);

        if(DOUBLECOMPARE(distance, PARAMETERS.LENGTH1) == GT){
            return true;
        }
    }

    return false;
}

/*
* Given the indexes for two points, returns the distance between the points
* found at these indices. Doesn't check the validity of X and Y arrays so
* that check must be done externally.
* 
* @param p1Index The index of the first point in the X and Y arrays.
* @param p2Index The index of the second point in the the X and Y arrays.
* @return The distance between the points.
*/
double distance_by_index(int p1Index, int p2Index){
    int x1 = X[p1Index];
    int x2 = X[p2Index];
    int y1 = Y[p1Index];
    int y2 = Y[p2Index];
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}