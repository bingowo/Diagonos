#include <stdio.h>
#include <stdlib.h>
#define MOD 10007 

int cmod[1001][1001];

long long qmod(int a,int n,int p)
{
    if (n==0) return 1;
    else if (n%2==1) return qmod(a,n-1,p)*a%p;
    else
    {
        long long temp = qmod(a,n/2,p)%p;
        return temp*temp%p;
    }
}

void init()
{
    for (int i=0;i<1001;i++)
    {
        cmod[i][i] = 1;
        cmod[i][0] = 1;
        for (int j=1;j<i;j++)
        {
            cmod[i][j] = cmod[i-1][j]+cmod[i-1][j-1];
            if (cmod[i][j]>=10007) cmod[i][j] -= 10007;
        }
    }
}

int main()
{
    int T; scanf("%d",&T);
    init();
    for (int i=0;i<T;i++)
    {
        int a,b,k,n,m;
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        int min = (n>m)?m:n;
        long long ccmod = cmod[k][min];
        long long mod1 = qmod(a,n,10007);
        long long mod2 = qmod(b,m,10007);
        long long ans = ((mod1*mod2%10007)*ccmod)%10007;
        printf("case #%d:\n%lld\n",i,ans);
    }
    system("pause");
    return 0;
}