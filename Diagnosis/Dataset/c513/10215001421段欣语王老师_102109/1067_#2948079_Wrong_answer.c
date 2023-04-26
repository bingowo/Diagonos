#include <stdio.h>
#include <stdlib.h>

long long Trib[74]={0,1,1};

void com(int N)
{
    int i;
    for(i=3;i<N;i++)
    Trib[i]=Trib[i-1]+Trib[i-2]+Trib[i-3];
}

int main()
{
    long long Trib[74]={0,1,1};
    int T,N;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d",&N);
        com(N);
        printf("%lld",Trib[N]);
    }
    return 0;
}