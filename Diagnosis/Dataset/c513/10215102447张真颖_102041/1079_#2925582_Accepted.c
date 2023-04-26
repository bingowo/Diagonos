#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    long long aa=*(long long*)a,bb=*(long long*)b;
    if(aa>bb) return 1;
    else if(aa<bb) return -1;
    else return 0;
}


int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n=0,m=0;
        scanf("%d%d",&n,&m);
        long long int a[1001]={0};
        long long* b=(long long*)malloc(sizeof(long long)*(n*(n+1)/2+1));
        b[0]=0;
        int cnt=0;
        for(int i=1;i<=n;i++){scanf("%d",a+i);a[i]+=a[i-1];}
        for(int len=1;len<=n;len++)
            for(int i=1;i<=n-len+1;i++)
              b[++cnt]=a[i+len-1]-a[i-1];
        qsort(b,cnt,sizeof(b[0]),cmp);
        for(int i=1;i<=cnt;i++) b[i]+=b[i-1];
        printf("case #%d:\n",i);
        for(int j=0;j<m;j++)
        {
            int L=0,U=0;
            scanf("%d%d",&L,&U);
            printf("%lld\n",b[U]-b[L-1]);
        }
        free(b);
    }
    return 0;
}