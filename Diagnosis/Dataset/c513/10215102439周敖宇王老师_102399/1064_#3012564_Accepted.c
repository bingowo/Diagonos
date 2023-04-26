#include<stdio.h>
#include<string.h>
#include<stdlib.h>
double f()
{
    char s[200];
    double a,b;
    scanf("%s",s);
    switch (s[0])
    {
        case '+':{a=f();b=f();return a+b;}
        case '-':{a=f();b=f();return a-b;}
        case '*':{a=f();b=f();return a*b;}
        case '/':{a=f();b=f();return a/b;}
        default:return atof(s);
    }
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n%.6f\n",i,f());
    }
    return 0;
}