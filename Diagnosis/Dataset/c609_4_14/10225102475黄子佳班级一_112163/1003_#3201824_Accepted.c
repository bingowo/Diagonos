#include <stdio.h>

void trans(long long int N)
{
    if(N>0)
    {
        trans(N/2333);
        printf("%d ",N%2333);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long long int N;
        scanf("%lld",&N);
        if(N==0)printf("0");
        else trans(N);
        printf("\n");
    }
    return 0;
}
