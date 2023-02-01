#include "decide.h"
#include "minunit.h"
#include <stdio.h>
#include <stdbool.h>

/*
This file is supposed to be used in the following way:
1- First, a test for a single case is written, and this test must have the return type static char *.
   In this test, the global variables (PARAMETERS, NUMPOINTS and so on) should be set up according
   to the type of test performed. At the end of the function there must be two lines. The first 
   of these lines is `mu_assert("ERROR MESSAGE", FUNCTION() == VALUE);`, where ERROR MESSAGE is
   a static string that explains the failed test, FUNCTION is the function (a condition also works)
   that is being tested, and VALUE is the expected return value of the function. The second line that
   must be present at the end of the file is `return 0;`
2- Then, these tests are supposed to be run inside another function that returns static char * (see the
   current_tests function). This outside function is only supposed to call mu_run_test with the test
   you want to run as its only parameter (you can call mu_run_test multiple times with different 
   parameters if you wish to run multiple tests). This function must also end with `return 0;`
3- Inside main, you can replace the function on the first line with the function you want to run. When 
   you compile and run the file, the result of the tests should be output to stdout.
*/

int tests_run = 0;

/*
*  A test where launch should return true
* @return 0 if the test passes, an error message otherwise
*/
static char * test_program_positive(){
    // circle and one point in the ori       
    // Condition 0: True because LENGTH1 = 0.99
    // Condition 1: True because RADIUS1 = 1.01
    // Condition 2: True because EPSILON = PI/2 - 0.01
    // Condition 3: True because AREA1 = 0.49
    // Condition 4: True because Q_PTS = 5 and QUADS = 2
    // Condition 5: True because (0, 0), (1, 0) consecutive points exist
    // Condition 6: True because DIST = 0.99 and N_PTS = 5
    // Condition 7: True because LENGTH1 = 0.99 and K_PTS = 1
    // Condition 8: False because RADIUS1 = 1.01 and A_PTS = B_PTS = 1
    // Condition 9: True because EPSILON = PI/2 -0.01 and C_PTS = D_PTS = 1
    // Condition 10: True because AREA1 = 0.49 and E_PTS = F_PTS = 1
    // Condition 11: True because G_PTS = 1
    // Condition 12: True because LENGTH1 = 0.99 and LENGTH2 = 2 and K_PTS = 1
    // Condition 13: False, see condition 8
    // Condition 14: False, see condition 10gin: (0, 0), (1, 0), (-1, 0), (0, 1), (0, -1).
    NUMPOINTS = 5;
    PARAMETERS.LENGTH1 = 0.99;   
    PARAMETERS.LENGTH2 = 2;    
    PARAMETERS.RADIUS1 = 0.99;    
    PARAMETERS.RADIUS2 = 0.01;    
    PARAMETERS.EPSILON = 0;     
    PARAMETERS.AREA1 = 0.49;    
    PARAMETERS.AREA2 = 0;       
    PARAMETERS.QUADS = 2;     
    PARAMETERS.DIST = 0.99;   
    PARAMETERS.APTS = 1;      
    PARAMETERS.BPTS = 1;       
    PARAMETERS.CPTS = 1;       
    PARAMETERS.DPTS = 1;      
    PARAMETERS.EPTS = 1;      
    PARAMETERS.FPTS = 1;       
    PARAMETERS.GPTS = 1;       
    PARAMETERS.KPTS = 1;       
    PARAMETERS.NPTS = 5;       
    PARAMETERS.QPTS = 5;        

    double local_X[5];
    double local_Y[5];
    X = local_X;
    Y = local_Y;
    X[0] = 0; X[1] = 1; X[2] = -1; X[3] = 0; X[4] = 0;
    Y[0] = 0; Y[1] = 0; Y[2] = 0; Y[3] = 1; Y[4] = -1;
    


    CONNECTORS local_LCM[15][15] = 
            {{ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD}};
    CONNECTORS* local_LCM_2[15];
    for(int i=0; i<15; i++){
        local_LCM_2[i] = local_LCM[i];
    }
    LCM = local_LCM_2;


    int local_PUV[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };
    PUV = local_PUV;

    DECIDE();
    mu_assert("The positive test failed", LAUNCH == true);
    return 0;
}

