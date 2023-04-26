#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int dp[100000]={0};
    int total=0,id,j,n,a[11]={0},ans[1001]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        total+=a[i];
    }
    dp[1]=a[0];dp[2]=-a[0];id=2;
    for(int i=1;i<n;i++)
    {   j=1;
        for(int q=0;q<=id;q++)
        {
            dp[id+j]=dp[q]+a[i];
            dp[id+j+1]=dp[q]-a[i];
            dp[id+j+2]=dp[q];
            j+=3;
        }
        id=id+j;
    }
    for(int i=1;i<=id;i++)
    {
        if(abs(dp[i]))
           ans[dp[i]]=1;
    }
    for(int i=1;i<=total;i++)
    {
        if(ans[i])
            printf("1");
        else
            printf("0");
    }
    return 0;
}
