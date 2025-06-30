#include <stdio.h>
#include <stdlib.h>

typedef struct Sq {
    char data[100];
    int top;
} Sq;

// ��ʼ��ջ
void Init(Sq *s) {
    s->top = -1;
}

// ��ջ
int Push(Sq *s, char x) {
    if (s->top == 99) return -1;
    s->data[++s->top] = x;
    return 1;
}

// ��ջ
int Pop(Sq *s, char *x) {
    if (s->top == -1) return -1;
    *x = s->data[s->top--];
    return 1;
}

// �ж������Ƿ�ƥ��
int IFpd(Sq *s, char add[], int len) {
    char x;
    for (int i = 0; i < len; i++) {
        if (add[i] == '(' || add[i] == '[' || add[i] == '{') {
            Push(s, add[i]);
        } else if (add[i] == ')' || add[i] == ']' || add[i] == '}') {
            if (Pop(s, &x) == -1) {
                return 0; // ����������
            }
            if ((add[i] == ')' && x != '(') ||
                (add[i] == ']' && x != '[') ||
                (add[i] == '}' && x != '{')) {
                return 0; // �������Ͳ�ƥ��
            }
        }
    }
    // �ж��Ƿ�ջ�л���ʣ��δƥ���������
    return s->top == -1 ? 1 : 0;
}

int main() {
    Sq s;
    Init(&s);
    char arr[] = {'{', '{', '(', ')', ')', '[', ']', '}'};
    int result = IFpd(&s, arr, sizeof(arr) / sizeof(arr[0]));
    printf("%s\n", result ? "ƥ��ɹ�" : "��ƥ��");
    return 0;
}
