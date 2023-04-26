#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void*a,const void*b)
{
    return *(long long*)b-*(long long*)a;
}

int main()
{
    long long a[10001];
    long long t=0;
    int n,i;scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        t^=a[i];
    }
    if(t!=0)printf("-1");
    else
    {
        long long t1=0,t2=0;
        qsort(a,n,sizeof(a[0]),cmp);
        for(i=0;i<n-1;i++)
        {
            t2=t2+a[i];
            t1=t1+t2/1000000;
            t2=t2%1000000;
        }
        if(t1!=0)printf("%lld%06lld",t1,t2);
        else printf("%lld",t2);
    }
    
}