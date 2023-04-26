#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double PM()
{
    char a[10];
    double f1,f2;
    scanf("%s",a);
    switch (a[0])
    {
        case'+':{f1=PM();f2=PM();return f1+f2;}
        case'-':{f1=PM();f2=PM();return f1-f2;}
        case'*':{f1=PM();f2=PM();return f1*f2;}
        case'/':{f1=PM();f2=PM();return f1/f2;}
        default: return atof(a);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        double result=PM();
        printf("%lf\n",result);

    }


    return 0;
}
