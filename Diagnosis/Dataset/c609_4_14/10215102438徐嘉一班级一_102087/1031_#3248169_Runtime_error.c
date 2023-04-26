#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int T,n,m,L,U,a[1001]={0};
    long long int b[500501]={0};
    int cnt=0;
    scanf("%d",&T);
    for(int c=0;c<T;c++)
    {
        scanf("%d %d\n",&n,&m);
        for(int j=1;j<=n;j++)
        {
            scanf("%d",a+j);
            a[j]+=a[j-1];
        }
        for(int h=0;h<m;h++)
        {
            scanf("%d %d\n",&L,&U);
        }
        for(int len=1;len<=n;len++)
        {
            for(int i=1;i<=n-len+1;i++)
            {
                b[++cnt]=a[i+len-1]-a[i-1];
            }
        }
        qsort(b,cnt,sizeof(long long int),cmp);
        for(int i=1;i<=cnt;i++)
            b[i]+=b[i-1];
        printf("case #%d:\n",c);
        printf("%lld\n",b[U]-b[L-1]);
    }
    return 0;
}
