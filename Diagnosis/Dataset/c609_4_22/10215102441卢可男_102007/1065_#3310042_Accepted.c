#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
double expr()
{
    char a[10]={0};
    double f1,f2;
    scanf("%s",a);
    switch(a[0])
    {
        case '+':{f1=expr();f2=expr();return f1+f2;}
        case '-':{f1=expr();f2=expr();return f1-f2;}
        case '*':{f1=expr();f2=expr();return f1*f2;}
        case '/':{f1=expr();f2=expr();return f1/f2;}
        default :return atof(a);
    }
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
       double res;
       res=expr();
       printf("case #%d:\n%f\n",i,res);
    }
    return 0;
}
