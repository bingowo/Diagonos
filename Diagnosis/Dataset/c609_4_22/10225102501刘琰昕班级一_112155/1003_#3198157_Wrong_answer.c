#include <stdio.h>
#include <stdlib.h>

int Tto2333(long long x)
{
    if(x>0)
    {
        Tto2333(x/2333);
        printf("%lld ",x%2333);
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
        scanf("%d",&N);
        if(N==0){printf("0");continue;}
        if(N<0)
        {
            printf("-");
            N=-N;
        }
        Tto2333(N);
        printf("\n");
    }
    return 0;
}
