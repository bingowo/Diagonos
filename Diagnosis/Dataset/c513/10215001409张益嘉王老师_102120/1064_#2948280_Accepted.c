#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double expr()
{
    char a[12];
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
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        double re=expr();
        printf("case #%d:\n",i);
        printf("%.6f\n",re);

    }
    return 0;
}
