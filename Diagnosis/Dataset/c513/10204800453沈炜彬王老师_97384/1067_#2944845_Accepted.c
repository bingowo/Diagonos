#include <stdio.h>

long long int cal(int N, long long int *pnum);

int
main()
{
    int questions;
    int N;
    long long int result;
    long long int num[74] = {0};
    num[0] = 0;
    num[1] = 1;
    num[2] = 1;
    
    scanf("%d",&questions);
    
    for (int i=0; i<questions; i++)
    {
        scanf("%d",&N);
        result = cal(N,num);
        
        printf("case #%d:\n",i);
        printf("%lld\n",result);
    }
    
    return 0;
}

long long int
cal(int N, long long int *pnum)
{
    if (N == 0)
    {
        return 0;
    }
    else if (N == 1)
    {
        return 1;
    }
    else if (N == 2)
    {
        return 1;
    }
    else
    {
        if (*(pnum+N) == 0)
        {
            *(pnum+N) = cal(N-1, pnum) + cal(N-2, pnum) + cal(N-3, pnum);
            return *(pnum+N);
        }
        else
        {
            return *(pnum+N);
        }
    }
}