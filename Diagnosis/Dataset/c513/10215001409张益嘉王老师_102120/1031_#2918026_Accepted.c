#include <stdio.h>
#include <stdlib.h>

int cmp1(const void*a,const void*b)
{
    long long aa=*((long long*)a);
    long long bb=*((long long*)b);
    if(aa>bb) return -1;
    else if(aa<bb) return 1;
    else return 1;
}

int cmp2(const void*a,const void*b)
{
    long long aa=*((long long*)a);
    long long bb=*((long long*)b);
    if(aa<bb) return -1;
    else if(aa>bb) return 1;
    else return -1;
}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int j;
        long long n,a[1500],b[1500],re=0;
        memset(a,0,sizeof(long long)*1500);
        memset(b,0,sizeof(long long)*1500);
        scanf("%lld",&n);
        for(j=0;j<n;j++)
        {
            scanf("%lld",&a[j]);
        }
        for(j=0;j<n;j++)
        {
            scanf("%lld",&b[j]);
        }
        qsort(a,n,sizeof(long long),cmp1);
        qsort(b,n,sizeof(long long),cmp2);
        for(j=0;j<n;j++)
        {
            re+=a[j]*b[j];
        }
        printf("case #%d:\n%lld\n",i,re);
    }
}
