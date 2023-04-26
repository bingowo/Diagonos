#include <stdio.h>
#include <stdlib.h>

double expr()
{
    char a[10];
    double f1, f2;
    scanf("%s", a);
    switch(a[0]){
        case '+': {f1 = expr(); f2 = expr(); return f1 + f2;}  //若为计算符则按相应运算进行计算
        case '-': {f1 = expr(); f2 = expr(); return f1 - f2;}
        case '*': {f1 = expr(); f2 = expr(); return f1 * f2;}
        case '/': {f1 = expr(); f2 = expr(); return f1 / f2;}
        default: return atof(a);  //不是运算符则转换为double类型
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t ++){
        printf("case #%d:\n%f\n", t, expr());
    }
    return 0;
}