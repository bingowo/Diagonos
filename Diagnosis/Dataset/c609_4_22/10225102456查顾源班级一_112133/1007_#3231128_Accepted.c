#include<stdio.h>
#include<stdlib.h>

struct num{
    int sum;
    long long n;
};

int cmp(const void *a,const void *b){
    struct num* d1 = (struct num*)a;
    struct num* d2 = (struct num*)b;
    if(d2->sum == d1->sum){
        if(d1->n > d2->n)
            return 1;
        else
            return -1;
    }
    else
        return d2->sum - d1->sum;
}

int test(long long a)
{
    int sum=0;
    for (int i = 0;i < 64;++i){
        if((a & 1 )== 1)
            sum++;
        a >>= 1;
    }
    return sum;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int j=0;j<T;j++)
    {
        int k;
        struct num arr[10001];
        scanf("%d",&k);
        for (int i=0;i<k;i++)
        {
            scanf("%lld",&arr[i].n);
            long long temp=arr[i].n;
            arr[i].sum=test(temp);
        }
        qsort(arr,k,sizeof(arr[0]),cmp);
        printf("case #%d:\n",j);
        for(int x=0;x<k-1;x++)
            printf("%lld ",arr[x].n);
        printf("%lld\n",arr[k-1].n);
    }
    return 0;
}