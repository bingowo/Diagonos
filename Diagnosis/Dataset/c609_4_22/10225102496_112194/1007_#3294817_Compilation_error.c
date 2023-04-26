#include<stdio.h>
#include<stdlib.h>

int cnt(long long n)
{
    int cnt=0;
    if(n>0)
    {
        while(n!=0)
        {
            if(n&1) cnt++;
            n=n>>1;
        }
    }
    if(n==0) cnt=0;
    if(n<0)
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
    long long *a=(int*)p1;
    long long *b=(int*)p2;
    int a1=cnt(*a);int b1=cnt(*b);
    if(a1!=b1) return b1-a1;
    else return int(*a-*b);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;i++)
    {
        int N; 
        scanf("%d",&N);
        long long a[N];
        for(int i=0;i<N;i++)
        {
            scanf("%lld",&a[i]);
            qsort(a,N,sizeof(a[0]),cmp);
        }
        printf("case #%d:\n",cas);
        for(int i=0;i<N;i++)
        {
            printf("%lld ",a[i]);
        }
    }
    return 0;
}