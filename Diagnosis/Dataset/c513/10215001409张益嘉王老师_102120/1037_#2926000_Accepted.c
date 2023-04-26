#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
   long long aa=*((long long*)a);
   long long bb=*((long long*)b);
    if(aa>bb) return -1;
    else if(aa<bb) return 1;
    else return 0;

}

int main()
{
    int n,m,i,j;


    scanf("%d%d",&n,&m);
    long long *x=(long long*)malloc(n*sizeof(long long));
    for(i=0;i<n;i++)
    {
        scanf("%lld",&x[i]);
    }
    qsort(x,n,sizeof(long long),cmp);

    long long ans=0;

    for(i=1;i<m;i++)
    {
            ans+=(x[0]-x[i]);
    }
    long long re=ans;
    for(i=1;i<n-m+1;i++)
    {
        re=re+(x[i-1]-x[i+m-1])-(x[i-1]-x[i])*m;
        if (re<ans) ans=re;
    }

    printf("%lld",ans);
    return 0;

}
