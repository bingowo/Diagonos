#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

long long cmp(const void *_a, const void *_b);
long long sum(long long *a, int start, int end);

int main()
{
    int n,m;
    long long min=0,t;
    int i;
    //输入数据
    scanf("%d %d",&n,&m);
    long long *a = (long long *)malloc(sizeof(long long)*n);
    for (i=0;i<n;i++)
    {
        scanf("%lld",a+i);
    }

    //a数组降序排列
    qsort(a,n,sizeof(long long),cmp);

    for (i=0;i<n-m;i++)
    {
        t=(m-1)*a[i]-sum(a,i+1,i+m-1);
        if (t<min)
        {
            min=t;
        }
    }
    printf("%lld",min);
    return 0;
}


long long cmp(const void *_a, const void *_b)
{
    long long *a = (long long *)_a;
    long long *b = (long long *)_b;
    return (*b-*a);
}

long long sum(long long *a, int start, int end)
{
    int i;
    long long res=0;
    for (i=0;i<=end-start;i++)
    {
        res+=*(a+start+i);
    }
    return res;
}