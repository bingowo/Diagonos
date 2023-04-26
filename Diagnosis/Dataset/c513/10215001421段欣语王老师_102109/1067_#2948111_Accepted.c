#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long Trib[74]={0,1,1};
    int T,N;
    scanf("%d",&T);
    for(int j=3;j<74;j++)
        Trib[j]=Trib[j-1]+Trib[j-2]+Trib[j-3];
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d",&N);
        printf("%lld\n",Trib[N]);
    }
    return 0;
}