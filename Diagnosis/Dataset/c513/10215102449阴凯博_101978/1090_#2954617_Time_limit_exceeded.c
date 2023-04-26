#include <stdio.h>
#include <stdlib.h>

long long pow(int n)
{
    long long m=1;
    for (int i=0;i<n;i++)
        m=m*10;
    return m;

}

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
            long long n=pow(m-1);
            x=1;
            for (int j=0;j<N;j++)
            {
                n=pow(digit(x)-1);
                x=x*N/n;
            }
            n=pow(digit(x)-1);
            x=x/n;
            printf("%d\n",x);
        }

    }


    return 0;
}
