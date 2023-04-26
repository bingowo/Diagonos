#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
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
{   int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("case #%d:\n",i);
    printf("%.6lf\n",p());
    }
    return 0;
}