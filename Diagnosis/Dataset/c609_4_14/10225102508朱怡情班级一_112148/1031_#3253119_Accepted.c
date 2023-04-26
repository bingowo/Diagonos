#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int cmp(const void* a,const void* b)
{
    return *(long long*)a<*(long long*)b?-1:1;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n,m;
        scanf("%d%d",&n,&m);
        int cnt=0;
        int a[1001]={0};
        long long b[500509];
        for(int j=1;j<=n;j++){
            scanf("%d",&a[j]);
            a[j]+=a[j-1];
        }
        for(int len=1;len<=n;len++){
            for(int l=1;l<=n-len+1;l++){
                b[++cnt]=a[l+len-1]-a[l-1];
            }
        }
        qsort(b,cnt+1,sizeof(long long),cmp);
        for(int j=1;j<=cnt;j++)b[j]+=b[j-1];
        printf("case #%d:\n",i);
        for(int j=0;j<m;j++){
            int U,L;
            scanf("%d%d",&U,&L);
            printf("%lld\n",b[L]-b[U-1]);
        }
    }
    return 0;
}
