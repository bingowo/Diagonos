#include<stdio.h>
int main()
{
    int n,m,k,ans=0;
    scanf("%d %d %d\n",&n,&m,&k);
    int a[n+1][m+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d ",&a[i][j]);
        }
    }
    for(int x0=1;x0<=n;x0++)
    {
        for(int y0=1;y0<m;y0++)
        {
            long long s=a[x0][y0];
            for(int r=1;x0-r>0&&y0-r>0;r++)
            {
                for(int y=y0-r;y<=y0;y++)
                    s+=a[x0-r][y];
                if(s>=k)ans++;
            }
            s=a[x0][y0];
            for(int r=1;x0-r>0&&y0+r<=m;r++)
            {
                for(int y=y0;y<=y0+r;y++)
                    s+=a[x0-r][y];
                if(s>=k)ans++;
            }
            s=a[x0][y0];
            for(int r=1;x0+r<=n&&y0-r>0;r++)
            {
                for(int y=y0-r;y<=y0;y++)
                    s+=a[x0+r][y];
                if(s>=k)ans++;
            }
            s=a[x0][y0];
            for(int r=1;x0+r<=n&&y0+r<=m;r++)
            {
                for(int y=y0;y<=y0+r;y++)
                    s+=a[x0+r][y];
                if(s>=k)ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}