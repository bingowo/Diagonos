#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

int main()
{
    unsigned long long n;
    unsigned long long sum =0;
    long long n0 =1;
    scanf("%lu",&n);

    while(sum<=n)
    {
          sum+=n0*4+2;
          n0+=2;
    }
    sum -= (2+(n0-2)*4);
    long long po = n0/2-1;
    n0-=2;
    long long x = po;
    long long y = po*(-1);
    if(n==sum)printf("(%lld,%lld)",x,y);
    else
    {

        if(n<=sum+n0)
        {
            printf("(%lld,%lld)",x,y+n-sum);
            return 0;
        }

        else if(n<=sum+n0*2)
        {   y+=n0;
            printf("(%lld,%lld)",x-(n-sum-n0),y);
                return 0;
        }

        else if(n<=sum+n0*3+1)
        {   y+=n0;
            x-=n0;
            printf("(%lld,%lld)",x,y-(n-sum-2*n0));
            return 0;
        }

        else if(n<sum+n0*4+2)
        {
            y=y-1;
            x-=n0;
            printf("(%lld,%lld)",x+n-sum-3*n0-1,y);
            return 0;
        }

    }
    return 0;
}
