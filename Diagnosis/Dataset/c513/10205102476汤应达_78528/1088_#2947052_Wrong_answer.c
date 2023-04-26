#include<stdio.h>

int main()
{
    int t,m,n,d;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d%d",&m,&n);d=m-n;
        unsigned long long ans=1;
        if(n==0) ans=1;
        else
        {
            for(int j=1;j<=d;j++)
            {
                ans*=(m-j+1);
                ans/=j;
            }
        }
        printf("case #%d:\n%d\n",i,ans);
    }
}
