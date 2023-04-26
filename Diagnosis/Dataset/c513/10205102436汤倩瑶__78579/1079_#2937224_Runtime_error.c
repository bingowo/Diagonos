#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    return *((int*)a)-*((int *)b);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int *a=(int *)malloc(sizeof(int)*n);
        long long int *b=(long long int *)malloc(sizeof(long long int)*n*(n-1)/2);
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        int cnt=0;int k=1;
        while(k<=n){
        for(int p=0;(k+p)<=n;p++)
        {
            int sum=0;

            for(int t=0;t<k;t++)
            {
                sum+=a[p+t];
            }
            b[cnt++]=sum;
        }
        k++;
        }
        qsort(b,cnt,sizeof(b[0]),cmp);
        //for(int j=0;j<cnt;j++)
        //printf("%d ",b[j]);
        for(int j=0;j<cnt;j++) b[j]+=b[j-1];
        printf("case #%d:\n",i);
        int l,u;
        for(int j=0;j<m;j++)
        {
            scanf("%d%d",&l,&u);
            printf("%lld\n",b[u-1]-b[l-2]);

        }

    }



}
