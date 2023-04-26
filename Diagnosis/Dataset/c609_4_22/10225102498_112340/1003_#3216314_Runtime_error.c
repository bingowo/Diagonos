#include <stdio.h>
#include <stdlib.h>
#define H 2333

int main()
{
    unsigned long long i;
    unsigned long long T;
    unsigned long long n;
    scanf("%llu",&T);
    for(i=0; i<T; i++)
    {
        scanf("%llu",&n);
        unsigned long long k = 0;
        unsigned long long h = H;
        while(h<=n)
        {
            h = h*H;
            k++;
        }
        //printf("h=%d\nk=%d",h,k);
        h = h/H;
        unsigned long long j = 0;
        for(j=0; j<=k; j++)
        {
            unsigned long long k;
            k = n/h;
            printf("%llu ",k);
            n = n%h;
            h = h/H;
        }
        printf("\n");
    }

    return 0;
}
