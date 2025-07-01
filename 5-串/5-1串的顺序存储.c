#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
    char ch[100]; //ÿ�������洢һ����Ԫ
    int length;  //���ĳ���
}SString;

typedef struct {
    char *ch;  //��̬����
    int length;
}Hstring;

//��ʼ��
void INitHsting(Hstring *str){
    str->ch=NULL;
    str->length=0;
}

//��ֵ
void AssHstr(Hstring *str,const char *chars){
    int len = strlen(chars);

    if(str->ch){
        free(str->ch);
    }

    str->ch = (char *)malloc((len + 1) * sizeof(char));
    if(!str->ch){
        printf("�ڳ�����ʧ��!\n");
        exit(1);
    }
    strcpy(str->ch,chars);
    str->length = len;
}

//����
void DelHstr(Hstring *str){
    if(str->ch){
        free(str->ch);
        str->ch = NULL;
    }
    str->length = 0;
}

void prinSstr(SString s){
    for(int i=0;i<s.length;i++){
        putchar(s.ch[i]);
    }
    printf("\n");
}

void prinHstr(Hstring str){
    if(str.ch){
        printf("%s\n",str.ch);
    }
}

//���ִ�
int Substring(SString *str,SString S,int pos,int len){
    if (pos + len-1 > S.length){
        return 0;
    }
    for(int i=pos;i<pos+len;i++){
        str->ch[i-pos] = S.ch[i];
    }
    str->length = len;
    return 1;
}

int main() {
    // ��ʼ��һ�������� SString
    SString s = { .ch = "Hello", .length = 5 };
    SString b;
    printf("SString ����: ");
    prinSstr(s);  // ��ӡ SString ����

    // ��ʼ��һ����̬�� HString
    Hstring h;
    INitHsting(&h);               // ��ʼ�� h ָ��Ϊ��
    AssHstr(&h, "World");    // ��ֵ�ַ��� "World"
    printf("HString ����: ");
    prinHstr(h);               // ��ӡ HString ����
    DelHstr(&h);            // ���ٶ�̬�����ͷ��ڴ�
    // �����Ӵ���ȡ���ܣ��� s ��λ�� 1 ��ʼȡ 2 ���ַ�
    if (Substring(&b, s, 1, 3)) {
        printf("�Ӵ����: ");
        prinSstr(b);  // Ӧ��� "el"
    } else {
        printf("�Ӵ���ȡʧ�ܣ�\n");
    }
}
