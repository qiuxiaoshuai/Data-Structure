#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
    char ch[100]; //每个分量存储一个单元
    int length;  //串的长度
}SString;

typedef struct {
    char *ch;  //动态分配
    int length;
}Hstring;

//初始化
void INitHsting(Hstring *str){
    str->ch=NULL;
    str->length=0;
}

//赋值
void AssHstr(Hstring *str,const char *chars){
    int len = strlen(chars);

    if(str->ch){
        free(str->ch);
    }

    str->ch = (char *)malloc((len + 1) * sizeof(char));
    if(!str->ch){
        printf("内车分配失败!\n");
        exit(1);
    }
    strcpy(str->ch,chars);
    str->length = len;
}

//销毁
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

//求字串
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
    // 初始化一个定长串 SString
    SString s = { .ch = "Hello", .length = 5 };
    SString b;
    printf("SString 内容: ");
    prinSstr(s);  // 打印 SString 内容

    // 初始化一个动态串 HString
    Hstring h;
    INitHsting(&h);               // 初始化 h 指针为空
    AssHstr(&h, "World");    // 赋值字符串 "World"
    printf("HString 内容: ");
    prinHstr(h);               // 打印 HString 内容
    DelHstr(&h);            // 销毁动态串，释放内存
    // 测试子串提取功能，从 s 的位置 1 开始取 2 个字符
    if (Substring(&b, s, 1, 3)) {
        printf("子串结果: ");
        prinSstr(b);  // 应输出 "el"
    } else {
        printf("子串提取失败！\n");
    }
}
