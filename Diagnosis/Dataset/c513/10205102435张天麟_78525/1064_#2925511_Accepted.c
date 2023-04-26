#include<stdio.h>
#include<stdlib.h>
double expr()
{
    char a[10];
    double f1,f2;
    scanf("%s",a);
    switch(a[0])
    {
        case'+':
        {
            f1=expr();
            f2=expr();
            return f1+f2;
        }
        case'-':
        {
            f1=expr();
            f2=expr();
            return f1-f2;
        }
        case'*':
        {
            f1=expr();
            f2=expr();
            return f1*f2;
        }
        case'/':
        {
            f1=expr();
            f2=expr();
            return f1/f2;
        }
        default:return atof(a);
    }
}
int main()
{
    int T,n;
    double ans;
    scanf("%d",&T);
    for(n=0;n<T;n++)
    {
        ans=expr();
        printf("case #%d:\n%6f\n",n,ans);
    }
    return 0;
}