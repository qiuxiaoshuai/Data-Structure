#include<stdio.h>
#define MaxSize 10

// typedef ��C������������������ؼ���
// ���������ǣ������ӵ����ͣ�����ṹ�壩��һ���򵥵ı���
// �������Ժ����ֱ��д sqList ���������ֽṹ�����ͣ�������Ҫÿ�ζ�д struct {...}

// struct������һ���ṹ��
typedef struct{
    int Data[MaxSize];
    int leng;
}sqList;

void InitList(sqList *L){
    for(int i = 0;i<MaxSize;i++){
        L->Data[i]=i;
    }
    L->leng=0;
}

// InitList �����Ĳ����� sqList *L ���� ����ָ��ṹ���ָ�롣
// main �����У�L ��һ����ͨ�ṹ�����������ָ�롣
// ���ԣ����ʽṹ���Ա�ķ�ʽ��ͬ��
// ���	           ���ʷ�ʽ	      ʾ��
// ��ͨ�ṹ�����	�� .	L.Data[i]
// �ṹ��ָ��	�� ->	L->Data[i]

// sqList L;    // ��ͨ����
// sqList *p;   // ָ��

// p = &L;      // pָ��L

// p->Data[0] �� (*p).Data[0] ��һ���£�-> �Ƕ� (*p).��Ա �ļ�д
int main(){
    sqList L;
    InitList(&L);
    for(int i = 0;i<MaxSize;i++){
        printf("%d",L.Data[i]);
    }
    printf("\n����Ϊ:%d",L.leng);
}