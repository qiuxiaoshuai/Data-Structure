#include <stdio.h>

void fun_tree(int x, int depth, int is_last) {
    // ��ӡ�����ͷ�֧����
    for(int i = 0; i < depth - 1; i++) {
        printf("��   ");
    }
    if(depth > 0) {
        if(is_last)
            printf("������");
        else
            printf("������");
    }

    // ��ӡ��ǰ�ڵ�
    printf("fun(%d)\n", x);

    if(x == 0 || x == 1) {
        for(int i = 0; i < depth; i++) {
            printf("    ");
        }
        printf("return 1\n");
    } else {
        // �ݹ����
        fun_tree(x - 1, depth + 1, 1);
        for(int i = 0; i < depth; i++) {
            printf("    ");
        }
        printf("return %d * fun(%d) = %d\n", x, x - 1, x * 1); // ���շ���ֵ�������ñ����棬��ʱ��ʾ���㹫ʽ
    }
}

int f(int x) {
    static int depth = 0;  // �þ�̬����׷�ٵݹ����
    for (int i = 0; i < depth; i++) {
        printf("��   ");  // ��ӡÿһ�������
    }
    printf("fun(%d)\n", x);

    // �������
    if (x > 0) {
        depth++;  // �ݹ�ǰ�������
        int result = x * f(x - 1);  // �ݹ����
        depth--;  // ����ʱ�������
        for (int i = 0; i < depth; i++) {
            printf("��   ");  // ��ӡÿһ�������
        }
        printf("return %d * fun(%d) = %d\n", x, x - 1, result);  // ��ӡ����ֵ
        return result;
    } else {
        // �������
        for (int i = 0; i < depth; i++) {
            printf("��   ");  // ��ӡÿһ�������
        }
        printf("return 2\n");  // ��������ֵ
        return 2;
    }
}


int main() {
    int n = 4;
    fun_tree(n, 0, 1);
    printf("%d",f(f(1)));
}
