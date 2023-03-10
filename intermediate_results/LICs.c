#include "decide.h"
#include <stdio.h>
#include <stdbool.h>

double distance_by_index(int, int);
double distance_to_line(double,double,double,double,double,double);
double largest_3(double,double,double);
double slope_by_index(int,int);
double angle_by_index(int,int,int);

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

//Gives the distance between two points using pythagoras theorem
double distance (double x1, double x2, double y1, double y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

/*
* There exists at least one set of three consecutive data points that 
* cannot all be contained within or on a circle of radius RADIUS1.
* (0 ≤ RADIUS1)
*/
boolean check_lic_1 () {
    if(PARAMETERS.RADIUS1 < 0)
        return false;

    for(int i=0; i < NUMPOINTS - 2; i++){
        int j = i + 1;
        int k = j + 2;

        double dist1 = distance_by_index(i, j);
        double dist2 = distance_by_index(j, k);
        double dist3 = distance_by_index(i, k);
        double slope1 = slope_by_index(i,j);
        double slope2 = slope_by_index(j,k);
        double slope3 = slope_by_index(i,k);
        double angle1 = angle_by_index(i,j,k);
        double angle2 = angle_by_index(i,k,j);
        double angle3 = angle_by_index(k,i,j);

        double largest_dist = largest_3(dist1, dist2, dist3);
        double largest_angle = largest_3(angle1, angle2, angle3);

        // To find the smallest circle that can contain these 3 points, we will use the method proposed at
        // https://math.stackexchange.com/a/2234810, with a few more checks in case the three points don't 
        // form a triangle.

        int R;
        // If two points are the same, or if the three points are on the same line (they don't form a triangle),
        // or if they form an obtuse triangle,
        // checking that the largest distance is less than RADIUS * 2 is sufficient.
        if((X[i] == X[j] && Y[i] == Y[j]) ||
           (X[i] == X[k] && Y[i] == Y[k]) ||
           (X[j] == X[k] && Y[j] == Y[k]) ||
           DOUBLECOMPARE(slope1, slope2) == EQ || 
           DOUBLECOMPARE(slope1, slope3) == EQ ||
           DOUBLECOMPARE(slope2, slope3) == EQ ||
           DOUBLECOMPARE(largest_angle, PI/2) == GT){

            R = largest_dist / 2;
        } else{
            // If the three points instead form an acute triangle, the radius of the circumscribed circle
            // is the smallest radius these 3 points can fit in.

            int s = (dist1 + dist2 + dist3) / 2;
            R = (dist1*dist2*dist3) / (4*sqrt(s * (s-dist1) * (s - dist2) * (s - dist3)));

        }
        
        if(DOUBLECOMPARE(R, PARAMETERS.RADIUS1) == GT){
            return true;
        }
    }

    return false;
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

//Gives the are of a triangle based on the lenght of each side
//Using the Heron's Formula (https://www.cuemath.com/measurement/area-of-triangle/)
double triangle_area (double a, double b, double c) {
    double s = (a+b+c)/2;

    return sqrt(s*((s-a)*(s-b)*(s-c)));
}

/*
* There exists at least one set of three consecutive data points that 
* are the vertices of a triangle with area greater than AREA1.
* (0 ≤ AREA1)
*/
boolean check_lic_3 () {
    for(int i = 0; i < NUMPOINTS-2; i++) {
        //Get the length of all three lines
        double ab = distance(*(X+i), *(X+i+1), *(Y+i), *(Y+i+1));
        double bc = distance(*(X+i+1), *(X+i+2), *(Y+i+1), *(Y+i+2));
        double ac = distance(*(X+i), *(X+i+2), *(Y+i), *(Y+i+2));

        if(ab == 0 || ac == 0 || bc == 0)
            continue;

        //Calculate the are of the triangle
        double area = triangle_area(ab,ac,bc);

        if(area > PARAMETERS.AREA1)
            return 1;
    }

    return 0;
}

/*
* There exists at least one set of QPTS consecutive data points that lie in more 
* than QUADS quadrants. Where there is ambiguity as to which quadrant contains a 
* given point, priority of decision will be by quadrant number, i.e., I, II, III, IV.
* For example, the data point (0,0) is in quadrant I, the point (-l,0) is in quadrant II, 
* the point (0,-l) is in quadrant III, the point(0,1) is in quadrant I and the point (1,0) 
* is in quadrant I.
* (2 ≤ QPTS ≤ NUMPOINTS),
* (1 ≤ QUADS ≤ 3)
*/
boolean check_lic_4 (void) {
    if(PARAMETERS.QPTS < 2 || PARAMETERS.QPTS > NUMPOINTS || 
    PARAMETERS.QUADS < 1 || PARAMETERS.QUADS > 3)
        return false;

    //Declare the quadrants
    boolean quad_1, quad_2, quad_3, quad_4;

    for(int i = 0; i < NUMPOINTS - PARAMETERS.QPTS; i++) {
        //Set quadrants to 0 as we look through a new set of consecutive points
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

/*
* Checks the condition for LIC 6, which is if there is at least one set of  N_PTS consecutive 
* data points so that one of these point is further than DIST away from the line that can be
* created between the first and the last of the N_PTS points. 
* If the first and last points of these N_PTS are identical, then the calculated distance
* to compare with DIST will be the distance from this point to all other points.
* The function uses the other function distance_to_line in order to calculate the distance.
*
* @return true if the condition is met, false otherwise.
*/
boolean check_lic_6(void){
    int N_PTS = PARAMETERS.NPTS;
    if(NUMPOINTS < 3 || N_PTS < 3 || N_PTS > NUMPOINTS){
        return false;
    }

    if(X == NULL || Y == NULL){
        return false;
    }

    for(int i = 0; i < NUMPOINTS - N_PTS+1; i++){
        double x_first = X[i];
        double x_last = X[i+N_PTS-1];
        double y_first = Y[i];
        double y_last = Y[i+N_PTS-1];

        boolean same_point = false;
        if(x_first == x_last && y_first == y_last){
            same_point = true;
        }

        for(int j = i+1; j < N_PTS; j++){
            double dist;

            if(same_point){
                dist = distance(x_first,X[j],y_first,Y[j]);
            } else{
                dist = distance_to_line(X[j],Y[j],x_first,y_first,x_last,y_last);
            }
  
            if(DOUBLECOMPARE(dist,PARAMETERS.DIST) == GT){
                return true;
            }
        }
    }
    return false;
}

/*
* Calculates the (shortest) distance from a point (x,y) to a line. It is calculated
* from getting the perpendicular point on the line from the given point. The calculation
* is derived from the equation for a triangle's area; A=(b*h)/2
* https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line
*
* @param x0 x-coordinate of the point
* @param y0 y-coordinate of the point
* @param x1 x-coordinate for one of the points making the line
* @param y1 y-coordinate for one of the points making the line
* @param x2 x-coordinate for the other point making the line
* @param y2 y-coordinate for the other point making the line
* @return The distance between the point (x0,y0) and the line between (x1,y1) and (x2,y2)
*/
double distance_to_line(double x0, double y0, double x1, double y1, double x2, double y2){
    return fabs((x2-x1)*(y1-y0)-(x1-x0)*(y2-y1)) / distance(x1,x2,y1,y2);
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
* Function which returns the largest out of three doubles.
* 
* @param a The first double to be compared
* @param b The second double to be compared.
* @param c The third double to be compared.
* @return The largest value out of the three
*/
double largest_3 (double a, double b, double c) {
    if(a > b && a > c)
        return a;
    else if (b > c)
        return b;
    else
        return c;
}

/*
* There exists at least one set of three data points separated by exactly APTS
* and BPTS consecutive intervening points, respectively, that cannot be contained 
* within or on a circle of radius RADIUS1. 
* The condition is not met when NUMPOINTS < 5.
* 1 ≤ APTS, 1 ≤ BPTS 
* APTS + BPTS ≤ (NUMPOINTS − 3)
*/
boolean check_lic_8(void){
    if(PARAMETERS.APTS < 1 || PARAMETERS.BPTS < 1 ||
    PARAMETERS.APTS + PARAMETERS.BPTS > NUMPOINTS - 3)
        return false;

    if(NUMPOINTS < 5)
        return false;

    for(int i = 0; i + PARAMETERS.APTS + PARAMETERS.BPTS < NUMPOINTS - 3; i++) {
        int a = i + PARAMETERS.APTS;
        int b = a + PARAMETERS.BPTS;

        double x[3] = {*(X+i), *(X+a), *(X+b)};
        double y[3] = {*(Y+i), *(Y+a), *(Y+b)};

        double ab = distance(x[0], x[1], y[0], y[1]);
        double bc = distance(x[1], x[2], y[1], y[2]);
        double ac = distance(x[0], x[2], y[0], y[2]);

        double diameter = largest_3(ab, ac, ab);

        if(diameter > PARAMETERS.RADIUS1*2)
            return true;
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

boolean check_lic_9(void){
    if(1 > PARAMETERS.CPTS || 1 > PARAMETERS.DPTS || PARAMETERS.CPTS + PARAMETERS.DPTS > NUMPOINTS - 3){
        return false;
    }
    if(X == NULL || Y == NULL){
        return false;
    }
    if(NUMPOINTS < 5){
        return false;
    }

    for(int i=0; i + PARAMETERS.CPTS + 1 + PARAMETERS.DPTS + 1 < NUMPOINTS; i++){
        int j = i + PARAMETERS.CPTS + 1;
        int k = j + PARAMETERS.DPTS + 1;

        double x1 = X[i]; double x2 = X[j]; double x3 = X[k];
        double y1 = Y[i]; double y2 = Y[j]; double y3 = Y[k];

        if((x1 == x2) && (y1 == y2)){
            continue;
        } else if((x3 == x2) && (y3 == y2)){
            continue;
        }

        // Method inspired by https://stackoverflow.com/a/31334882/19188850
        // Returns a number between -pi and pi (Whether the interval is closed, half-closed or open should be tested)
        double angle =  atan2(y1 - y2, x1 - x2) - atan2(y3 - y2, x3 - x2);

        if(angle < 0){
            // This needs to be tested, might need to get replaced by `angle += 2*PI;`
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

/*
* Checks the condition for LIC 10, 
* there exists at least one set of three data points separated by exactly E_PTS and F_PTS
* consecutive intervening points, respectively, that are the vertices of a triangle with 
* area greater than AREA1.
*
* @return true if the condition is met, false otherwise.
*/
boolean check_lic_10(void){
    int E_PTS = PARAMETERS.EPTS;
    int F_PTS = PARAMETERS.FPTS;
	//condition is not met when NUMPOINTS < 5, or when E_PTS / F_PTS is 0 or lower
	if(NUMPOINTS < 5 || E_PTS < 1 || F_PTS < 1){
		return false;
	}
	if(E_PTS + F_PTS > NUMPOINTS-3){
		return false;
	}
	
	for(int index1 = 0; index1 < NUMPOINTS-(E_PTS+F_PTS+2); index1++){
		int index2 = index1 + E_PTS + 1;
		int index3 = index2 + F_PTS + 1;
		
		double ab = distance(X[index1], X[index2], Y[index1],Y[index2]);
		double ac = distance(X[index1], X[index3], Y[index1],Y[index3]);
		double bc = distance(X[index2], X[index3], Y[index2],Y[index3]);
		
		if (ab == 0 || ac == 0 || bc == 0){
			return false;
		}
		
		double area = triangle_area(ab,ac,bc);
     
		if(DOUBLECOMPARE(area, PARAMETERS.AREA1) == GT){
			return true;
		}
	}
    return false;
}

boolean check_lic_11(void){
    if(1 > PARAMETERS.GPTS || PARAMETERS.GPTS > NUMPOINTS - 2){
        return false;
    }
    for(int p1Index=0; p1Index + PARAMETERS.GPTS + 1 < NUMPOINTS; p1Index++){
        int p2Index = p1Index + PARAMETERS.GPTS + 1;
        if(DOUBLECOMPARE(X[p2Index] - X[p1Index], 0.0) == LT){
            return true;
        }
    }
    return false;
}

/*
* Given the indexes for two points, returns the slope of the line joining the points
* found at these indices. Doesn't check the validity of X and Y arrays so
* that check must be done externally. This method does not return accurate results
* when the two points are the same.
* 
* @param i The index of the first point in the X and Y arrays.
* @param j The index of the second point in the the X and Y arrays.
* @return The slope of the line joining the first line to the second
*/
double slope_by_index(int i, int j){
    double delta_y = Y[j] - Y[i];
    double delta_x = X[j] = X[i];

    if(delta_x == 0){
        return 99999999999;
    } else{
        return delta_y / delta_x;
    }
    

}

/*
* Given the indexes for two points, returns the angle that has the point at index j 
* as its vertex. Doesn't check the validity of X and Y arrays so
* that check must be done externally. This method always returns an answer less than PI.
* 
* @param i The index of the first point in the X and Y arrays.
* @param j The index of the vertex of the angle in the the X and Y arrays.
* @param k The index of the second point in the the X and Y arrays.
* @return The slope of the line joining the first line to the second
*/
double angle_by_index(int i, int j, int k){
    int x1 = X[i]; int y1 = Y[i];
    int x2 = X[j]; int y2 = Y[j];
    int x3 = X[k]; int y3 = Y[k];

    // Method inspired by https://stackoverflow.com/a/31334882/19188850
    // Returns a number between -pi and pi (Whether the interval is closed, half-closed or open should be tested)
    double angle =  atan2(y1 - y2, x1 - x2) - atan2(y3 - y2, x3 - x2);

    if(angle < 0){
        // This needs to be tested, might need to get replaced by angle += 2*PI;
        angle = -angle;
    }

    if(DOUBLECOMPARE(angle, PI) == GT){
        angle = (2 * PI) - angle;
    }
    
    return angle;
}

/*
* Checks the condition for LIC 13, which is there exists at least one set of three data points, separated by exactly A PTS and B PTS
* consecutive intervening points, respectively, that cannot be contained within or on a circle of
* radius RADIUS1. In addition, there exists at least one set of three data points (which can be
* the same or different from the three data points just mentioned) separated by exactly A PTS
* and B PTS consecutive intervening points, respectively, that can be contained in or on a
* circle of radius RADIUS2. Both parts must be true for the LIC to be true. The condition is
* not met when NUMPOINTS < 5.
* 0 < RADIUS2
*
* @return true if the condition is met, false otherwise.
*/
boolean check_lic_13(void){
    // Since it is the case with every other LIC, I will be assuming that A and B are both at least 1.
    // I will further be assuming that RADIUS1 has to be bigger than 0.
    if(1 > PARAMETERS.APTS || 1 > PARAMETERS.BPTS || NUMPOINTS < 5 || 0 >= PARAMETERS.RADIUS2 || 0 >= PARAMETERS.RADIUS1){
            return false;
    }

    if(X == NULL || Y == NULL){
        return false;
    }
    
    int cond1 = false;
    int cond2 = false;

    for(int i=0; i + PARAMETERS.APTS + 1 + PARAMETERS.BPTS + 1 < NUMPOINTS; i++){
        int j = i + PARAMETERS.APTS + 1;
        int k = j + PARAMETERS.BPTS + 1;


        double dist1 = distance_by_index(i, j);
        double dist2 = distance_by_index(j, k);
        double dist3 = distance_by_index(i, k);
        double slope1 = slope_by_index(i,j);
        double slope2 = slope_by_index(j,k);
        double slope3 = slope_by_index(i,k);
        double angle1 = angle_by_index(i,j,k);
        double angle2 = angle_by_index(i,k,j);
        double angle3 = angle_by_index(k,i,j);



        double largest_dist = largest_3(dist1, dist2, dist3);
        double largest_angle = largest_3(angle1, angle2, angle3);

        // To find the smallest circle that can contain these 3 points, we will use the method proposed at
        // https://math.stackexchange.com/a/2234810, with a few more checks in case the three points don't 
        // form a triangle.

        int R;
        // If two points are the same, or if the three points are on the same line (they don't form a triangle),
        // or if they form an obtuse triangle,
        // checking that the largest distance is less than RADIUS * 2 is sufficient.
        if((X[i] == X[j] && Y[i] == Y[j]) ||
           (X[i] == X[k] && Y[i] == Y[k]) ||
           (X[j] == X[k] && Y[j] == Y[k]) ||
           DOUBLECOMPARE(slope1, slope2) == EQ || 
           DOUBLECOMPARE(slope1, slope3) == EQ ||
           DOUBLECOMPARE(slope2, slope3) == EQ ||
           DOUBLECOMPARE(largest_angle, PI/2) == GT){

            R = largest_dist / 2;
        } else{
            // If the three points instead form an acute triangle, the radius of the circumscribed circle
            // is the smallest radius these 3 points can fit in.

            int s = (dist1 + dist2 + dist3) / 2;
            R = (dist1*dist2*dist3) / (4*sqrt(s * (s-dist1) * (s - dist2) * (s - dist3)));

        }
        
        if(DOUBLECOMPARE(R, PARAMETERS.RADIUS1) == GT){
            cond1 = true;
        }
        if(DOUBLECOMPARE(R, PARAMETERS.RADIUS2) == LT){
            cond2 = true;
        }
    }

    return cond1 && cond2;
}

/*
* There exists at least one set of two data points, separated by exactly KPTS
* consecutive intervening points, which are a distance greater than the length,
* LENGTH1, apart. In addition, there exists at least one set of two data points 
* (which can be the same or different fromthe two data points just mentioned), 
* separated by exactly KPTS consecutive intervening points, that are a distance 
* less than the length, LENGTH2, apart. Both parts must be true for the LIC to be true. 
* The condition is not met when NUMPOINTS < 3.
* 0 ≤ LENGTH2
*/
boolean check_lic_12(void){
    if(NUMPOINTS < 3 || PARAMETERS.LENGTH2 < 0)
        return false;

    for(int i = 0; i + PARAMETERS.KPTS + 1 < NUMPOINTS; i++) {
        int j = i + PARAMETERS.KPTS + 1;

        double dist = distance(*(X+i), *(X+j), *(Y+i), *(Y+j));


        if(dist > PARAMETERS.LENGTH1 && dist < PARAMETERS.LENGTH2)
            return true;
    }

    return false;
}

/*
* Checks the condition for LIC 14, 
* there exists at least one set of three data points, separated by exactly E_PTS and F_PTS 
* consecutive points, respectively, that make up a triangle with a bigger area than AREA1.
* Additionally, there exist three data points (same or different set) separated by exactly E_PTS and F_PTS 
* consecutive intervening points, respectively, that make up a triangle with a smaller area than AREA2.
* Both parts must be true for the LIC to be true.
*
* @return true if both the conditions are met, false otherwise.
*/
boolean check_lic_14(void){
    int E_PTS = PARAMETERS.EPTS;
    int F_PTS = PARAMETERS.FPTS;
    boolean cond1 = false;
    boolean cond2 = false;

    if(NUMPOINTS < 5 || PARAMETERS.AREA2 < 0 || E_PTS < 0 || F_PTS < 0){
        return false;
    }

    if(X == NULL || Y == NULL){
        return false;
    }
    
    for(int index1 = 0; index1 < NUMPOINTS-E_PTS-F_PTS-2; index1++){
        int index2 = index1 + E_PTS + 1;
        int index3 = index2 + F_PTS + 1;

        double dist1 = distance_by_index(index1, index2);
        double dist2 = distance_by_index(index1, index3);
        double dist3 = distance_by_index(index2, index3);

        double tri_area = triangle_area(dist1,dist2,dist3);
        
        if(DOUBLECOMPARE(tri_area,PARAMETERS.AREA1) == GT){
            cond1 = true;
        }

        if(DOUBLECOMPARE(tri_area,PARAMETERS.AREA2) == LT){
            cond2 = true;
        }
    }

    return cond1 && cond2;
}
