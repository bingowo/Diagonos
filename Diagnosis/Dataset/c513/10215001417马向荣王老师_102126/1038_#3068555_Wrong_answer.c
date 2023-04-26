#include<stdio.h>
int main()
{
    int n,m,k,ans=0;
    int a[200][200];
    long long int f[200][200]={0};
    scanf("%d %d %d\n",&n,&m,&k);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d ",&a[i][j]);
            f[i][j]+=a[i][j];
        }
    }
    for(int x0=1;x0<=n;x0++)
    {
        for(int y0=1;y0<m;y0++)
        {
            long long int s=a[x0][y0];
            for(int r=1;x0-r>0 && y0-r>0;r++)
            {
                int lb=y0-r;
                int rb=y0;
                s+=f[x0-r][rb]-f[x0-r][lb-1];
                if(s>=k) ans++;
            }
            for(int r=1;x0+r<n && y0-r>0;r++)
            {
                int lb=y0-r;
                int rb=y0;
                s+=f[x0+r][rb]-f[x0+r][lb-1];
                if(s>=k) ans++;
            }
            for(int r=1;x0-r>0 && y0+r<m;r++)
            {
                int lb=y0;
                int rb=y0+r;
                s+=f[x0-r][rb]-f[x0-r][lb+1];
                if(s>=k) ans++;
            }
            for(int r=1;x0+r<n && y0+r<m;r++)
            {
                int lb=y0;
                int rb=y0+r;
                s+=f[x0+r][rb]-f[x0+r][lb+1];
                if(s>=k) ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}