#include <stdio.h>
#include <math.h>

int main()
{
    long long n;
    while((scanf("%lld",&n)!=EOF))
    {
        if(n == 0) return 0;
        else
        {
            double f = n * log10(n);
            f -= (int)f;
            long long b = pow(10,f);
            printf("%lld\n",b);
        }
    }
    return 0;
}
