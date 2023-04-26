#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    long long int c=*((long long int *)a);
    long long int d=*((long long int *)b);
    if(c<=d) return -1;
    else return 1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        printf("case #%d:",cas);
        int n,m;
        scanf("%d %d",&n,&m);
        int a[1001]={0};
        long long int b[500501]={0};
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            scanf("%d",a+j);
            a[j]+=a[j-1];
        }
        for(int len=1;len<=n;len++)
            for(int i=1;i<=n-len+1;i++)
                b[++cnt]=a[i+len-1]-a[i-1];
        qsort(b,cnt,sizeof(b[0]),cmp);
        for(int i=1;i<=cnt;i++) b[i]+=b[i-1];
        for(int k=0;k<m;k++)
        {
            int L,U;scanf("%d %d",&L,&U);
             printf("%lld",(b[U]-b[L-1]));
        }
    }
    return 0;
}
