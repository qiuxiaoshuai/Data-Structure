#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ??¨²???????????¦Ë???
void print_bits(void *ptr, size_t size) {
    unsigned char *bytes = (unsigned char *)ptr;
    for (int i = size - 1; i >= 0; i--) {       // ?????????????????
        for (int j = 7; j >= 0; j--) {
            printf("%d", (bytes[i] >> j) & 1);
        }
        printf(" "); // ?????????
    }
    printf("\n");
}

void add(){
    int si = 65536;
    short i = si;
    unsigned j = 0;
    if(i<j-1) {
            printf("????\n"); 
            print_bits(&si,sizeof(si));
            print_bits(&i,sizeof(i));
            print_bits(&j,sizeof(j));
    }
    else {
        printf("?????");
    }
}

void add_1(){
    int i = 32777;
    short si = i;
    int j = si;
    printf("%d\n",j);
    print_bits(&j,sizeof(j));
    printf("%d\n",si);
    print_bits(&si,sizeof(si));
}

void add_2(){
    int x,y,z;
    double dx = (double)x;
    double dy = (double)y;
    double dz = (double)z;
    if(dx+dy == (double)(x+y)) printf("dx+dy\n",dx+dy);   
    if(dx*dx >=0) printf("dx*dx\n",dx*dx);  
    if(dx/dx == dy/dy) printf("dx/dx == dy/dy\n",dx/dx);  
    if((dx + dy)+dz == dx+(dy+dz)) printf("(dx + dy)+dz\n",(dx + dy)+dz);  
}

void add_3(){
    static short b[2][4] = {
        {2,9,-1,5},
        {3,1,-6,2}
    };
    printf("%p\n",(void*)b);
    struct cont{
        char id;
        unsigned post;
        char phone;
    }x;
    printf("A:%p\nB:%p",&x,&x.phone);
}

int add_4(){
    int a[3][4] = {
        {1,2,3,4},
        {10,20,30,40},
        {100,200,300,400}
    };
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int main(){
    add_4();
}