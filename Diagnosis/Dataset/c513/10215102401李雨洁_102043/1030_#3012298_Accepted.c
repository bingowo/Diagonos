#include <stdio.h>
#include <stdlib.h>

int cmp(const void *_a,const void *_b)
{
    long long a = *((long long*)_a);
    long long b = *((long long*)_b);
    long long i,j;
    i = a;
    j = b;
    if(i < 0) i = -i;
    if(j < 0) j = -j;
    while(i / 10) i /= 10;
    while(j / 10) j /= 10;
    if(i == j)
    {
        if(a > b) return 1;
        else return -1;
    }
    else return j - i;
}


int main()
{
    int t;
    scanf("%d",&t);
    long long a[10001];
    for(int k = 0; k < t; k++)
    {
        int n;
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%lld",&a[i]);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",k);
        for(int i = 0; i < n - 1; i++)
        {
            printf("%lld ",a[i]);
        }
        printf("%lld\n",a[n-1]);
    }
}


