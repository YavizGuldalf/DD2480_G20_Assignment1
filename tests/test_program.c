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
    return 0;
}

/*
*  A test where launch should return false
* @return 0 if the test passes, an error message otherwise
*/
static char * test_program_negative(){
    return 0;
}

/*
*  A test where launch should return false with an invalid input
* @return 0 if the test passes, an error message otherwise
*/
static char * test_program_invalid(){
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