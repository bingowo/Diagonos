#include <stdio.h>
#include <stdlib.h>

double expr()
{
    char a[101]={0};
    double f1,f2;
    scanf("%s",a);
    switch(a[0])
    {
        case '+':{f1=expr();f2=expr();return f1+f2;}
        case '-':{f1=expr();f2=expr();return f1-f2;}
        case '*':{f1=expr();f2=expr();return f1*f2;}
        case '/':{f1=expr();f2=expr();return f1/f2;}
        default:return atof(a);
    }
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        double res;
        res = expr();
        printf("case #%d:\n",i);
        printf("%lf\n",res);
    }
    return 0;
}
