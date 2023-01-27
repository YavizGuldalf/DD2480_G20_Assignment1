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

double triangle_area (double a, double b, double c) {
    double s = (a+b+c)/2;

    return sqrt(s*((s-a)*(s-b)*(s-c)));
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

boolean LIC_3 (double area1) {
    for(int i = 0; i < 97; i++) {
        double ab = distance(*(X+i), *(X+i+1), *(Y+i), *(Y+i+1));
        double bc = distance(*(X+i+1), *(X+i+2), *(Y+i+1), *(Y+i+2));
        double ac = distance(*(X+i), *(X+i+2), *(Y+i), *(Y+i+2));

        if(ab == 0 || ac == 0 || bc == 0)
            continue;

        double area = triangle_area(ab,ac,bc);

        if(area > area1)
            return 1;
    }

    return 0;
}