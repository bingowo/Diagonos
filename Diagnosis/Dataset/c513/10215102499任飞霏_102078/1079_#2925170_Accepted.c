#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b);

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        int n,m;
        scanf("%d %d",&n,&m);
        int a[1001]={0};
        long long *b = (long long*)malloc(500501*sizeof(long long));
        int cnt = 0;
        for(int j = 1;j <=n;j++){
            scanf("%d",a+j);
            // 将a各位变为由a[0]到该位的和
            a[j]+=a[j-1];
        }
        for(int len = 1;len<=n;len++){
            // 由b[len]开始往后逐个家和，b[len]和他后面一个，后面两个…
            for(int i = 1;i <= n-len+1;i++){
                b[++cnt]=a[i+len-1]-a[i-1];
            }
        }
        // b中已经存好子数组和了，现在排序
        qsort(b,n*(n+1)/2,sizeof(long long int),cmp);
        // 仿照a，通过减法求得和
        for(int k=1;k<=cnt;k++)b[k]+=b[k-1];
        for(int k = 0;k < m;k++){
            int L,U;
            scanf("%d %d",&L,&U);
            printf("%lld\n",b[U]-b[L-1]);
        }
    }
    return 0;
}

int cmp(const void* a,const void* b)
{
    long long int x = *((long long*)a);
    long long int y = *((long long*)b);
    return (int)(x-y);
}

