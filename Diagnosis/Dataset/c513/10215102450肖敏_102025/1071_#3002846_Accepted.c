#include <stdio.h>

#define MAX 1000
#define MOD 10007
typedef unsigned long long ull;
ull find(ull a,ull b,ull n,ull m)
{
    static ull d[MAX+1][MAX+1]={1};
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i+j)
            {
                if(i==0)
                {
                    d[i][j]=d[i][j-1]*b%MOD;
                }
                else if(j==0)
                {
                    d[i][j]=d[i-1][j]*a%MOD;
                }
                else
                {
                    d[i][j]=(a*d[i-1][j]+b*d[i][j-1])%MOD;
                }
            }
        }
    }
    return d[n][m];
}

int main() {
    int T;
    scanf("%d",&T);
    ull a,b,k,n,m;
    for(int i=0;i<T;i++)
    {
        scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
        printf("case #%d:\n%llu\n",i,find(a,b,n,m));
    }
    return 0;
}
