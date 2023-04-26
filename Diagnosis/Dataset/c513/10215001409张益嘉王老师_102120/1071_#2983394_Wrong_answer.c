#include <stdio.h>
#include <stdlib.h>
#define N 10007
#define M 1001

int f(int a,int b,int n,int m)
{
    int i,j;
    static int cun[M][M]={1};
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i+j)
            {
                if(i==0) cun[i][j]=b*cun[i][j-1]%N;
                else if(j==0) cun[i][j]=a*cun[i-1][j]%N;
                else cun[i][j]=(a*cun[i-1][j]+b*cun[i][j-1])%N;
            }

        }
    }
    return cun[n][m];

}


int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int a,b,k,n,m;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        int re;
        re=f(a,b,n,m);
        printf("case #%d:\n%d\n",i,re);
    }
    return 0;

}
