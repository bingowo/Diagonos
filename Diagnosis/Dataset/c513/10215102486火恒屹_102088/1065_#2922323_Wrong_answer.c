#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    int noru[21][2]={0};
    noru[1][0]=1;
    noru[2][1]=1;
    for(int i=3;i<=n-1;i++)
    {
        noru[i][0]=noru[i-1][0]+noru[i-2][0];
        noru[i][1]=noru[i-1][1]+noru[i-2][1];
    }
    int iru[21][2]={0};
    iru[1][0]=1;
    iru[2][0]=1;
    for(int i=3;i<=n;i++)
    {
        iru[i][0]=iru[i-1][0]+noru[i-2][0];
        iru[i][1]=iru[i-1][1]+noru[i-2][1];
    }
    int b=(m-iru[n][0]*a)/iru[n][1];
    printf("%d",iru[x][0]*a+iru[x][1]*b);
    return 0;
}