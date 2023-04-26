#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    int* ap=(int*)a;
    int* bp=(int*)b;
    return (*ap-*bp);
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int n,m;
        scanf("%d %d",&n,&m);//原数组共有n个值，计算m个和
        int a[1001]={0};int b[20][2]={0};//a存储原数组b存储LU
        int j,l,k,q,amount;
        long long int total;
        for(j=0;j<n;j++)
            scanf("%d",&a[j]);
        for(j=0;j<m;j++)
            scanf("%d %d",&b[j][0],&b[j][1]);
        int c[510000]={0};
        for(l=1,q=0;l<=n;l++)
        {
            for(j=0;j<n&&((n-j)>=l);j++)
            {
                amount=a[j];
                for(k=j+1;(k-j)<l;k++)
                {
                    amount=amount+a[k];
                }
                c[q++]=amount;
            }
        }
        qsort(c,q,sizeof(int),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<m;j++)
        {
            total=0;
            for(k=b[j][0]-1;k<b[j][1];k++)
                total=total+c[k];
            printf("%lld\n",total);
        }
    }
}