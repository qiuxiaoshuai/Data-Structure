#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ˳�򴮽ṹ����
typedef struct {
    char ch[100]; // �ַ����飬��ʹ�� \0���ֶ�������
    int length;   // ʵ���ַ�������
} SString;

// ��ӡ�ַ�������
void PrintSString(SString s) {
    for (int i = 0; i < s.length; i++) {
        putchar(s.ch[i]);
    }
    printf("\n");
}

// �Ӵ���ȡ�������� S �е� pos ��λ�ã�0 ��ʼ������ȡ len ���ַ��� str
int Substring(SString *str, SString S, int pos, int len) {
    if (pos < 0 || pos + len > S.length) {
        return 0; // Խ����
    }

    for (int i = 0; i < len; i++) {
        str->ch[i] = S.ch[pos + i];
    }
    str->length = len;
    return 1;
}

// �ַ����Ƚϣ����ص�һ��������ַ��Ĳ�ֵ���򳤶Ȳ�
int strbi(SString a, SString b) {
    int minLen = (a.length < b.length) ? a.length : b.length;
    for (int i = 0; i < minLen; i++) {
        if (a.ch[i] != b.ch[i]) {
            return a.ch[i] - b.ch[i];
        }
    }
    return a.length - b.length;
}

// �ַ�����λ���� S �в����Ӵ� b������ b �� S �е�һ�γ��ֵ�λ�ã��� 0 ��ʼ��
// ��δ�ҵ������� -1
int Index(SString S, SString b) {
    int n = S.length;
    int m = b.length;
    SString sub;

    for (int i = 0; i <= n - m; i++) {
        if (Substring(&sub, S, i, m)) {
            if (strbi(sub, b) == 0) {
                return i; // �ҵ�������λ��
            }
        }
    }
    return -1; // δ�ҵ�
}

int main() {
    SString s = { .ch = "HelloWorld", .length = 10 };
    SString sub;
    SString b = { .ch = "ll", .length = 2 };

    // �Ӵ���ȡ��ʾ
    if (Substring(&sub, s, 2, 4)) {  // Ӧ��� lloW
        printf("��ȡ���Ӵ�Ϊ��");
        PrintSString(sub);
    } else {
        printf("�Ӵ���ȡʧ�ܣ�Խ�磩\n");
    }

    // �ַ����Ƚ���ʾ
    printf("�ַ����ȽϽ����%d\n", strbi(s, b));  // s �� b �Ĳ�ֵ

    // �ַ�����λ��ʾ
    int pos = Index(s, b);
    if (pos != -1) {
        printf("�Ӵ� \"%.*s\" �������е�һ�γ��ֵ�λ���ǣ�%d\n", b.length, b.ch, pos);
    } else {
        printf("δ�ҵ����Ӵ���\n");
    }

    return 0;
}
