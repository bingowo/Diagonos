#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int digit(int n)
{
    int i=0;
    while (n)
    {
        i++;
        n/=10;
    }
    return i;
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
            m=digit(N);
            long long n=(long long)pow(10,m-1);
            x=1;
            for (int j=0;j<N;j++)
            {
                n=(long long)pow(10,digit(x)-1);
                x=x*N/n;
            }
            n=(long long)pow(10,digit(x)-1);
            x=x/n;
            printf("%d\n",x);
        }

    }


    return 0;
}
