#include<stdio.h>
#include<stdlib.h>

int bll(int a,int b,int c){
    int max = c,min = a;
    if(b > c) max = b;
    if(a > c) max = a;
    if(b < a) min = b;
    if(c < a) min = c;
    return 2 * (max - min);
}

int all(int S1[],int n1,int S2[],int n2,int S3[],int n3){
    int q = 0,w = 0,e = 0;
    int num_a = S1[q],num_b = S2[w],num_c = S3[e];
    int D = bll(S1[q],S2[w],S3[e]);//?????
    while(q < n1 && w < n2 && e < n3){
        int cd = bll(S1[q],S2[w],S3[e]);
        if(D>cd){
            D = cd;
            num_a = S1[q];
            num_b = S2[w];
            num_c = S3[e];
        }
        int min_num = num_a;
        if(num_b < min_num ) min_num = num_b;
        if(num_c < min_num) min_num = num_c;
        if(min_num == num_a){
            q++;
        }else if (min_num == num_b)
        {
            w++;
        }else{
            e++;
        }
    }
    printf("???????:%d,????????????(%d,%d,%d)",D,num_a,num_b,num_c);
}

int main(){
    int S1[] = {-1, 0, 9};
    int S2[] = {-25, -10, 10, 11};
    int S3[] = {2, 9, 17, 30, 41};

    int n1 = sizeof(S1) / sizeof(S1[0]);
    int n2 = sizeof(S2) / sizeof(S2[0]);
    int n3 = sizeof(S3) / sizeof(S3[0]);
    all(S1,n1,S2,n2,S3,n3);
}