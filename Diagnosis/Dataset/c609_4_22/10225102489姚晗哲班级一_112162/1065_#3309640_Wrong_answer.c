#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 100

typedef struct {
    double data[MAXSIZE];
    int top;
} Stack;//定义结构体

// 入栈
void push(Stack *S, double x) {
    S->data[++(S->top)] = x;
}

// 出栈
double pop(Stack *S) {
    return S->data[(S->top)--];
}

// 判断是否为运算符
int isOperator(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

// 计算二元操作
double calc(double a, double b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("case #%d: ", t);  // 输出问题编号
        char str[MAXSIZE];
        scanf("%s", str);
        int len = strlen(str);
        Stack S;
        S.top = -1;
        // 从右往左扫描表达式
        for (int i = len - 1; i >= 0; i--) {
            if (isOperator(str[i])) {  // 如果是运算符，弹出栈顶的两个数进行计算，并将结果入栈
                double a = pop(&S);
                double b = pop(&S);
                double res = calc(a, b, str[i]);
                push(&S, res);
            } else if (isdigit(str[i])) {  // 如果是数字，将其转换成浮点数并入栈
                double num = 0;
                double base = 1.0;
                while (i >= 0 && isdigit(str[i])) {
                    num += (str[i] - '0') * base;
                    base *= 10;
                    i--;
                }
                push(&S, num);
                i++;
            }
        }
        printf("%.6f\n", S.data[S.top]);  // 输出表达式的值
    }
    return 0;
}