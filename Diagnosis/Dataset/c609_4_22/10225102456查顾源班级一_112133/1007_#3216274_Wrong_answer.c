#include<stdio.h>
#include<stdlib.h>

struct num
{
    int sum;
    long long n;
};

int cmp(const void *a,const void *b)
{struct num d1,d2;
d1=*((struct num*)a);
d2=*((struct num*)b);
   if(d2.sum!=d1.sum)
    return d2.n-d1.n;
   else return d1.sum-d2.sum;
}

int test(long long a)
{
    int sum=0;
    for(int i=0;i<64;i++)
    {
        long long mask=1LL<<i;
        if(a&mask!=0)
          sum++;
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
