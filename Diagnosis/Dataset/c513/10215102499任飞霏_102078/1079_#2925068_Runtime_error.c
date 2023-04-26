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
        long long int b[50050]={0};
        int cnt = 0;
        for(int j = 1;j <=n;j++){
            scanf("%d",a+j);
            a[j]+=a[j-1];
        }
        for(int len = 1;len<=n;len++){
            for(int i = 1;i <= n-len+1;i++){
                b[++cnt]=a[i+len-1]-a[i-1];
            }
        }
        qsort(b,n*(n+1)/2,sizeof(long long int),cmp);
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

