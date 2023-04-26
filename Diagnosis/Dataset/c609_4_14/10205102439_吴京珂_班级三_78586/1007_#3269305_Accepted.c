#include <stdio.h>
#include <stdlib.h>

int f(long long int x)
{
    int cnt=0;
    for(int i=0;i<64;i++)//注意
    {
        if(x&1==1) cnt+=1;
        x=x>>1;//右移
    }
    return cnt;
}

int cmp(const void *a1,const void *b1)//比较函数
{
    long long int a=*(long long int*)a1;
    long long int b=*(long long int*)b1;
    if(f(a)>f(b)) return -1;
    else if(f(a)<f(b)) return 1;
    else
    {
        if(a<b) return -1;
        else return 1;
    }


}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        int N;
        scanf("%d",&N);
        long long int a[10005];
        for(int j=0; j<N; j++)
        {
            scanf("%lld",&a[j]);
        }

        qsort(a,N,sizeof(a[0]),cmp);//qsort

        printf("case #%d:\n",i);
        for(int j=0; j<N-1; j++)
        {
            printf("%lld ",a[j]);
        }
        printf("%lld\n",a[N-1]);

    }

    return 0;
}