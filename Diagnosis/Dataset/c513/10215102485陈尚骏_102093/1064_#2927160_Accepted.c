#include <stdio.h>
#include <stdlib.h>
#include<string.h>

double poland()
{
    char a[11];
    double f1,f2;
    scanf("%s",a);
    switch(a[0])
    {
        case'+':f1=poland(); f2=poland(); return f1+f2;
        case'-':f1=poland(); f2=poland(); return f1-f2;
        case'*':f1=poland(); f2=poland(); return f1*f2;
        case'/':f1=poland(); f2=poland(); return f1/f2;
        default: return atof(a);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        printf("%lf\n",poland());
    }
    return 0;
}
