#include "decide.h"
#include <stdbool.h>

boolean LIC_2(){
    for(int i=0; i<NUMPOINTS-2; i++){
        double x1 = X[i];
        double y1 = Y[i];
        double x2 = X[i+1];
        double y2 = Y[i+1];
        double x3 = X[i+2];
        double y3 = Y[i+2];

        // Method inspired by https://stackoverflow.com/a/31334882/19188850
        // Returns a number between -pi and pi (Whether the interval is closed, half-closed or open should be tested)
        double angle =  atan2(y1 - y2, x1 - x2) - atan2(y3 - y2, x3 - x2);

        // Negative angles should be made positive
        if(angle < 0){
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