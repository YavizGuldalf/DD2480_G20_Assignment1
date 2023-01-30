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

/*
    Yagiz:
    I suggest creating a positive, negative and an invalid test for each lic. Then these three tests can
    be grouped in a function like the one explained in step 2 above. (Don't forget to also add it to all_tests).
    This keeps the tests more organized and any specific lic can easily be tested for all test cases by just
    changing a single line (the first line of main).
*/



boolean check_lic_0(void);
boolean check_lic_1(void);
boolean check_lic_2(void);
boolean check_lic_3(void);
boolean check_lic_4(void);
boolean check_lic_5(void);
boolean check_lic_6(void);
boolean check_lic_7(void);
boolean check_lic_8(void);
boolean check_lic_9(void);
boolean check_lic_10(void);
boolean check_lic_11(void);
boolean check_lic_12(void);
boolean check_lic_13(void);
boolean check_lic_14(void);

int tests_run = 0;

/*
*  A test where check_lic_0 should return true
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic0_positive(){
    NUMPOINTS = 10;
    PARAMETERS.LENGTH1 = 1;
    double local_X[5];
    X = local_X;
    double local_Y[5];
    Y = local_Y;
    X[0]=1; X[1]=2; X[2]=3; X[3]=12; X[4]=17;
    Y[0]=1; Y[1]=2; Y[2]=3; Y[3]=12; Y[4]=22;

    mu_assert("The positive test failed!", check_lic_0() == true);
    return 0;
}

/*
*  A test where check_lic_0 should return false
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic0_negative(){
    NUMPOINTS = 5;
    PARAMETERS.LENGTH1 = 3;
    double local_X[5];
    X = local_X;
    double local_Y[5];
    Y = local_Y;
    X[0]=1; X[1]=2; X[2]=3; X[3]=4; X[4]=5;
    Y[0]=1; Y[1]=2; Y[2]=3; Y[3]=4; Y[4]=6;

    mu_assert("The negative test failed!", check_lic_0() == false);
    return 0;
}

/*
*  A test where check_lic_0 should return false with an invalid input
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic0_invalid(){
    NUMPOINTS = 4;
    PARAMETERS.LENGTH1 = 1;
    X = NULL;
    Y = NULL;
    mu_assert("The invalid test failed!", check_lic_0() == false);
    return 0;
}

/*
*  A test where check_lic_4 should return true
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic4_positive(){
    NUMPOINTS = 7;
    PARAMETERS.QPTS = 4;
    PARAMETERS.QUADS = 2;
    double local_X[7] = {0,2,-1,-1,5,6,7};
    X = local_X;
    double local_Y[7] = {0,-1,4,-1,10,13,14};
    Y = local_Y;

    mu_assert("The positive test for LIC 4 failed!", check_lic_4() == true);
    return 0;
}

/*
*  A test where check_lic_4 should return false
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic4_negative(){
    NUMPOINTS = 7;
    PARAMETERS.QPTS = 4;
    PARAMETERS.QUADS = 2;
    double local_X[7] = {0,2,1,-1,5,6,7};
    X = local_X;
    double local_Y[7] = {0,1,4,1,10,13,14};
    Y = local_Y;

    mu_assert("The negative test for LIC 4 failed!", check_lic_4() == false);
    return 0;
}

/*
*  A test where check_lic_4 should return false with an invalid input
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic4_invalid(){
    NUMPOINTS = 7;
    PARAMETERS.QPTS = 1;
    PARAMETERS.QUADS = 2;
    double local_X[7] = {0,2,-1,-1,5,6,7};
    X = local_X;
    double local_Y[7] = {0,-1,4,-1,10,13,14};
    Y = local_Y;

    mu_assert("The invalid test for LIC 4 failed!", check_lic_4() == false);
    return 0;
}

/*
*  A test where check_lic_5 should return true
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic5_positive(){
    NUMPOINTS = 2;
    double local_X[2];
    X = local_X;
    double local_Y[2];
    Y = local_Y;
    X[0]=2; X[1]=1;
    Y[0]=1; Y[1]=2;

    mu_assert("The positive test for LIC 5 failed!", check_lic_5() == true);
    return 0;
}

/*
*  A test where check_lic_5 should return false
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic5_negative(){
    NUMPOINTS = 2;
    double local_X[2];
    X = local_X;
    double local_Y[2];
    Y = local_Y;
    X[0]=2; X[1]=10;
    Y[0]=1; Y[1]=2;

    mu_assert("The negative test for LIC 5 failed!", check_lic_5() == false);
    return 0;
}

/*
*  A test where check_lic_5 should return false with an invalid input
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic5_invalid(){
    NUMPOINTS = 2;
    X = NULL;
    Y = NULL;
    mu_assert("The invalid test for LIC 5 failed!", check_lic_5() == false);
    return 0;
}

/*
*  A test where check_lic_6 should return true
*  The distance from point (2,3) is about 0.83205... to 
*  the line between (1,3),(3,0).
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic6_positive(){
    NUMPOINTS = 3;
    PARAMETERS.DIST = 0.83;
    PARAMETERS.NPTS = 3;
    double local_X[3] = {1,2,3};
    X = local_X;
    double local_Y[3] = {3,3,0};
    Y = local_Y;

    mu_assert("The positive test failed for lic6!", check_lic_6() == true);
    return 0;
}

/*
*  A test where check_lic_6 should return false
* The distance from point (-5,0) is about 0.707... to 
*  the line between (-2,-2),(-6,2).
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic6_negative(){
    NUMPOINTS = 3;
    PARAMETERS.DIST = 1;
    PARAMETERS.NPTS = 3;
    double local_X[3] = {-2,-5,-6};
    X = local_X;
    double local_Y[3] = {-2,0,2};
    Y = local_Y;

    mu_assert("The negative test for LIC 6 failed!", check_lic_6() == false);
    return 0;
}

/*
*  A test where check_lic_6 should return false with an invalid input
*  The invalid input in this case is that N_PTS > NUMPOINTS
* The test would otherwise succeed, if N_PTS = 3
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic6_invalid(){
    NUMPOINTS = 3;
    PARAMETERS.DIST = 0.83;
    PARAMETERS.NPTS = 4;
    double local_X[3] = {1,2,3};
    X = local_X;
    double local_Y[3] = {3,3,0};
    Y = local_Y;

    mu_assert("The invalid test for LIC 6 failed!", check_lic_6() == false);
    return 0;
}

/*
*  A test where check_lic_7 should return true
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic7_positive(){
    NUMPOINTS = 7;
    PARAMETERS.LENGTH1 = 13;
    PARAMETERS.KPTS = 4;
    double local_X[7] = {1,2,3,4,5,6,7};
    X = local_X;
    double local_Y[7] = {1,2,4,8,10,13,15};
    Y = local_Y;

    mu_assert("The positive test failed for lic7!", check_lic_7() == true);
    return 0;
}

/*
*  A test where check_lic_7 should return false
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic7_negative(){
    NUMPOINTS = 7;
    PARAMETERS.LENGTH1 = 13;
    PARAMETERS.KPTS = 4;
    double local_X[7] = {1,2,3,4,5,6,7};
    X = local_X;
    double local_Y[7] = {1,2,4,8,10,13,14};
    Y = local_Y;

    mu_assert("The negative test failed for lic7!", check_lic_7() == false);
    return 0;
}

/*
*  A test where check_lic_7 should return false with an invalid input
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic7_invalid(){
    NUMPOINTS = 5;
    PARAMETERS.LENGTH1 = 13;
    PARAMETERS.KPTS = 5;
    double local_X[7] = {1,2,3,4,5,6,7};
    X = local_X;
    double local_Y[7] = {1,2,4,8,10,13,14};
    Y = local_Y;

    mu_assert("The invalid test failed for lic7!", check_lic_7() == false);
    return 0;
}

/*
*  A test where check_lic_8 should return true
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic8_positive(){
    NUMPOINTS = 7;
    PARAMETERS.RADIUS1 = 3;
    PARAMETERS.APTS = 1;
    PARAMETERS.BPTS = 2;
    double local_X[7] = {1,2,3,4,5,6,7};
    X = local_X;
    double local_Y[7] = {1,2,4,8,10,13,15};
    Y = local_Y;

    mu_assert("The positive test failed for lic8!", check_lic_8() == true);
    return 0;
}

/*
*  A test where check_lic_8 should return false
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic8_negative(){
    NUMPOINTS = 7;
    PARAMETERS.RADIUS1 = 3;
    PARAMETERS.APTS = 1;
    PARAMETERS.BPTS = 2;
    double local_X[7] = {1,2,2,1,2,-1,1};
    X = local_X;
    double local_Y[7] = {1,2,2,2,1,1,-1};
    Y = local_Y;

    mu_assert("The negative test failed for lic8!", check_lic_8() == false);
    return 0;
}

/*
*  A test where check_lic_8 should return false with an invalid input
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic8_invalid(){
    NUMPOINTS = 7;
    PARAMETERS.RADIUS1 = 3;
    PARAMETERS.APTS = 0;
    PARAMETERS.BPTS = 2;
    double local_X[7] = {1,2,3,4,5,6,7};
    X = local_X;
    double local_Y[7] = {1,2,4,8,10,13,15};
    Y = local_Y;

    mu_assert("The invalid test failed for lic8!", check_lic_8() == false);
    return 0;
}

/*
*  A test where check_lic_9 should return true
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic9_positive(){
    NUMPOINTS = 8;
    PARAMETERS.CPTS= 1;
    PARAMETERS.DPTS = 3;
    PARAMETERS.EPSILON = 0.6981317008;
    double local_X[8] = {1,2,3,4,2,3,5,4};
    X = local_X;
    double local_Y[8] = {1,2,3,4,4,9,25,16};
    Y = local_Y;

    mu_assert("The positive test failed for lic9!", check_lic_9() == true);
    return 0;
}


/*
*  A test where check_lic_9 should return false
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic9_negative(){
    NUMPOINTS = 8;
    PARAMETERS.CPTS= 1;
    PARAMETERS.DPTS = 3;
    PARAMETERS.EPSILON = 0.6981317008;
    double local_X[8] = {1,2,3,4,2,3,5,5};
    X = local_X;
    double local_Y[8] = {1,2,3,4,4,9,25,8};
    Y = local_Y;

    mu_assert("The negative test failed for lic9!", check_lic_9() == false);
    return 0;
}


/*
*  A test where check_lic_9 should return false with an invalid input
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic9_invalid(){
    NUMPOINTS = 5;
    PARAMETERS.CPTS= 1;
    PARAMETERS.DPTS = 3;
    PARAMETERS.EPSILON = 0.6981317008;
    double local_X[8] = {1,2,3,4,2,3,5,4};
    X = local_X;
    double local_Y[8] = {1,2,3,4,4,9,25,12};
    Y = local_Y;

    mu_assert("The invalid test failed for lic9!", check_lic_9() == false);
    return 0;
}

/*
*  A test where check_lic_10 should return true
*  Produces a triangle with area 2.0 which is larger than AREA1 = 1.9
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic10_positive(){
    NUMPOINTS = 8;
    PARAMETERS.EPTS = 2;
    PARAMETERS.FPTS = 3;
    PARAMETERS.AREA1 = 1.9;
    double local_X[8] = {1,2,2,3,4,5,10,2};
    X = local_X;
    double local_Y[8] = {0,2,1,0,8,1.4,1.3,2};
    Y = local_Y;

    mu_assert("The positive test failed for lic10!", check_lic_10() == true);
    return 0;
}

/*
*  A test where check_lic_10 should return false
*  Produces a triangle with area 2.0 which is smaller than AREA1 = 2.001
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic10_negative(){
    NUMPOINTS = 5;
    PARAMETERS.EPTS = 1;
    PARAMETERS.FPTS = 1;
    PARAMETERS.AREA1 = 2.001;
    double local_X[5] = {1,2,3,4,2};
    X = local_X;
    double local_Y[5] = {0,2,0,8,2};
    Y = local_Y;

    mu_assert("The negative test failed for lic10!", check_lic_10() == false);
    return 0;
}

/*
*  A test where check_lic_10 should return false with an invalid input
*  Invalid because NUMPOINTS < 5
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic10_invalid(){
    NUMPOINTS = 4;
    PARAMETERS.EPTS = 2;
    PARAMETERS.FPTS = 3;
    PARAMETERS.AREA1 = 1.9;
    double local_X[8] = {1,2,2,3,4,5,10,2};
    X = local_X;
    double local_Y[8] = {0,2,1,0,8,1.4,1.3,2};
    Y = local_Y;

    mu_assert("The invalid test failed for lic10!", check_lic_10() == false);
    return 0;
}

/*
*  A test where check_lic_11 should return true
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic11_positive(void){
    NUMPOINTS = 7;
    PARAMETERS.GPTS = 2;
    double local_X[7] = {1,2,3,4,5,6,3.8};
    X = local_X;
    double local_Y[7] = {1,2,4,8,10,13,14};
    Y = local_Y;

    mu_assert("The positive test failed for lic11!", check_lic_11() == true);
    return 0;
}

/*
*  A test where check_lic_11 should return false
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic11_negative(void){
    NUMPOINTS = 7;
    PARAMETERS.GPTS = 2;
    double local_X[7] = {1,2,3,4,5,6,8};
    X = local_X;
    double local_Y[7] = {1,2,4,8,10,13,14};
    Y = local_Y;

    mu_assert("The negative test failed for lic11!", check_lic_11() == false);
    return 0;
}

/*
*  A test where check_lic_11 should return false with an invalid input
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic11_invalid(void){
    NUMPOINTS = 7;
    PARAMETERS.GPTS = 0;
    double local_X[7] = {1,2,3,4,5,6,8};
    X = local_X;
    double local_Y[7] = {1,2,4,8,10,13,14};
    Y = local_Y;

    mu_assert("The invalid test failed for lic11!", check_lic_11() == false);
    return 0;
}

/*
*  A test where check_lic_12 should return true
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic12_positive(void){
    NUMPOINTS = 7;
    PARAMETERS.KPTS = 2;
    PARAMETERS.LENGTH1 = 2;
    PARAMETERS.LENGTH2 = 4;
    double local_X[7] = {1,2,4,4,5,6,3.8};
    X = local_X;
    double local_Y[7] = {1,2,1,1,10,13,14};
    Y = local_Y;

    mu_assert("The positive test failed for lic12!", check_lic_12() == true);
    return 0;
}

/*
*  A test where check_lic_12 should return false
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic12_negative(void){
    NUMPOINTS = 7;
    PARAMETERS.KPTS = 2;
    PARAMETERS.LENGTH1 = 2;
    PARAMETERS.LENGTH2 = 4;
    double local_X[7] = {0,2,4,8,5,6,3.8};
    X = local_X;
    double local_Y[7] = {0,2,4,8,14,16,20};
    Y = local_Y;

    mu_assert("The negative test failed for lic12!", check_lic_12() == false);
    return 0;
}

/*
*  A test where check_lic_12 should return false with an invalid input
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic12_invalid(void){
    NUMPOINTS = 7;
    PARAMETERS.KPTS = 2;
    PARAMETERS.LENGTH1 = 2;
    PARAMETERS.LENGTH2 = -1;
    double local_X[7] = {1,2,3,4,5,6,3.8};
    X = local_X;
    double local_Y[7] = {1,2,4,8,10,13,14};
    Y = local_Y;

    mu_assert("The invalid test failed for lic12!", check_lic_12() == false);
    return 0;
}

/*
*  A test where check_lic_14 should return true
*  Makes triangle out of points (0,0), (2,0) and (1,-2) which has area of 2.
*  That is larger than AREA1 = 1.5 and smaller than AREA2 = 2.1
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic14_positive(){
    NUMPOINTS = 5;
    PARAMETERS.EPTS = 1;
    PARAMETERS.FPTS = 1;
    PARAMETERS.AREA1 = 1.5;
    PARAMETERS.AREA2 = 2.1;
    double local_X[5] = {0,2,2,3,1};
    X = local_X;
    double local_Y[5] = {0,2,0,0,-2};
    Y = local_Y;

    mu_assert("The positive test failed for lic14!", check_lic_14() == true);
    return 0;
}

/*
*  A test where check_lic_14 should return false
*  Makes triangle out of points (-2,-1), (1,2) and (4,-1) which has area of 9.
*  That is larger than AREA1 = 8, but not smaller than AREA2 = 2.1 and is thus false
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic14_negative(){
    NUMPOINTS = 5;
    PARAMETERS.EPTS = 1;
    PARAMETERS.FPTS = 1;
    PARAMETERS.AREA1 = 8;
    PARAMETERS.AREA2 = 2.1;
    double local_X[5] = {-2,2,1,3,4};
    X = local_X;
    double local_Y[5] = {-1,2,2,0,-1};
    Y = local_Y;

    mu_assert("The negative test failed for lic14!", check_lic_14() == false);
    return 0;
}

/*
*  A test where check_lic_14 should return false with an invalid input
*  Invalid because E_PTS = -10 (< 0)
* @return 0 if the test passes, an error message otherwise
*/
static char * test_lic14_invalid(){
    NUMPOINTS = 6;
    PARAMETERS.EPTS = -10;
    PARAMETERS.FPTS = 3;
    PARAMETERS.AREA1 = 1.9;
    PARAMETERS.AREA2 = 1.9;
    double local_X[8] = {1,2,2,3,4,5,10,2};
    X = local_X;
    double local_Y[8] = {0,2,1,0,8,1.4,1.3,2};
    Y = local_Y;

    mu_assert("The invalid test failed for lic14!", check_lic_14() == false);
    return 0;
}

