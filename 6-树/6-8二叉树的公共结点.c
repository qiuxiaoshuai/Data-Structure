#include <stdio.h>

// ������˳��洢���㷨�� LCA
// tree �Ƕ�������˳��洢���飬n �����Ľ����
int findLCA(int tree[], int n, int i, int j) {
    // ��� i �� j �������ķ�Χ��ֱ�ӷ��� -1
    if (i < 1 || i > n || j < 1 || j > n) {
        printf("�ڵ��ų�����Χ\n");
        return -1;
    }

    // �� i �� j ��ʼ���ϲ��ң�ֱ���ҵ���������
    while (i != j) {
        // ��� i �ڵ�ı�Ŵ��� j �ڵ�ı�ţ�i �����ƶ������ڵ�
        if (i > j) {
            i = i / 2;  // i �ĸ��ڵ�
        }
        // ��� j �ڵ�ı�Ŵ��� i �ڵ�ı�ţ�j �����ƶ������ڵ�
        else {
            j = j / 2;  // j �ĸ��ڵ�
        }
    }

    return i;  // �ҵ��� i �� j ��ͬ��Ϊ�����������
}

int add(int A[],int i,int j){
    while(i!=j){
        if(i>j){
            i = i / 2;
        }else{
            j = j / 2;
        }
    }
    return i;
}

int main() {
    int tree[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};  // ˳��洢�Ķ����� (1-12)
    int n = 12;  // �������Ľڵ���
    
    int i = 8;   // �ڵ� i
    int j = 9;   // �ڵ� j

    int lca = findLCA(tree, n, i, j);  // ���� i �� j �������������
    printf("�ڵ� %d �� �ڵ� %d ���������������: %d\n", i, j, lca);
    int ca = add(tree, i, j);  // ���� i �� j �������������
    printf("�ڵ� %d �� �ڵ� %d ���������������: %d\n", i, j, ca);
    return 0;
}
