#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b){
    int a1=*(int*)a, b1=*(int*)b;
    if (a1>b1) return 1;
    else return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        int n,m;
        scanf("%d%d",&n,&m);
        int a[1000];
        int sum[1001];
        int *b=(int*)malloc(sizeof(int)*(n*(n+1))/2);
        for(int j=0;j<n;j++)
            scanf("%d",&a[j]);
        sum[0]=0;
        for (int j=0;j<n;j++)
            sum[j+1]=sum[j]+a[j];
        int count=0;
        for (int j=0;j<=n;j++)
            for (int k=0;k<j;k++) b[count++]=sum[j]-sum[k];

        qsort(b,count,sizeof(b[0]),cmp);
        printf("case #%d:\n",i);
        for (int j=0;j<m;j++){
            int l,u;
            scanf("%d%d",&l,&u);
            long long plus=0;
            for (int k=l-1;k<u;k++)
                plus+=b[k];
            printf("%lld\n",plus);

        }
        free(b);
    }


    return 0;
}