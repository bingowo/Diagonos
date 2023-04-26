#include <stdio.h>

#define LEN 1000
#define N 10007

typedef unsigned long long ull;

ull find(ull n,ull m,ull a,ull b)
{
    static ull dp[LEN+1][LEN+1]= {1};
    int x,y;
    for(x=0; x<=n; x++)
    {
        for(y=0; y<=m; y++)
        {
            if(x+y)
            {
                if(x==0) dp[x][y]=dp[x][y-1]*b%N;
                else if(y==0) dp[x][y]=dp[x-1][y]*a%N;
                else dp[x][y]=(a*dp[x-1][y]+b*dp[x][y-1])%N;
            }
        }
    }
    return dp[n][m];

}

int main()
{

    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        ull a,b,k,n,m;
        scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
        printf("case #%d:\n",i);
        printf("%llu\n",find(n,m,a,b));
    }

    return 0;
}