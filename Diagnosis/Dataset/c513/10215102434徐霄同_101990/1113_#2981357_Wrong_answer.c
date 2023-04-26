#include <stdio.h>
int m(int i,int k)
{
    if(i<k)
        return 0;
    else
        return i-k;
}
int main()
{
    int i,j,k,n;
    long long ans[100];
    scanf("%d%d",&k,&n);
    for(i=0;i<n;i++)
        ans[i]=0;
    ans[1]=1;
    for(i=2;i<n;i++)
        for(j=m(i,k);j<i;j++)
           ans[i]=ans[i]+ans[j];
    printf("%lld\n",ans[n-1]);
    return 0;
}
