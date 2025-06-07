#include<stdio.h>
#include<stdlib.h>

// ��������ڵ�ṹ������ջ��ʵ��
typedef struct LinkNode {
    char data;           // ջ�д洢��Ԫ��
    struct LinkNode *next; // ָ����һ��ջԪ�ص�ָ��
} LinkNode, *LinkSrack;   // LinkSrack ��ջ��ָ�����ͣ�ָ�� LinkNode �ṹ��

// ��ʼ��ջ��ջ��ָ����Ϊ��
void Init(LinkSrack *top) {
    *top = NULL;  // ��ʼ��ջ��ָ��Ϊ NULL
}

// ��ջ��ѹ��һ��Ԫ��
void Push(LinkSrack *top, char x) {
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));  // �����µ�ջ�ڵ�
    s->data = x;          // ��Ԫ�ظ�ֵ��ջ�ڵ�
    s->next = *top;       // �½ڵ�� next ָ��ǰջ��
    *top = s;             // ����ջ��ָ��ָ���½ڵ�
}

// ��ջ�е���һ��Ԫ��
int Pop(LinkSrack *top, char *x) {
    if (*top == NULL) {  // �ж�ջ�Ƿ�Ϊ��
        printf("ջΪ��\n"); // ���Ϊ�գ���ӡ��ʾ��Ϣ
        return 0; // ����ʧ��
    }
    LinkNode *temp = *top;    // ��ʱ����ջ��Ԫ��
    *x = temp->data;          // ��ջ��Ԫ�ص�ֵ���� x
    *top = temp->next;        // ����ջ��ָ�룬ָ����һ��Ԫ��
    free(temp);               // �ͷ�ԭջ���ڵ���ڴ�
    return 1;                 // ���سɹ�
}

// �������ַ����е������Ƿ�ƥ��
// add[] �������ַ����飬leng �����鳤��
int IFStack(char add[], int leng) {
    LinkSrack s;
    Init(&s);  // ��ʼ��ջ

    // �����ַ����е�ÿ���ַ�
    for (int i = 0; i < leng; i++) {
        // ����ǿ����ţ�����ѹ��ջ��
        if (add[i] == '(' || add[i] == '{' || add[i] == '[') {
            Push(&s, add[i]);
        } else { // ����Ǳ�����
            // ���ջΪ�գ�˵��û�ж�Ӧ�Ŀ����ţ����� 0 ��ʾƥ��ʧ��
            if (s == NULL) {
                return 0;
            }
            char topElem; // ���ڴ洢ջ��Ԫ��
            Pop(&s, &topElem); // ����ջ��Ԫ��
            // ��鵱ǰ�ı������Ƿ���ջ��Ԫ�صĿ�����ƥ��
            if ((add[i] == ')' && topElem != '(') ||
                (add[i] == ']' && topElem != '[') ||
                (add[i] == '}' && topElem != '{')) {
                return 0; // �����ƥ�䣬���� 0
            }
        }
    }

    // ���ջΪ�գ���ʾ�������Ŷ���ƥ��
    return 1;
}

int main() {
    char arr[] = {'{', '(', '(', ')', ')', '[', ']', '}'}; // ���Ե���������
    // ���� IFStack ��������������Ƿ�ƥ��
    printf("%d", IFStack(arr, sizeof(arr) / sizeof(arr[0])));  // ���ƥ������1 ��ʾƥ�䣬0 ��ʾ��ƥ��
}
