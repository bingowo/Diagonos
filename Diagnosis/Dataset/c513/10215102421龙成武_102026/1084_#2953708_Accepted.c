#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int T,i,j,N;
    long long res;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        res=1;
        for(j=0;j<N;j++)
        {
            res*=2;
        }

        printf("case #%d:\n",i);
        printf("%d\n",res);
    }
    return 0;
}

