#include "decide.h"
#include <stdbool.h>

const int LIC_COUNT = 15;
int FUV_initialized = false;

// Utility function to dynamicall allocate space for FUV
void init_FUV(void){
    FUV = calloc(LIC_COUNT, sizeof(*FUV));
    FUV_initialized = true;
}

/*
* Fill the FUV cells by using the values of PUM and PUV. FUV[i] should be set 
* to true if PUV[i] is false (indicating that the associated LIC should not
* hold back launch) or if all elements in PUM row i are true.
*/
void fill_FUV(void){
    if(!FUV_initialized){
        init_FUV();
    }

    for(int i=0; i < LIC_COUNT; i++){
        FUV[i] = true;
        // A value in the FUV is false iff PUV[i] is 
        // true and there is at least one false element in the PUM row
        if(PUV[i] == true){
            for(int j=0; j < LIC_COUNT; j++){
                FUV[i] = FUV[i] && PUM[i][j];
            }
        }
    }
}

// Utility function to free the space allocated to FUV
void free_FUV(void){
    free(FUV);
    FUV_initialized = false;
}