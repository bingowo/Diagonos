#include <stdio.h>
#include <limits.h>
#define M 100+2
#define N 100
int C(int L,int R,int(*a)[N],int n)
{
    int r,i,j,min;
    for(r=j=0; j<n; j++)
    {
        for(min=INT_MAX,i=L; i<=R; i++)if(a[i][j]<min)min=a[i][j];
        r+=min;
    }
    return r;
}
int E(int L,int R,int(*c)[N])
{
    int i,x,y,t;
    static int e[M][M];
    for(y=2; y<=R; y++)
        for (x=y-1; x>=1; x--)
        {
            e[x][y]=INT_MAX;
            for (i=x; i<y; i++)
                if((t=e[x][i]+e[i+i][y]+2*(c[x][i]+c[i+i][y]-2*c[x][y]))<e[x][y]) e[x][y]=t;
        }
    return e[L][R];
}
int main()
{
    int i,j,m,n,a[M][N]={0};
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)for(j=0;j<n;j++)scanf("%d",&a[i][j]);
    for(i=1;i<=m;i++)for(j=i;j<m;j++)c[i][j]=C(i,j,a,n);
    printf("%d\n",E(1,m+1,c));
    return 0;
}