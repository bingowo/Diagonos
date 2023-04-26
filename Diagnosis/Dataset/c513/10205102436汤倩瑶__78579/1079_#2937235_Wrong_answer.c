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
        int a[1001]={0};
long long int b[500501]={0};
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
        printf("case #%d:\n",i);
        int l,u;
        for(int j=0;j<m;j++)
        {
            scanf("%d%d",&l,&u);
            int ans=0;
            for(int k=l-1;k<u;k++)
                ans+=b[k];
            printf("%d\n",ans);

        }

    }



}
