#include<stdio.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        int j;
        long long ans=1;
        for(j=1;j<=n;j++)
        {
            ans*=m-j+1;
            ans/=j;
        }
        printf("case #%d:\n%lld\n",i,ans);
    }
    return 0;
}