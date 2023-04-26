#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    long long int x=*(long long int*)a;
    long long int y=*(long long int*)b;
    return x-y;
}
void qu(long long int a[],long long int ret[],int n)
{
    int temp=1,index=0;
    while(temp<=n)
    {

    for(int i=0;i<n;i++)
    {
        int j,ans=0;
        if(temp+i<=n)
        {
        for(j=i;j<temp+i;j++)
            ans+=a[j];

        ret[index++]=ans;
        }
    }
    temp++;
    }
    qsort(ret,n*(n+1)/2,sizeof(ret[0]),cmp);

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,m,l,u;
        scanf("%d %d",&n,&m);
        long long int a[1000],ret[500500]={0};
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&a[j]);
        }
        qu(a,ret,n);
        printf("case #%d:\n",i);
        for(int j=0;j<m;j++)
        {
            long long int ans=0;
            scanf("%d %d",&l,&u);
            for(int k=l-1;k<u;k++)
                ans+=ret[k];
            printf("%lld\n",ans);

        }

    }
    return 0;
}
