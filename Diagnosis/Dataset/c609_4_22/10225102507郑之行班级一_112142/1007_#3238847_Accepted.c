#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    int a1=0,b1=0;
    long long n1=1;
    long long a2=*(long long*)a,b2=*(long long*)b;
    for(int k=0;k<64;k++)
    {
        if(a2 & n1 != 0)a1++;
        if(b2 & n1 != 0)b1++;
        a2>>=1;b2>>=1;
    }
    //printf("%lld %d\n",(*(long long*)a),a1);
    //printf("%lld %d\n",(*(long long*)b),b1);
    if (a1>b1)return -1;
    else if (a1<b1)return 1;
    else
    {
        if (*(long*)a >= *(long*)b)return 1;
        else return -1;
    }
}

int main()
{
    int T;scanf("%d\n",&T);
    int N;
    for(int i=0;i<T;i++)
    {
        scanf("%d\n",&N);
        long long num[N];
        for(int j=0;j<N;j++)
            scanf("%lld",&num[j]);

        qsort(num,N,sizeof(long long),cmp);

        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
            printf("%lld ",num[j]);
        printf("\n");
    }

    return 0;
}




