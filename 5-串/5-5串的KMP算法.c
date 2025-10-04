#include <stdio.h>
#include <string.h>

typedef struct {
    char data[255];
    int lenght;
} SString;

// ��ӡ�ַ���
void PrintfString(SString str) {
    for (int i = 0; i < str.lenght; i++) {
        printf("%c", str.data[i]);
    }
    printf("\n");
}

// ���� next ����
void Next(SString pattern, int next[]) {
    int i = 0;       // ��ǰ����next��ģʽ��λ��
    int k = -1;      // ����ǰ������ǰ׺�����׺���ȵ��±꣨-1�����ޣ�
    next[0] = -1;    // Լ����ʼ

    while (i < pattern.lenght - 1) {
        // ���k==-1����ʾ��û�ҵ����ʵ�ǰ׺������pattern[i] == pattern[k]��������չ�����ǰ��׺
        if (k == -1 || pattern.data[i] == pattern.data[k]) {
            i++;   // ������һ��λ�õ�next
            k++;   // ��չƥ��������ǰ��׺����
            next[i] = k;
        } else {
            // ��ƥ��ʱ��k���˵���һ�������ǰ��׺��λ��
            k = next[k];
        }
    }
}


// KMP ������������ƥ�䵽��λ��(��0��ʼ)���Ҳ�������-1
int KMP(SString text, SString pattern) {
    int i = 0; // text����
    int j = 0; // pattern����

    int next[255];
    Next(pattern, next);

    while (i < text.lenght && j < pattern.lenght) {
        if (j == -1 || text.data[i] == pattern.data[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }

    if (j == pattern.lenght) {
        return i - j; // ����ƥ�����ʼ�±�
    } else {
        return -1; // δƥ��ɹ�
    }
}

int main() {
    SString text = { .data = "Hadoop Java C++", .lenght = (int)strlen("Hadoop Java C++") };
    SString pattern = { .data = "Java", .lenght = (int)strlen("Java") };

    printf("�ı���: ");
    PrintfString(text);
    printf("ģʽ��: ");
    PrintfString(pattern);

    int pos = KMP(text, pattern);
    if (pos != -1) {
        printf("ƥ��ɹ���λ��: %d\n", pos);
    } else {
        printf("δ�ҵ�ƥ��\n");
    }

    return 0;
}
