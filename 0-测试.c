#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int add[7] = {20,3,11,18,9,14,7};

    for(int i =0;i<7;i++){
        printf("%d - %d\n",add[i],(add[i] * 3)%11);
    }
    // short si = -32767;
    unsigned short usi = 65535;
    short si=usi;
    printf("%d",si);
}