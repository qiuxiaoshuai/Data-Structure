#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000  // ����������鳤��

// ��������������ȼ�
int precedence(char op) {
    if(op == '+' || op == '-') return 1;  // �Ӽ����ȼ���
    if(op == '*' || op == '/') return 2;  // �˳����ȼ���
    return 0;
}

// �ж��Ƿ��������
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// ����׺���ʽת��Ϊ��׺���ʽ���沨�����ʽ��
// ������infix Ϊ�������׺���ʽ��postfix Ϊ����ĺ�׺���ʽ
void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX];  // ջ���ڴ�������
    int top = -1;     // ջ��ָ��
    int j = 0;        // ��׺���ʽ�±�

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // ��������֣������λ��
        if (isdigit(c)) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];  // ���������ַ�
            }
            postfix[j++] = ' ';  // ���ֺ�ӿո�ָ�
            i--;  // ����һ���ַ�����Ϊѭ�������1
        } 
        else if (c == '(') {
            stack[++top] = c;  // ������ѹջ
        } 
        else if (c == ')') {
            // ���������ţ�����ֱ������������
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            if (top >= 0 && stack[top] == '(') top--;  // ����������
        } 
        else if (isOperator(c)) {
            // ������������������ȼ����������������
            while (top >= 0 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            stack[++top] = c;  // ��ǰ�������ջ
        }
    }

    // ����ʣ��ջ�������
    while (top >= 0) {
        postfix[j++] = stack[top--];
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';  // �ַ���������
}

// �����׺���ʽ��ֵ
// ������postfix Ϊ����ĺ�׺���ʽ
// ���أ���������int��
int evaluatePostfix(char* postfix) {
    int stack[MAX];  // ������ʵ��ջ
    int top = -1;    // ջ��ָ��
    int i = 0;

    while (postfix[i] != '\0') {
        // ��������֣���ȡ�������ֲ���ջ
        if (isdigit(postfix[i])) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i++] - '0');  // �ַ�ת����
            }
            stack[++top] = num;
            printf("��ջ: %d\t��ǰջ: ", num);
            for (int k = 0; k <= top; k++) printf("%d ", stack[k]);
            printf("\n");
        } 
        // �����������������������������������ջ
        else if (isOperator(postfix[i])) {
            int b = stack[top--];  // �Ҳ�����
            int a = stack[top--];  // �������
            int res = 0;
            switch (postfix[i]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            stack[++top] = res;
            printf("����: %d %c %d = %d\t��ǰջ: ", a, postfix[i], b, res);
            for (int k = 0; k <= top; k++) printf("%d ", stack[k]);
            printf("\n");
            i++;  // �ƶ�����һ���ַ�
        } 
        else if (postfix[i] == ' ') {
            i++;  // �ո�����
        } 
        else {
            i++;  // ���������ַ�
        }
    }

    return stack[top];  // ���ս����ջ��
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("��������׺���ʽ���� (12+3)*2 ����");
    fgets(infix, sizeof(infix), stdin);           // ��ȡ�û�����
    infix[strcspn(infix, "\n")] = '\0';           // �Ƴ����з�

    infixToPostfix(infix, postfix);               // ��׺ת��׺
    printf("��׺���ʽ��%s\n", postfix);          // �����׺���ʽ

    int result = evaluatePostfix(postfix);        // �����׺���ʽ
    printf("���ս����%d\n", result);             // ������

    return 0;
}
