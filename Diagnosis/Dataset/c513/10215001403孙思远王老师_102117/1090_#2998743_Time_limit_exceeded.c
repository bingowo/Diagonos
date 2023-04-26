#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x;
    while(scanf("%d",&x)!=0)
    {
        int k=x*log10(x);
        double a=pow(10,(x*log10(x)-k));
        int b=(int)a;
        printf("%d\n",b);
    }
    return 0;
}
