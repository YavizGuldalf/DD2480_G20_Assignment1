#include "decide.h"
#include <stdio.h>
#include <stdbool.h>

void fill_FUV(void);
void CMV_fill(void);
void fill_PUM(void);
void CMV_free();
void free_PUM();
void free_FUV();

int main(){
    NUMPOINTS = 10;
    double X_local[] = {1,0,3,-4,-2,2,14,5,9,200};
    double Y_local[] = {1,2,5,-2,6,22,13,-12,5,200};

    X = X_local;
    Y = Y_local;

    PARAMETERS.LENGTH1 = 2;
    PARAMETERS.RADIUS1 = 1.5;
    PARAMETERS.EPSILON = 0.64;
    PARAMETERS.AREA1 = 3.4;
    PARAMETERS.QPTS = 7;
    PARAMETERS.QUADS = 1;
    PARAMETERS.DIST = 10;
    PARAMETERS.NPTS = 3;
    PARAMETERS.KPTS = 2;
    PARAMETERS.APTS = 0;
    PARAMETERS.BPTS = 1;
    PARAMETERS.CPTS = 9;
    PARAMETERS.DPTS = 2;
    PARAMETERS.EPTS = 2;
    PARAMETERS.FPTS = 1;
    PARAMETERS.GPTS = 4;
    PARAMETERS.LENGTH2 = 13;
    PARAMETERS.RADIUS2 = 5.8;
    PARAMETERS.AREA2 = 2.2;

    LCM = calloc(LIC_COUNT, sizeof(*LCM));
    
    CONNECTORS LCM_0_local[] = {NOTUSED, ORR, NOTUSED, ANDD, ANDD, ANDD, ANDD, ANDD, NOTUSED, ANDD, ORR, ORR, ORR, ORR, NOTUSED};
    CONNECTORS LCM_1_local[] = {ORR, NOTUSED, NOTUSED, ORR, NOTUSED, NOTUSED, ORR, NOTUSED, NOTUSED, ANDD, ORR, NOTUSED, ORR, ORR, NOTUSED};
    CONNECTORS LCM_2_local[] = {NOTUSED, ORR, ORR, ANDD, NOTUSED, ORR, ORR, ANDD, NOTUSED, NOTUSED, ANDD, ORR, ANDD, ORR, ANDD};
    CONNECTORS LCM_3_local[] = {ANDD, ANDD, ORR, ANDD, ORR, ORR, ORR, ORR, ORR, ORR, ORR, ORR, ORR, ORR, ORR};
    CONNECTORS LCM_4_local[] = {ANDD, ANDD, ORR, ANDD, ANDD, ORR, ORR, ORR, NOTUSED, NOTUSED, ORR, NOTUSED, ORR, NOTUSED, NOTUSED};
    CONNECTORS LCM_5_local[] = {NOTUSED, NOTUSED, NOTUSED, NOTUSED, ORR, ANDD, ANDD, ORR, ANDD, ANDD, ORR, NOTUSED, NOTUSED, ANDD, ANDD};
    CONNECTORS LCM_6_local[] = {ORR, ORR, ORR, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED};
    CONNECTORS LCM_7_local[] = {NOTUSED, ORR, NOTUSED, ORR, ORR, NOTUSED, NOTUSED, ORR, NOTUSED, ORR, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED};
    CONNECTORS LCM_8_local[] = {ORR, NOTUSED, ORR, ANDD, ORR, ORR, NOTUSED, ORR, ANDD, ORR, NOTUSED, NOTUSED, ANDD, ORR, ANDD};
    CONNECTORS LCM_9_local[] = {ORR, ANDD, NOTUSED, ANDD, ANDD, NOTUSED, ANDD, NOTUSED, ORR, NOTUSED, ANDD, NOTUSED, ORR, ANDD, ORR};
    CONNECTORS LCM_10_local[] = {ORR, NOTUSED, ORR, ORR, ORR, ANDD, NOTUSED, ORR, ORR, ORR, ANDD, NOTUSED, ORR, NOTUSED, ORR};
    CONNECTORS LCM_11_local[] = {ORR, NOTUSED, ANDD, NOTUSED, NOTUSED, ANDD, ANDD, ANDD, ANDD, ORR, ORR, NOTUSED, NOTUSED, NOTUSED, NOTUSED};
    CONNECTORS LCM_12_local[] = {ORR, NOTUSED, ANDD, NOTUSED, NOTUSED, ANDD, ORR, NOTUSED, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD, ANDD};
    CONNECTORS LCM_13_local[] = {NOTUSED, ANDD, NOTUSED, NOTUSED, NOTUSED, ANDD, ANDD, ORR, NOTUSED, NOTUSED, ANDD, NOTUSED, NOTUSED, ORR, ANDD};
    CONNECTORS LCM_14_local[] = {NOTUSED, ANDD, ORR, ANDD, ANDD, ORR, ORR, ANDD, ANDD, ANDD, NOTUSED, ANDD, ORR, NOTUSED, ORR};

    LCM[0] = LCM_0_local;
    LCM[1] = LCM_1_local;
    LCM[2] = LCM_2_local;
    LCM[3] = LCM_3_local;
    LCM[4] = LCM_4_local;
    LCM[5] = LCM_5_local;
    LCM[6] = LCM_6_local;
    LCM[7] = LCM_7_local;
    LCM[8] = LCM_8_local;
    LCM[9] = LCM_9_local;
    LCM[10] = LCM_10_local;
    LCM[11] = LCM_11_local;
    LCM[12] = LCM_12_local;
    LCM[13] = LCM_13_local;
    LCM[14] = LCM_14_local;
    
    int PUV_local[] = {0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0};

    PUV = PUV_local;

    DECIDE();

    if(LAUNCH == true){
        printf("LAUNCH\n");
    } else{
        printf("NO LAUNCH\n");
    }
}
/*
* The main decision function of the program. It sets the LAUNCH variable to true or false. Rules for how the calculation is made
* can be found on the link in the readme.
*/
void DECIDE(void){

    if(NUMPOINTS < 2 || NUMPOINTS > 100){
        LAUNCH = false;
        return;
    }

    CMV_fill();
    fill_PUM();
    fill_FUV();
    
    LAUNCH = true;

    for(int i=0; i<LIC_COUNT; i++){
        LAUNCH = LAUNCH && FUV[i];
    }
    
    CMV_free();
    free_PUM();
    free_FUV();
}