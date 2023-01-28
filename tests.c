#include "decide.h"
#include "minunit.h"
#include <stdio.h>
#include <stdbool.h>

boolean check_lic_0(void);

int tests_run = 0;

static char * test_lic0_positive(){
    NUMPOINTS2 = 10;
    PARAMETERS2.LENGTH1 = 1;
    double local_X[5];
    X2 = local_X;
    double local_Y[5];
    Y2 = local_Y;
    X2[0]=1; X2[1]=2; X2[2]=3; X2[3]=12; X2[4]=17;
    Y2[0]=1; Y2[1]=2; Y2[2]=3; Y2[3]=12; Y2[4]=22;

    printf("%d\n", check_lic_0());

    mu_assert("The positive test failed!", check_lic_0() == true);
    return 0;
}

static char * test_lic0_negative(){
    NUMPOINTS2 = 5;
    PARAMETERS2.LENGTH1 = 3;
    double local_X[5];
    X2 = local_X;
    double local_Y[5];
    Y2 = local_Y;
    X2[0]=1; X2[1]=2; X2[2]=3; X2[3]=4; X2[4]=5;
    Y2[0]=1; Y2[1]=2; Y2[2]=3; Y2[3]=4; Y2[4]=6;

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


