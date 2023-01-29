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
*  A test where check_lic_0 should return true
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
    mu_run_test(test_lic7_negative);
    mu_run_test(test_lic7_positive);
    mu_run_test(test_lic7_invalid);
    
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
*  Runs all of the tests of lic7 until an error is encountered or all the tests are passed.
*  @returns 0 if all the tests pass, the error message of the first test that fails otherwise.
*/
static char * lic5_tests(){
    mu_run_test(test_lic5_negative);
    mu_run_test(test_lic5_positive);
    mu_run_test(test_lic5_invalid);
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

int main(int argc, char **argv) {
    //char *result = lic5_tests();
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