/* This functions runs all the tests currently prepared for this revision.
*  Any new tests that are implemented should be added to this function as well.
*
*/
static char * all_tests() {
    mu_run_test(test_lic0_negative);
    mu_run_test(test_lic0_positive);
    mu_run_test(test_lic0_invalid);
    mu_run_test(test_lic5_positive);
    mu_run_test(test_lic5_negative);
    mu_run_test(test_lic5_invalid);
    mu_run_test(test_lic6_positive);
    mu_run_test(test_lic6_negative);
    mu_run_test(test_lic6_invalid);
    mu_run_test(test_lic7_negative);
    mu_run_test(test_lic7_positive);
    mu_run_test(test_lic7_invalid); 
    mu_run_test(test_lic8_negative);
    mu_run_test(test_lic8_positive);
    mu_run_test(test_lic8_invalid);
    mu_run_test(test_lic9_negative);
    mu_run_test(test_lic9_positive);
    mu_run_test(test_lic9_invalid);
    mu_run_test(test_lic10_negative);
    mu_run_test(test_lic10_positive);
    mu_run_test(test_lic10_invalid);
    mu_run_test(test_lic11_negative);
    mu_run_test(test_lic11_invalid);
    mu_run_test(test_lic11_positive);
    mu_run_test(test_lic12_negative);
    mu_run_test(test_lic12_invalid);
    mu_run_test(test_lic12_positive);
    mu_run_test(test_lic14_negative);
    mu_run_test(test_lic14_positive);
    mu_run_test(test_lic14_invalid);
    return 0;
}

