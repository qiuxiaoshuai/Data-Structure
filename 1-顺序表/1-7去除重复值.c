#include <stdio.h>
#include <stdlib.h> // Ϊ�� exit()
#define Maxsize 10

typedef struct {
    int data[Maxsize];
    int leng;
} List;

void printfList(List *L) {
    for(int i = 0; i < L->leng; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

void qcList(List *L){
    for(int i = 0;i<L->leng;i++){
        //�����j����,��Ϊ˳����ɾ�����ǴӺ�����λ��ǰ�棬���������µ����ʱ�����ܾͻ����©ɾ�������
        // [5, 5, 5, 6]
        //  ��  ��
        //  i  j
//         ɾ�� L->data[1]
// �����Ϊ�� [5, 5, 6]
//            ��     ��
//            i     j=2 (�Զ�++��)
        for(int j = i+1;j<L->leng;){
            if (L->data[i] == L->data[j]){
                for(int g = j;g<L->leng;g++){
                    L->data[g] = L->data[g+1];
                }
                L->leng--;
            }
            else{
                j++;
            }
        }
    }
    printfList(L);
}

int main(){
    List L = {{-3, 5, 1, 5, 5, 6}, 6};
    qcList(&L);
}