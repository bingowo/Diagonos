#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double polish()
{
    char a[11];
    double f1,f2;
    scanf("%s",a);
    if(a[0]=='+')
    {
        f1=polish();
        f2=polish();
        return f1+f2;
    }
    else if(a[0]=='-')
    {
        f1=polish();
        f2=polish();
        return f1-f2;
    }
    else if(a[0]=='*')
    {
        f1=polish();
        f2=polish();
        return f1*f2;
    }
    else if(a[0]=='/')
    {
        f1=polish();
        f2=polish();
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
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n%.6f\n",i,polish());
    }
    return 0;
}
