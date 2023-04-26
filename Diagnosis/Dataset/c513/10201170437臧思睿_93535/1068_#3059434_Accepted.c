#include <stdio.h>
#include <math.h>

int dp(int n,int m)
{
    if(n>m)
    {
        return (dp(n-1,m)*2+pow(2,n-m-1)-dp(n-m-1,m));
    }
    else if(n==m){return 1;}
    else{return 0;}
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=0 && n!=-1)
    {
        printf("%d\n",dp(n,m));
    }
    return 0;
}
