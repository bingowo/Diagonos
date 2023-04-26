#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
double expr(){ //波兰式函数体，返回值为double
char a[10]; //定义准备读入的字符串
double f1, f2; //定义2个双精度数，用于保存递归结果
scanf("%s", a); //读入字符串
switch(a[0]){ //如为算符，处理其后的波兰式并计算
case'+': {f1= expr( ); f2 = expr( ); return f1 + f2;}
case'-': {f1= expr( ); f2 = expr( ); return f1 - f2;}
case'*': {f1= expr( ); f2 = expr( ); return f1 * f2;}
case'/': {f1= expr( ); f2 = expr( ); return f1 / f2;}
default: return atof(a); //不是算符就转换为双精度数
}
}
int main()
{
    int T;
    int i;
    double res=0
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        res=expr();
        printf("case #%d:\n",i);
        printf("%lf\n",res);
    }
}