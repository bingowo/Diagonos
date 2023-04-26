#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int n,m,k,i,j,ans=0;scanf("%d %d %d",&n,&m,&k);int a[n+1][m+1];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)scanf("%d",&a[i][j]);
    for(int x0=1;x0<=n;x0++)
    {
        for(int y0=1;y0<=m;y0++)
        {
            long long s=a[x0][y0];
            for(int r=1;x0-r>0&&y0-r>0;r++)
            {
                for(int y=y0-r;y<=y0;y++)
                    s+=a[x0-r][y];
                if(s>=k)ans++;
            }
            for(int r=1;x0-r>0&&y0-r>0;r++)
            {
                for(int y=y0;y<=y0+r;y++)
                    s+=a[x0-r][y];
                if(s>=k)ans++;
            }
            for(int r=1;x0-r>0&&y0-r>0;r++)
            {
                for(int y=y0-r;y<=y0;y++)
                    s+=a[x0+r][y];
                if(s>=k)ans++;
            }
            for(int r=1;x0-r>0&&y0-r>0;r++)
            {
                for(int y=y0;y<=y0+r;y++)
                    s+=a[x0+r][y];
                if(s>=k)ans++;
            }
        }
    }
    printf("%d",ans);
}