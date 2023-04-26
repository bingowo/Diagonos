#include <stdio.h>
#include <stdlib.h>

double expr()
{
    char a[10];
    double f1,f2;
    scanf("%s",a);
    switch(a[0])
    {
        case '+':
        {
            f1=expr();
            f2=expr();
            return f1+f2;
        }
        case '-':
        {
            f1=expr();
            f2=expr();
            return f1-f2;
        }
        case '*':
        {
            f1=expr();
            f2=expr();
            return f1*f2;
        }
        case '/':
        {
            f1=expr();
            f2=expr();
            return f1/f2;
        }
        default: return atof(a);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        double s;
        s=expr();
        printf("case #i:\n",i);
        printf("%lf\n",s);
    }
    return 0;
}
