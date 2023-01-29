#include "decide.h"
#include <stdio.h>
#include <stdbool.h>

const int LIC_COUNT = 15;

void fill_FUV(void);
void CMV_fill(void);
void fill_PUM(void);

// Makes the final decision of launching or not launching
int main(){
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

    if(LAUNCH == true){
        printf("LAUNCH\n");
    } else{
        printf("NO LAUNCH\n");
    }
}