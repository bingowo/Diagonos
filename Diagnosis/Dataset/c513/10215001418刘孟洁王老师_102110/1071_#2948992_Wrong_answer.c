#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define N 10007

int find_xi(int a,int b,int n,int m)
{
    int i,j;
    int xi[1007][1007] = {1};
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
    int a,b,k,m,n;
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        printf("case #%d:\n",i);
        printf("%d\n",find_xi(a,b,n,m));
    }
    return 0;
}
