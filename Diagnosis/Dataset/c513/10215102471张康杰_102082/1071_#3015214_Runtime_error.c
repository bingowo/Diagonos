#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MOD 10007
int table[1000][1000];

typedef long long int LLD;

LLD Comb(int n,int m,int a,int b)
{
    if(table[n][m] != -1)
        return table[n][m];
    LLD out;
    if(n == 0 && m == 0)
        out = 0;
    else if(n == 0 && m != 0)
        out = ((Comb(n,m - 1,a,b) % MOD) * (b % MOD)) % MOD;
    else if(n != 0 && m == 0)
        out = ((Comb(n - 1,m,a,b) % MOD) * (a % MOD)) % MOD;
    else if(n != 0 && m != 0)
        out = (((Comb(n,m - 1,a,b) % MOD) * (b % MOD)) % MOD + ((Comb(n - 1,m,a,b) % MOD) * (a % MOD)) % MOD) % MOD;
    table[n][m] = out;
    return out;
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int a,b,k,n,m;
        LLD ef;
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        memset(table,-1,sizeof(LLD) * 1000 * 1000);
        Comb(n,m,a,b);
        printf("%lld\n",table[n][m]);
        return 0;
    }
}