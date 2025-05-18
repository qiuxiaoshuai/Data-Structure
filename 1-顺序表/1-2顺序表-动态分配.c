#include <stdio.h>     // �����׼�������ͷ�ļ�
#include <stdlib.h>    // �����׼��ͷ�ļ������� malloc �� free ����

#define InitSize 10    // �����ʼ˳��������Ϊ10

// ����˳���ṹ��
typedef struct {
    int *data;         // ָ��̬�����ڴ��ָ�룬���ڴ洢����Ԫ��
    int MaxSize;       // ��ǰ˳�����������
    int length;        // ��ǰ˳���������Ԫ�صĸ���
} List;

// ��ʼ��˳���
void InitList(List *L) {
    L->data = (int *)malloc(InitSize * sizeof(int));  // ��̬�����ڴ棬��СΪInitSize��int
// 1. malloc(...) ����ʲô�ģ�
// malloc �� C ���������ڶ�̬�ڴ����ĺ��������� <stdlib.h>��
// ���������ǣ��ڶ��ڴ��п���һ��ָ����С���ڴ�ռ䡣
// �﷨Ϊ��void *malloc(size_t size);
// ��˼�ǣ����� size �ֽڵ��ڴ棬����һ�� void*��ͨ��ָ�룩��
// 2. InitSize * sizeof(int)
// ���Ǽ�����Ҫ��������ֽڵ��ڴ档
// InitSize �����Լ�����ĺ꣬������ 10��
// sizeof(int) ��ʾһ�� int ���ͱ�����ռ���ֽ�����ͨ���� 4 �ֽڣ�����ȡ����ϵͳ����
// ���� InitSize * sizeof(int) ���ǣ����� 10 �� int ���͵Ŀռ䣬Ҳ���� 10 * 4 = 40 �ֽڡ�
// 3. (int *) ��ʲô��˼��
// malloc ���ص��� void* ���͵�ָ�룬��������Ҫ���� int* ���ͣ���Ϊ data �� int*��������Ҫ����ǿ������ת����
// Ҳ����˵���ѷ��ص� void* ת�� int*����ֵ�� L->data��
    L->length = 0;                                     // ��ʼ��ʱ˳�����Ϊ0
    L->MaxSize = InitSize;                             // ����˳�����������
}

// ����˳�������
void IncreaseSize(List *L, int len) {
    int *p = L->data;                                        // ����ԭʼ�ڴ��ַ
    L->data = (int *)malloc((L->MaxSize + len) * sizeof(int)); // ���·�������������ڴ�
    for (int i = 0; i < L->length; i++) {                    // ��ԭ�����е����ݸ��Ƶ���������
        L->data[i] = p[i];
    }
    L->MaxSize = L->MaxSize + len;                          // �����������
    free(p);                                                // �ͷ�ԭ�����ڴ棬�����ڴ�й©
}

int main() {
    List L;               // ����һ��˳������L
    InitList(&L);         // ��ʼ��˳���
    IncreaseSize(&L, 5);  // ��˳���������չ5����λ

    free(L.data);         // �������ǰ�ͷŶ�̬������ڴ�
    return 0;             // ������������
}
