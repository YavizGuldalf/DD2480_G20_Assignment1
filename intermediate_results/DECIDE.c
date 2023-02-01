#include "decide.h"
#include <stdio.h>
#include <stdbool.h>

void fill_FUV(void);
void CMV_fill(void);
void fill_PUM(void);
void CMV_free();
void free_PUM();
void free_FUV();

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