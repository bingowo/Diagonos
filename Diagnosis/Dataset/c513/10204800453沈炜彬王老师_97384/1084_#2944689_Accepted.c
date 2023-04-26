#include <stdio.h>

long long int cal(long long int N);

int
main()
{
    int questions;
    long long int N;
    long long int result;
    
    scanf("%d",&questions);
    for (int i=0; i<questions; i++)
    {
        scanf("%lld",&N);
        result = cal(N);
        printf("case #%d:\n",i);
        printf("%lld\n",result);
    }
    
    return 0;
}


long long int
cal(long long int N)
{
    long long int num = 1;
    
    for (int i=0; i<N; i++)
    {
        num *= 2;
    }
    
    return num;
}