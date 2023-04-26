#include <stdio.h>
#include <stdlib.h>

long long Tto2333(long long x)
{
    if(x>0)
    {
        Tto2333(x/2333);
        printf("%d ",x%2333);
    }
    else return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long long N;
        scanf("%lld",&N);
        if(N==0)printf("0");
        Tto2333(N);
        printf("\n");
    }
    return 0;
}
