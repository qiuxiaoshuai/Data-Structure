#include <stdio.h>
#include <stdlib.h>

typedef struct Sq {
    char data[100];
    int top;
} Sq;

// ≥ı ºªØ’ª
void Init(Sq *s) {
    s->top = -1;
}

// »Î’ª
int Push(Sq *s, char x) {
    if (s->top == 99) return -1;
    s->data[++s->top] = x;
    return 1;
}

// ≥ˆ’ª
int Pop(Sq *s, char *x) {
    if (s->top == -1) return -1;
    *x = s->data[s->top--];
    return 1;
}

// ≈–∂œ¿®∫≈ «∑Ò∆•≈‰
int IFpd(Sq *s, char add[], int len) {
    char x;
    for (int i = 0; i < len; i++) {
        if (add[i] == '(' || add[i] == '[' || add[i] == '{') {
            Push(s, add[i]);
        } else if (add[i] == ')' || add[i] == ']' || add[i] == '}') {
            if (Pop(s, &x) == -1) {
                return 0; // ∂‡¡À”“¿®∫≈
            }
            if ((add[i] == ')' && x != '(') ||
                (add[i] == ']' && x != '[') ||
                (add[i] == '}' && x != '{')) {
                return 0; // ¿®∫≈¿‡–Õ≤ª∆•≈‰
            }
        }
    }
    // ≈–∂œ «∑Ò’ª÷–ªπ”– £”‡Œ¥∆•≈‰µƒ◊Û¿®∫≈
    return s->top == -1 ? 1 : 0;
}

int main() {
    Sq s;
    Init(&s);
    char arr[] = {'{', '{', '(', ')', ')', '[', ']', '}'};
    int result = IFpd(&s, arr, sizeof(arr) / sizeof(arr[0]));
    printf("%s\n", result ? "∆•≈‰≥…π¶" : "≤ª∆•≈‰");
    return 0;
}
