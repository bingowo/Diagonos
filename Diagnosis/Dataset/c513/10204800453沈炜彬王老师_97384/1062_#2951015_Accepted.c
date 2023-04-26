#include <stdio.h>

long long int cal(int N,long long int *n);

int
main()
{
    long long int n[51] = {0};
    int questions;
    long long int count=0;
    int N;

    
    scanf("%d",&questions);
    for (int i=0; i<questions; i++)
    {
        count = 0;
        scanf("%d",&N);
        count = cal(N,n);
        printf("case #%d:\n",i);
        printf("%lld\n",count);
    }
    
    
    return 0;
}


long long int
cal(int N,long long int *n)
{
    if (n[N] != 0)
    {
        return n[N];
    }
    else
    {
        if (N == 4)
        {
            return 8;
        }
        else if (N == 3)
        {
            return 4;
        }
        else if (N == 2)
        {
            return 2;
        }
        else if (N == 1)
        {
            return 1;
        }
        else
        {
            n[N] = cal(N-1,n)+cal(N-2,n)+cal(N-3,n)+cal(N-4,n);
            return n[N];
        }
    }
}