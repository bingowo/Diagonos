#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nn(int n)
{
    double p,a;
    long long m;
    if (n==2) return 4;
    p=n*log10(n+0.);
    m=(long long)p;
    a=p-m;
    return (int)pow(10,a);
}

int main()
{
    int N=1;
    while (1)
    {
        int m,x;
        scanf("%d",&N);
        if (N==0) break;
        else
        {

            printf("%d\n",nn(N));
        }

    }


    return 0;
}
