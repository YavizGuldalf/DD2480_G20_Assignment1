#include "decide.h"
#include "minunit.h"
#include <stdio.h>
#include <stdbool.h>

boolean check_lic_0(void);

int tests_run = 0;

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


static char * all_tests() {
    mu_run_test(test_lic0_negative);
    mu_run_test(test_lic0_positive);
    return 0;
}

static char * current_tests() {
    mu_run_test(test_lic0_positive);
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


