#include <stdio.h>

void trans(int N)
{
    if(N>0)
    {
        trans(N/2333);
        printf("%d ",N%2333);
    }
}

int main()
{
    int T,N;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&N);
        if(N==0)printf("0");
        else trans(N);
        printf("\n");
    }
    return 0;
}
