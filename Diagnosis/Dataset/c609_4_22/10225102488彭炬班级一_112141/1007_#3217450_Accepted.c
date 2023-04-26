#include <stdio.h>
#include <stdlib.h>

int cnt(long long int data)
{
    int number = 0,a;
    for(int i = 0;i < 64;i++)
        if((data>>i) & 1)
        number ++;
    return number;
}

int cmp(const void *a,const void *b)
{
    long long int *d1,*d2;
    d1 = (long long int *)a;
    d2 = (long long int *)b;
    if(cnt(*d1)==cnt(*d2))
        {
            if(*d1 < *d2)
                return -1;
            else if(*d1 > *d2)
                return 1;
            else if(*d2 > *d1)
                return 0;
        }
    else if(cnt(*d1) < cnt(*d2))
        return 1;
    else
        return -1;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int a = 0;a < T;a++)
    {
        int N;
        scanf("%d",&N);
        long long int n[N];
        for(int b = 0;b < N;b++)
            scanf("%lld",&n[b]);
        qsort(n,N,sizeof(n[0]),cmp);
        printf("case #%d:\n",a);
        for(int c = 0;c < N;c++)
            printf("%lld ",n[c]);
        printf("\n");
    }
    return 0;
}

