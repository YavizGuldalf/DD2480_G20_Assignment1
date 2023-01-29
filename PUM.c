#include "decide.h"
#include <stdbool.h>
#include <stdlib.h>

int PUM_initialized = false;
const int LIC_COUNT = 15;

// Utility function to dynamically allocate space for the PUM
void init_PUM(void){
    PUM = calloc(LIC_COUNT, sizeof(*PUM));
    for(int i=0; i < LIC_COUNT; i++){
        PUM[i] = calloc(LIC_COUNT, sizeof(*(PUM[i])));
    }
    PUM_initialized = true;
}

/*
* Fills each cell of the PUM by first taking a look at the value of LCM corresponding
* to that row, and that applying the appropriate operation to two elements from CMV.
*/
void fill_PUM(void){

    if(!PUM_initialized){
        init_PUM();
    }

    for(int row=0; row < LIC_COUNT; row++){
        for(int col=0; col < LIC_COUNT; col++){
            switch (LCM[row][col]){
                case NOTUSED:
                    PUM[row][col] = true;
                    break;
                case ANDD:
                    PUM[row][col] = CMV[row] && CMV[col];
                    break;
                case ORR:
                    PUM[row][col] = CMV[row] || CMV[col];
                    break;
            }
        }
    }
}

// Utility function to free the space allocated to PUM
void free_PUM(void){

    for(int i=0; i < LIC_COUNT; i++){
        free(PUM[i]);
    }
    free(PUM);
}
