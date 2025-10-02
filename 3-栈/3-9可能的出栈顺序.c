#include <stdio.h>
#include <stdlib.h>

#define MAXN 20

int n;
int input[MAXN];      // ��ջ˳��
int stack[MAXN];      // ģ��ջ
int top = -1;
int output[MAXN];     // ��ǰ��ջ����
int count = 0;        // ͳ�Ʒ�����

// ���ݺ���
void dfs(int inIndex, int outIndex) {
    // �������Ԫ�ض���ջ������ջΪ��
    if (inIndex == n && top == -1) {
        count++;
        printf("���� %d: ", count);
        for (int i = 0; i < n; i++) {
            printf("%d ", output[i]);
        }
        printf("\n");
        return;
    }

    // ѡ����ջ���������Ԫ��δ��ջ��
    if (inIndex < n) {
        stack[++top] = input[inIndex];     // ��ջ
        dfs(inIndex + 1, outIndex);
        top--;                             // ���ݣ�������ջ��
    }

    // ѡ�񣺳�ջ�����ջ��Ϊ�գ�
    if (top >= 0) {
        int temp = stack[top--];          // ��ջ
        output[outIndex] = temp;
        dfs(inIndex, outIndex + 1);
        stack[++top] = temp;              // ���ݣ�������ջ��
    }
}
int main() {
    printf("������Ԫ�ظ��� n: ");
    scanf("%d", &n);

    printf("������ %d ��Ԫ�ص���ջ˳��:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }

    dfs(0, 0);

    printf("�ܹ��� %d �ֳ�ջ˳��\n", count);
    return 0;
}
