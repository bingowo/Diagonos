#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int solve(int m)
{
    int w[1100]={0},x[1100]={0};

    for(int i=0;i<=1000;i++)
    {
        int k=i/3;
        for(int j=1;j<=k;j++)
           x[i]+=(i-j*3)/2+1;
    }
    for(int i=0;i<=1000;i++)
    {
        int k=i/4;
        for(int j=1;j<=k;j++)
            w[i]+=x[i-j*4]+(i-j*4)/2+1;
    }
    return w[m]+x[m]+m/2+1;

}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d",&m);
        int ans;
        ans=solve(m);
        printf("%d\n",ans);
    }
    return 0;
}