#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int zgw(long long x)
{
    if(x<0) x=-x;
    while((x/10)!=0)
    {
        x=x/10;
    }
    return x;
}

int cmp(const void*a,const void*b)
{
    int ha=zgw(*((long long*)a));
    int hb=zgw(*((long long*)b));
    if(ha==hb)
    {
        if((*((long long*)a))>(*((long long*)b))) return 1;
        else return -1;
    }
    else return hb-ha;
}


int main()
{
    int t,i;
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        int n,j;
        long long x[11000];
        //int h[11000];
        memset(x,0,11000*sizeof(long long));
        //memset(h,0,11000*sizeof(int));
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%lld",&x[j]);
        }
        qsort(x,n,sizeof(long long),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n-1;j++)
        {
            printf("%lld ",x[j]);
        }
        printf("%lld\n",x[j]);


    }
    return 0;
}
