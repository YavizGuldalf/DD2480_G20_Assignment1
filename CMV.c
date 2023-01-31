#include "decide.h"
#include <stdbool.h>

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
//boolean check_lic_13(void);
boolean check_lic_14(void);

int CMV_initialized = false;

// Utility function allocate space for CMV
void CMV_init(void){
    CMV = calloc(LIC_COUNT, sizeof(*CMV));
    CMV_initialized = true;
}

/*
* Fills the CMV cells by calling the corresponding LIC checking function
*/
void CMV_fill(void){
    if(!CMV_initialized){
        CMV_init();
    }

    CMV[0] = check_lic_0();
    CMV[1] = check_lic_1();
    CMV[2] = check_lic_2();
    CMV[3] = check_lic_3();
    CMV[4] = check_lic_4();
    CMV[5] = check_lic_5();
    CMV[6] = check_lic_6();
    CMV[7] = check_lic_7();
    CMV[8] = check_lic_8();
    CMV[9] = check_lic_9();
    CMV[10] = check_lic_10();
    CMV[11] = check_lic_11();
    CMV[12] = check_lic_12();
    //CMV[13] = check_lic_13();
    CMV[14] = check_lic_14();
}

// Utility function to free the space allocated to CMV
void CMV_free(void){
    free(CMV);
    CMV_initialized = false;
}