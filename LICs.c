#include "decide.h"

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
boolean LIC_1 (double radious) {
    for(int i = 0; i < 97; i++) {
        double ab = distance(*(X+i), *(X+i+1), *(Y+i), *(Y+i+1));
        double bc = distance(*(X+i+1), *(X+i+2), *(Y+i+1), *(Y+i+2));
        double ac = distance(*(X+i), *(X+i+2), *(Y+i), *(Y+i+2));

        double diameter = largest_3(ab, ac, ab);

        if(diameter < radious*2)
            return 1;
    }

    return 0;
}