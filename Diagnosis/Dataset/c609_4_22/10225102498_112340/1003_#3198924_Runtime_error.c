#include <stdio.h>
#include <stdlib.h>
#define H 2333

int main()
{
    long long i;
    long long T;
    long long n;
    scanf("%lld",&T);
    for(i=0; i<T; i++)
    {
        scanf("%lld",&n);
        long long k = 0;
        long long h = H;
        while(h<=n)
        {
            h = h*H;
            k++;
        }
        //printf("h=%d\nk=%d",h,k);
        h = h/H;
        long long j = 0;
        for(j=0; j<=k; j++)
        {
            long long k;
            k = n/h;
            printf("%lld ",k);
            n = n - n/h*h;
            h = h/H;
        }
        printf("\n");
    }

    return 0;
}
