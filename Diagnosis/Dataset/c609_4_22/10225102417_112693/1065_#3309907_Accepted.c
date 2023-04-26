#include <stdio.h>
#include <stdlib.h>

double p()
{
    char a[11];
    double f1,f2;
    scanf("%s",a);
    switch(a[0])
    {
        case'+':f1=p();f2=p();return f1+f2;
        case'-':f1=p();f2=p();return f1-f2;
        case'*':f1=p();f2=p();return f1*f2;
        case'/':f1=p();f2=p();return f1/f2;
        default:return atof(a);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n""%f\n",i,p());
    }
    return 0;
}