/*
*  Utility method to run only the tests you choose.
*  @return 0 if the test is successfull, an error message otherwise
*/
static char * current_tests() {
    mu_run_test(test_lic0_positive);
    return 0;
}

/*
*  Runs all of the tests of lic0 until an error is encountered or all the tests are passed.
*  @returns 0 if all the tests pass, the error message of the first test that fails otherwise.
*/
static char * lic0_tests(){
    mu_run_test(test_lic0_negative);
    mu_run_test(test_lic0_positive);
    mu_run_test(test_lic0_invalid);
    return 0;
}

/*
*  Runs all of the tests of lic5 until an error is encountered or all the tests are passed.
*  @returns 0 if all the tests pass, the error message of the first test that fails otherwise.
*/
static char * lic5_tests(){
    mu_run_test(test_lic5_negative);
    mu_run_test(test_lic5_positive);
    mu_run_test(test_lic5_invalid);

    return 0;
}

/*
*  Runs all of the tests of lic6 until an error is encountered or all the tests are passed.
*  @returns 0 if all the tests pass, the error message of the first test that fails otherwise.
*/
static char * lic6_tests(){
    mu_run_test(test_lic6_negative);
    mu_run_test(test_lic6_positive);
    mu_run_test(test_lic6_invalid);

    return 0;
}

