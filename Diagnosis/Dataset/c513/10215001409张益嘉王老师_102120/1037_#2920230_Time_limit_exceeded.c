#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    long long aa=*((long long*)a);
    long long bb=*((long long*)b);
    if(aa>bb) return -1;
    else if(aa<=bb) return 1;

}

int main()
{
    long long n,m;
    int i,j;

    scanf("%lld%lld",&n,&m);
    long long *x=(long long*)malloc(n*sizeof(long long));
    for(i=0;i<n;i++)
    {
        scanf("%lld",&x[i]);
    }
    qsort(x,n,sizeof(long long),cmp);

    unsigned long long re,ans;

    for(i=0;i<n-m+1;i++)
    {
        re=0;
        for(j=1;j<m;j++)
        {
            re+=(unsigned long long)(x[i]-x[i+j]);
        }
        if(i==0) ans=re;
        else if(re<=ans) ans=re;
    }

    printf("%llu",ans);
    return 0;

}
