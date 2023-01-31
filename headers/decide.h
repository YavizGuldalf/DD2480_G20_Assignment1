//This is version 4 of this file.
#include <math.h>
#include <stdlib.h>

////////////CONSTANT//////////
static const double PI = 3.1415926535;

static const int LIC_COUNT = 15;

////////////TYPEDECLARATIONS///////////
typedef enum {NOTUSED=777, ORR, ANDD} CONNECTORS;

//pointer to an array of 100 doubles
typedef double *COORDINATE;

//pointer to a 2−D array of [15,15] CONNECTORS
typedef CONNECTORS **CMATRIX;

//always in the range [0..1]
typedef int boolean;

//pointer to a 2−D array of [15,15] booleans
typedef boolean **BMATRIX;

//pointer to an array of 15 booleans 
typedef boolean *VECTOR;

typedef enum {LT=1111, EQ, GT} COMPTYPE;

//inputs to the DECIDE() function 
typedef struct {
 double LENGTH1; //Length in LICs 0, 7, 12
 double RADIUS1; //Radius in LICs 1, 8, 13
 double EPSILON; //Deviation from PI in LICs 2, 9
 double AREA1; //Area in LICs 3, 10, 14
 int QPTS; //No. of consecutivepoints in LIC 4
 int QUADS; //No. of quadrants in LIC 4
 double DIST; //Distance in LIC 6
 int NPTS; //No. of consecutive pts. in LIC 6
 int KPTS; //No. of int. pts. in LICs 7, 12
 int APTS; //No. of int. pts. in LICs 8, 13
 int BPTS; //No. of int. pts. in LICs 8, 13
 int CPTS; //No. of int. pts. in LIC 9
 int DPTS; //No. of int. pts. in LIC 9 
 int EPTS; //No. of int. pts. in LICs 10, 14 
 int FPTS; //No. of int. pts. in LICs 10, 14 
 int GPTS; //No. of int. pts. in LIC 11
 double LENGTH2; //Maximum length in LIC 12
 double RADIUS2; //Maximum radius in LIC 13
 double AREA2; //Maximum area in LIC 14
 } PARAMETERS_T;

 //////////// global variable declarations ////////////
 
 PARAMETERS_T PARAMETERS;
 static PARAMETERS_T PARAMETERS2;
 
 //X coordinates of data points 
 COORDINATE X;
 static COORDINATE X2;
 
 //Y coordinates of data points 
 COORDINATE Y;
 static COORDINATE Y2;
 
 //Number of data points 
 int NUMPOINTS;
 static int NUMPOINTS2;
 
 //Logical Connector Matrix
 CMATRIX LCM;
 static CMATRIX LCM2;

 // Preliminary Unlocking Vector
 VECTOR PUV;
 static VECTOR PUV2;

 //Preliminary Unlocking Matrix
 BMATRIX PUM;
 static BMATRIX PUM2;
 
 //Conditions Met Vector
 VECTOR CMV;
 static VECTOR CMV2;
 
 //Final Unlocking Vector
 VECTOR FUV;
 static VECTOR FUV2; 
 
 //Decision : Launch or No Launch
 boolean LAUNCH; 
 static boolean LAUNCH2;
 
 //compares floating point numbers −− see Nonfunctional Requirements 
 static inline 
 COMPTYPE DOUBLECOMPARE  (double A, 
 double B)
 {
    if(fabs(A - B) < 0.000001) return EQ;
    if(A < B) return LT;
    return GT;
}

//function you must write 
void DECIDE (void);

///////////// end of file /////////////