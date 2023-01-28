#include "decide.h"

double triangle_area (double a, double b, double c) {
    double s = (a+b+c)/2;

    return sqrt(s*((s-a)*(s-b)*(s-c)));
}

boolean LIC_3 () {
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