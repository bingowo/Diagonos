#include <stdio.h>
#include <stdlib.h>
double ans()
{
    char s[10];
    scanf("%s",s);
    double f1,f2;
    switch(s[0])
    {
        case'+':
            {
                f1=ans();f2=ans();return f1+f2;
            }
        case'-':
            {
                f1=ans();f2=ans();return f1-f2;
            }
        case'*':
            {
                f1=ans();f2=ans();return f1*f2;
            }
        case'/':
            {
                f1=ans();f2=ans();return f1/f2;
            }
        default: return atof(s);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n%lf\n",i,ans());
    }
}
