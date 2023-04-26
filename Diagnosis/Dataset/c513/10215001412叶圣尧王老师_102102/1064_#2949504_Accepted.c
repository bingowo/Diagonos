#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

double expr()
{
    char a[10];
    double f1,f2;
    scanf("%s",a);
    switch(a[0])
    {
        case'+':{f1=expr();f2=expr();return f1+f2;}
        case'-':{f1=expr();f2=expr();return f1-f2;}
        case'*':{f1=expr();f2=expr();return f1*f2;}
        case'/':{f1=expr();f2=expr();return f1/f2;}
        default:return atof(a);
    }
}

int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        printf("%f\n",expr());
    }
}