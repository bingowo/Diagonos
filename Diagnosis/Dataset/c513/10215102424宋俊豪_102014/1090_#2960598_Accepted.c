#include <stdio.h>
#include <math.h>

int main()
{
    int i,k;
    double n,a;
    while(scanf("%lf",&n)!=EOF)
    {   if(n<=0.001)continue;
        k=n*log10(n);
        a=pow(10,(n*log10(n))-k);
        printf("%d\n",(int) a);
    }
    return 0;
}
