#include<stdio.h>
#include<string.h>
#include<math.h>
typedef unsigned long long ll;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        ll n,m;
        scanf("%llu %llu",&m,&n);
        ll ans=1;
        if(n>m-n)
        {
            for(int j=1;j<=n;j++)
            {
                ans=ans*(m-n+j);
                ans=ans/j;
            }
        }
        else
        {
            for(int j=1;j<=m-n;j++)
            {
                ans=ans*(n+j);
                ans=ans/j;
            }
        }
        printf("case #%d:\n%llu\n",i,ans);
    }
}
