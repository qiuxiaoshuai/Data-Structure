#include <stdio.h>
#include <stdlib.h>
#include <math.h>


unsigned umul(unsigned x,unsigned y){return x*y;}
int imul(int x,int y){ return x*y;}
int main(){
    unsigned int x = 134;
    unsigned int y = 246;
    int m=x;
    int n=y;
    unsigned int z1=x-y;
    unsigned int z2=x+y;
    int k1 = m-n;
    int k2 = m+n;

    printf("m:%d n:%d z1:%d z2:%d k1:%d k2:%d",m,n,z1,z2,k1,k2);

}