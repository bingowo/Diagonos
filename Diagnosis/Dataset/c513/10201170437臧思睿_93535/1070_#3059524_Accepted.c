#include <stdio.h>
#include <math.h>

int dp(int n)
{
    if(n==3){return 1;}
    else if(n<3){return 0;}
    else
    {
        return(dp(n-1)*2+pow(2,n-2)-dp(n-2)-pow(2,n-3)+dp(n-3));
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=0 && n!=-1)
    {
        int s=pow(2,n)-dp(n);
        printf("%d\n",s);
    }
    return 0;
}
