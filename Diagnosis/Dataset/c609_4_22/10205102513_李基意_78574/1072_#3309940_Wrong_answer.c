#include<stdio.h>
#include<stdlib.h>
long long int c[1005][1005];

void init()
{
    c[0][0]=1;
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
        s=(s*a)%10007;
        if(a==0) break;
    }
    for(int cnt=0;cnt<m;cnt++)
    {
        if(b==0) break;
        s=(s*b)%10007;
    }
    if(s)
        printf("%lld\n",s);
    else
        printf("1");
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