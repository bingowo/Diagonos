#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        if(x==0)break;
        int k=x*log10(x);
        double a=pow(10,(x*log10(x)-k));
        printf("%d\n",(int)a);
    }
    return 0;
}