/*
*  Runs all of the tests of lic7 until an error is encountered or all the tests are passed.
*  @returns 0 if all the tests pass, the error message of the first test that fails otherwise.
*/
static char * lic7_tests(){
    mu_run_test(test_lic7_negative);
    mu_run_test(test_lic7_positive);
    mu_run_test(test_lic7_invalid);
    return 0;
}

/*
*  Runs all of the tests of lic8 until an error is encountered or all the tests are passed.
*  @returns 0 if all the tests pass, the error message of the first test that fails otherwise.
*/
static char * lic8_tests(){
    mu_run_test(test_lic8_negative);
    mu_run_test(test_lic8_positive);
    mu_run_test(test_lic8_invalid);
    return 0;
}

/*
*  Runs all of the tests of lic9 until an error is encountered or all the tests are passed.
*  @returns 0 if all the tests pass, the error message of the first test that fails otherwise.
*/
static char * lic9_tests(){
    mu_run_test(test_lic9_negative);
    mu_run_test(test_lic9_positive);
    mu_run_test(test_lic9_invalid);
    return 0;
}

/*
*  Runs all of the tests of lic10 until an error is encountered or all the tests are passed.
*  @returns 0 if all the tests pass, the error message of the first test that fails otherwise.
*/
static char * lic10_tests(){
    mu_run_test(test_lic10_negative);
    mu_run_test(test_lic10_positive);
    mu_run_test(test_lic10_invalid);
    return 0;
}

/*
*  Runs all of the tests of lic11 until an error is encountered or all the tests are passed.
*  @returns 0 if all the tests pass, the error message of the first test that fails otherwise.
*/
static char * lic11_tests(void){
    mu_run_test(test_lic11_negative);
    mu_run_test(test_lic11_positive);
    mu_run_test(test_lic11_invalid);

    return 0;
}

/*
*  Runs all of the tests of lic12 until an error is encountered or all the tests are passed.
*  @returns 0 if all the tests pass, the error message of the first test that fails otherwise.
*/
static char * lic12_tests(void){
    mu_run_test(test_lic12_negative);
    mu_run_test(test_lic12_positive);
    mu_run_test(test_lic12_invalid);

    return 0;
}

/*
*  Runs all of the tests of lic14 until an error is encountered or all the tests are passed.
*  @returns 0 if all the tests pass, the error message of the first test that fails otherwise.
*/
static char * lic14_tests(void){
    mu_run_test(test_lic14_negative);
    mu_run_test(test_lic14_positive);
    mu_run_test(test_lic14_invalid);

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