#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define N 10007

long long int find_xi(long long int a,long long int b,long long int n,long long int m)
{
    int i,j;
    long long int xi[1007][1007] = {1};
    for(i = 0; i <= n; i++)
        for(j = 0; j <= m; j++)
    {
        if(i + j)
     {
        if(i == 0)xi[i][j] = (xi[i][j-1]*b)%N;
        else if(j == 0)xi[i][j] = (xi[i-1][j]*a)%N;
        else xi[i][j] = (xi[i][j-1]*b + xi[i-1][j]*a)%N;
        }
    }
    return xi[n][m];
}

int main()
{
    int cas,i;
    long long int a,b,k,m,n;
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
        printf("case #%d:\n",i);
        printf("%lld\n",find_xi(a,b,n,m));
    }
    return 0;
}
