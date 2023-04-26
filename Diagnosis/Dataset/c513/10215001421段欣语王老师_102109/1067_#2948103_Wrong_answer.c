#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,N;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long long Trib[74]={0,1,1};
        printf("case #%d:\n",i);
        scanf("%d",&N);
        for(int j=3;j<N;j++)
        Trib[j]=Trib[j-1]+Trib[j-2]+Trib[j-3];
        printf("%lld\n",Trib[N]);
    }
    return 0;
}