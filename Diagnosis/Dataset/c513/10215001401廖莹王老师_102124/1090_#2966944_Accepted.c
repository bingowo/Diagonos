#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n=0;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        else
        {
            double x1=0,x2=0,re=0;long long k=0;
            x1=log10(n)*n;
            k=(long long)x1;
            x2=x1-k;
            re=pow(10,x2);
            while(re>=10){re=re/10;}k=(long long )re;
            printf("%lld\n",k);
        }
    }
    return 0;
}
