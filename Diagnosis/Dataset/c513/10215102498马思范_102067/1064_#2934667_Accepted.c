#include <stdio.h>
#include <string.h>
#include <stdlib.h>
double polish()
{
    char a[11];
    double f1,f2;
    scanf("%s",a);
    switch (a[0])
    {
        case '+':f1=polish();f2=polish();return f1+f2;
        case '-':f1=polish();f2=polish();return f1-f2;
        case '*':f1=polish();f2=polish();return f1*f2;
        case '/':f1=polish();f2=polish();return f1/f2;
        default: return atof(a);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    double p;
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        p=polish();
        printf("%f\n",p);
    }
}