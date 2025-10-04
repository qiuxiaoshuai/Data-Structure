#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // ���� malloc �� free ����

// ��ģʽ���� next ����
void computeNext(char *pattern, int *next) {
    int m = strlen(pattern);
    next[0] = 0; // next[0] = 0, ��Ϊû��ǰ׺�ͺ�׺

    int j = 0; // ǰ׺����
    for (int i = 1; i < m; i++) {
        // ����ģʽ������һ���ַ�
        while (j > 0 && pattern[i] != pattern[j]) {
            // �����ƥ�䣬�����
            j = next[j - 1];
        }
        
        if (pattern[i] == pattern[j]) {
            // ƥ��ɹ���ǰ׺���ȼ� 1
            j++;
        }
        
        next[i] = j; // ���� next �����ֵ
    }
}

void printNext(int *next, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", next[i]);
    }
    printf("\n");
}

int main() {
    char pattern[255];
    printf("������ģʽ��: ");
    scanf("%s", pattern);

    int m = strlen(pattern);
    int *next = (int *)malloc(m * sizeof(int)); // ��̬�����ڴ�
    if (next == NULL) {
        printf("�ڴ����ʧ��\n");
        return -1;
    }

    computeNext(pattern, next);

    printf("Next ����Ϊ��\n");
    printNext(next, m);

    free(next); // �ͷ��ڴ�
    return 0;
}
