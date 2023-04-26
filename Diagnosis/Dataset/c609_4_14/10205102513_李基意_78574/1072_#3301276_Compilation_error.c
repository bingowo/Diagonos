#include<stdio.h>
#include<stdlib.h>
long long int c[1005][1005];

void init()
{
    c[0][0]=0;
    c[1][0]=1;
    c[1][1]=1;
    for(int i=2;i<1001;i++)
    {
        c[i][0]=1;
        for(int j=0;j<=i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%10007;
    }
}

void solve()
{
    int a, b, k, n, m;
    scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
    long long int s=c[k][n];
    for(int cnt=0;cnt<n;cnt++)
    {
        s=(s)%10007;
    }
    for(int cnt=0;cnt<m;cnt++)
    {
        s=(sb)%10007;
    }
    printf("%lld\n",s);
}

int main()
{
    int i,t;
    scanf("%d",&t);
    init();
    for(i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        solve();
    }
    return 0;
}