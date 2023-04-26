#include<stdio.h>
#include<stdlib.h>

int cnt(long long n)
{
    int cnt=0;
    if(n==0) cnt=0;
    else
    {
        while(n!=0)
        {
            n=n&(n-1);
            cnt++;
        }
    }
    return cnt;
}

int cmp(const void*p1, const void*p2)
{
    long long *a=(long long*)p1;
    long long *b=(long long*)p2;
    int a1=cnt(*a);int b1=cnt(*b);
    if(a1!=b1) return b1-a1;
    else
    {
        if(*a>*b) return 1;
        if(*a<*b) return -1;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        int N; 
        scanf("%d",&N);
        long long a[N];
        for(int i=0;i<N;i++)
        {
            scanf("%lld",&a[i]);
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",cas);
        for(int i=0;i<N;i++)
        {
            printf("%lld ",a[i]);
        }
        printf("\n");
    }
    return 0;
}