/*
*  A test where launch should return false
* @return 0 if the test passes, an error message otherwise
*/
static char * test_program_negative(){
    NUMPOINTS = 3;
    PARAMETERS.LENGTH1 = 0.5;   
    PARAMETERS.LENGTH2 = 0;    
    PARAMETERS.RADIUS1 = 0.01;    
    PARAMETERS.RADIUS2 = 0;    
    PARAMETERS.EPSILON = PI - 0.01;     
    PARAMETERS.AREA1 = 2;    
    PARAMETERS.AREA2 = 0;       
    PARAMETERS.QUADS = 3;     
    PARAMETERS.DIST = 6;   
    PARAMETERS.APTS = 1;      
    PARAMETERS.BPTS = 1;       
    PARAMETERS.CPTS = 1;       
    PARAMETERS.DPTS = 1;      
    PARAMETERS.EPTS = 1;      
    PARAMETERS.FPTS = 1;       
    PARAMETERS.GPTS = 1;       
    PARAMETERS.KPTS = 1;       
    PARAMETERS.NPTS = 3;       
    PARAMETERS.QPTS = 3;        

    double local_X[NUMPOINTS];
    double local_Y[NUMPOINTS];
    X = local_X;
    Y = local_Y;
    X[0] = 0; X[1] = 0; X[2] = -1;
    Y[0] = 0; Y[1] = -1; Y[2] = 0;
    


    CONNECTORS local_LCM[15][15] = 
            {{ANDD, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED},
                {NOTUSED, ANDD, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED},
                {NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED},
                {NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD}
            };
    CONNECTORS* local_LCM_2[15];
    for(int i=0; i<15; i++){
        local_LCM_2[i] = local_LCM[i];
    }
    LCM = local_LCM_2;


    int local_PUV[] = {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true };
    PUV = local_PUV;

    DECIDE();
    mu_assert("The negative test failed", LAUNCH == false);
    return 0;
}

/*
*  A test where launch should return false with an invalid input
* @return 0 if the test passes, an error message otherwise
*/
static char * test_program_invalid(){

    NUMPOINTS = 100;
    PARAMETERS.LENGTH1 = 0.99;   
    PARAMETERS.LENGTH2 = 2;    
    PARAMETERS.RADIUS1 = 0.99;    
    PARAMETERS.RADIUS2 = 0.01;    
    PARAMETERS.EPSILON = 0;     
    PARAMETERS.AREA1 = 0.49;    
    PARAMETERS.AREA2 = 0;       
    PARAMETERS.QUADS = 2;     
    PARAMETERS.DIST = 0.99;   
    PARAMETERS.APTS = 1;      
    PARAMETERS.BPTS = 1;       
    PARAMETERS.CPTS = 1;       
    PARAMETERS.DPTS = 1;      
    PARAMETERS.EPTS = 1;      
    PARAMETERS.FPTS = 1;       
    PARAMETERS.GPTS = 1;       
    PARAMETERS.KPTS = 1;       
    PARAMETERS.NPTS = 5;       
    PARAMETERS.QPTS = 5;        

    double local_X[5];
    double local_Y[5];
    X = local_X;
    Y = local_Y;
    X[0] = 0; X[1] = 1; X[2] = -1; X[3] = 0; X[4] = 0;
    Y[0] = 0; Y[1] = 0; Y[2] = 0; Y[3] = 1; Y[4] = -1;
    


    CONNECTORS local_LCM[15][15] = 
            {{ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD, NOTUSED},
                {NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, ANDD}};
    CONNECTORS* local_LCM_2[15];
    for(int i=0; i<15; i++){
        local_LCM_2[i] = local_LCM[i];
    }
    LCM = local_LCM_2;


    int local_PUV[] = {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true };
    PUV = local_PUV;
    mu_assert("The invalid test failed", LAUNCH == false);
    return 0;
}

/* This functions runs all the tests currently prepared for this revision.
*  Any new tests that are implemented should be added to this function as well.
*
*/
static char * all_tests() {
    mu_run_test(test_program_positive);
    mu_run_test(test_program_negative);
    mu_run_test(test_program_invalid);
    return 0;
}

/*
*  Utility method to run only the tests you choose.
*  @return 0 if the test is successfull, an error message otherwise
*/
static char * current_tests() {
    mu_run_test(test_program_positive);
    return 0;
}

int main(int argc, char **argv) {
    char *result = all_tests();

    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}