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

int main() {
    int n = 4;
    fun_tree(n, 0, 1);
    return 0;
}
