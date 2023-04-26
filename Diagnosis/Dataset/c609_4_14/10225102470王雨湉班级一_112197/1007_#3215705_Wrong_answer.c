#include <stdio.h>
#include <stdlib.h>

int Number(long long int n)
{
        int count=0;
        for(int z=0; z<64; z++)
        {
                if((n&(1<<z))!=0)
                        count++;
        }
        return count;
}

int cmp(const void* a,const void* b)
{
        if(Number(*(long long int*)a)>Number(*(long long int*)b))
                return -1;
        else if(Number(*(long long int*)a)<Number(*(long long int*)b))
                return 1;
        else
                return *(long long int*)a-*(long long int*)b;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
            int N;
            scanf("%d",&N);
            long long int s[N+1];
            for(int j=0; j<N; j++)
                scanf("%lld",&s[j]);
            if(N!=1)
                qsort(s,N,sizeof(s[0]),cmp);
            printf("case #%d:\n",i);
            for(int j=0; j<N; j++)
                printf("%lld ",s[j]);
            printf("\n");
    }
    return 0;
}
