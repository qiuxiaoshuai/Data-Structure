#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ��ģʽ���� nextval ����
void computeNextval(char *pattern, int *nextval) {
    int m = strlen(pattern);
    nextval[0] = -1;  // nextval[0] = -1, ��Ϊû��ǰ׺�ͺ�׺

    int j = -1;  // j �����ǰ��׺�ĳ���
    for (int i = 1; i < m; i++) {
        // ����ģʽ������һ���ַ�
        while (j >= 0 && pattern[i] != pattern[j + 1]) {
            j = nextval[j];  // �����ƥ�䣬�����
        }
        
        if (pattern[i] == pattern[j + 1]) {
            j++;  // ƥ��ɹ���ǰ׺���ȼ� 1
        }
        
        // �����ǰ�ַ�ƥ�䣬����һ���ַ���Ȼ�ظ��������ظ�����
        if (pattern[i] == pattern[j + 1]) {
            nextval[i] = nextval[j];
        } else {
            nextval[i] = j;
        }
    }
}

// ��ӡ nextval ����
void printNextval(int *nextval, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", nextval[i]);
    }
    printf("\n");
}

// ���㻬������
int calculateSlideDistance(int *nextval, int j) {
    if (nextval[j] == -1) {
        return 1;  // ��� nextval[j] == -1���򻬶�1��λ��
    } else {
        return j - nextval[j] + 1;  // ���򣬻����ľ����� j - nextval[j] + 1
    }
}

int main() {
    char pattern[255];
    printf("������ģʽ��: ");
    scanf("%s", pattern);

    int m = strlen(pattern);
    int *nextval = (int *)malloc(m * sizeof(int));  // ��̬�����ڴ�
    if (nextval == NULL) {
        printf("�ڴ����ʧ��\n");
        return -1;
    }

    computeNextval(pattern, nextval);

    printf("Nextval ����Ϊ��\n");
    printNextval(nextval, m);

    // �Զ�����ÿ��λ�õĻ�������
    printf("ģʽ��ÿ��λ�õĻ�������Ϊ��\n");
    for (int j = 0; j < m; j++) {
        int slideDistance = calculateSlideDistance(nextval, j);
        printf("��ǰλ�� %d ʱ�������ľ����ǣ�%d\n", j, slideDistance);
    }

    free(nextval);  // �ͷ��ڴ�
    return 0;
}
