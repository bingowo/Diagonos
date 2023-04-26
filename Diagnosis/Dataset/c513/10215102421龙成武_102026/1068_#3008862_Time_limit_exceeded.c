#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int func(int n,int m)
{
    int ans=0;
    if(n==m)
        ans=1;
    else if(n>m)
    {
        for(int i=0;i<m;i++)
        {
            ans+=func(n-(i+1),m);
        }
        ans+=pow(2,n-m);
    }
    return ans;
}
int main()
{
    int n,m;
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(n==-1||m==-1)
            break;
        printf("%d\n",func(n,m));
    }
    return 0;
}
