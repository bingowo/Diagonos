#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
    if(*(long long int*)a>*(long long int *)b)
        return 1;
    else
        return -1;
}
int main()
{
    int t,l,u,n,m;
    scanf("%d",&t);
    for(int q=0; q<t; q++)
    {
        scanf("%d%d",&n,&m);
        int a[1001]= {0};
        long long int b[500501]= {0};
        int cnt=0;
        for(int j=1; j<=n; j++)
        {
            scanf("%d",a+j);
            a[j]+=a[j-1];
        }
        for(int len=1; len<=n; len++)
            for(int i=1; i<=n-len+1; i++)
                b[++cnt]=a[i+len-1]-a[i-1];
        qsort(b,cnt,sizeof(long long int),cmp);
        for(int i=1; i<=cnt; i++) b[i]+=b[i-1];
        printf("case #%d:\n",q);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&l,&u);
            printf("%lld\n",b[u]-b[l-1]);
        }
    }
    return 0;
}
