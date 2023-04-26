#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
double expr()
{ //波兰式函数体，返回值为double
    char a[10]; //定义准备读入的字符串
    double f1, f2;
    scanf("%s", a); //读入字符串
    if(a[0]=='+')
    {
        f1=expr();
        f2=expr();
        return f1+f2;
    }
    else if(a[0]=='-')
    {
        f1=expr();
        f2=expr();
        return f1-f2;
    }
    else if(a[0]=='*')
    {
        f1=expr();
        f2=expr();
        return f1*f2;
    }
    else if(a[0]=='/')
    {
        f1=expr();
        f2=expr();
        return f1/f2;
    }
    else
    {
        return atof(a);
    }
}
int main()
{
    int T;
    int i;
    double res=0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        res=expr();
        printf("case #%d:\n",i);
        printf("%lf\n",res);
    }
}