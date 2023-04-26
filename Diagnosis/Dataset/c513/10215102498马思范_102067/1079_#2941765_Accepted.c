#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    long long x=*(long long*)a;
    long long y=*(long long*)b;
    if(x>y)
        return 1;
    else
        return -1;
}
int main()
{
    int t;
    int n,m;
    scanf("%d",&t);
    for (int i=0;i<t;i++)
    {
        int L[20];
        int U[20];
        int a[1001]={0};
        long long int b[500501]={0};
        int cnt=0;
        scanf("%d%d",&n,&m);
        for(int j=1;j<=n;j++)
        {
            scanf("%d",a+j);
            a[j]=a[j]+a[j-1];
        }
        for(int q=0;q<m;q++)
        {
            scanf("%d%d",&L[q],&U[q]);
        }
        for(int len=1;len<=n;len++)
        {
            for(int k=1;k<=n-len+1;k++)
            {
                b[++cnt]=a[k+len-1]-a[k-1];
            }
        }
        qsort(b,cnt,sizeof(b[0]),cmp);
        for(int p=1;p<=cnt;p++)
        {
            b[p]=b[p]+b[p-1];
        }
        printf("case #%d:\n",i);
        for(int x=0;x<m;x++)
        {
            printf("%lld\n",b[U[x]]-b[L[x]-1]);
        }
    }
}