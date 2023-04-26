#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double expr()
{
    char a[10];
    scanf("%s",a);
    double f1,f2;
    switch(a[0])
    {
        case '+':{f1=expr();f2=expr();return f1+f2;}
        case '-':{f1=expr();f2=expr();return f1-f2;}
        case '*':{f1=expr();f2=expr();return f1*f2;}
        case '/':{f1=expr();f2=expr();return f1/f2;}
        default: return atof(a);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        double ret=expr();
        printf("case #%d:\n",i);
        printf("%f\n",ret);
    }
    return 0;
}

