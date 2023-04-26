#include <stdio.h>
#include <stdlib.h>

int main()
{int n,m,k,sum=0;
int F[201][201]={0};
scanf("%d%d%d",&n,&m,&k);
int a[201][201]={0};
for(int i=1;i<=n;i++)
{for(int j=1;j<=m;j++)
scanf("%d",&a[i][j]);}
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
{F[i][j]=F[i][j-1]+a[i][j];}
for(int x0=1;x0<=n;x0++)
{for(int y0=1;y0<=m;y0++)
{long long s=a[x0][y0];
for(int r=1;x0-r>0&&y0-r>0;r++)
{int lb=y0-r;
int rb=y0;
s+=F[x0-r][rb]-F[x0-r][lb-1];
if(s>=k) sum++;
}
}
}
for(int x0=1;x0<=n;x0++)
{for(int y0=1;y0<=m;y0++)
{long long s=a[x0][y0];
for(int r=1;x0-r>0&&y0+r<=m;r++)
{int lb=y0;
int rb=y0+r;
s+=F[x0-r][rb]-F[x0-r][lb-1];
if(s>=k) sum++;
}
}
}
for(int x0=1;x0<=n;x0++)
{for(int y0=1;y0<=m;y0++)
{long long s=a[x0][y0];
for(int r=1;x0+r<=n&&y0+r<=m;r++)
{int lb=y0;
int rb=y0+r;
s+=F[x0+r][rb]-F[x0+r][lb-1];
if(s>=k) sum++;
}
}
}
for(int x0=1;x0<=n;x0++)
{for(int y0=1;y0<=m;y0++)
{long long s=a[x0][y0];
for(int r=1;x0+r<=n&&y0-r>0<=m;r++)
{int lb=y0;
int rb=y0-r;
s+=F[x0+r][rb]-F[x0+r][lb-1];
if(s>=k) sum++;
}
}
}
printf("%d",sum);}


