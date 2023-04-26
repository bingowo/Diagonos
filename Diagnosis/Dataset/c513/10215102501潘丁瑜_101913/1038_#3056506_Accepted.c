#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int a[200][200]={0};
    int i,j;
    for(i = 0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    }
    int x0,y0,y;
    int r=0,lb=0,rb=0,ans=0;//r为延申边长度
    long long s=0;
    //角在右上角
    for(x0=0;x0<n;x0++)
    {
        for(y0=0;y0<m;y0++)
        {
            s=a[x0][y0];
            for(r=1;x0-r>=0&&y0-r>=0;r++)
            {
                lb=y0-r;
                rb=y0;//计算当前行边界
                for(y=lb;y<=rb;y++)
                {
                    s+=a[x0-r][y];
                }
                if(s>=k) ans++;
            }
        }
    }
    //角在左上角
    for(x0=0;x0<n;x0++)
    {
        for(y0=0;y0<m;y0++)
        {
            s=a[x0][y0];
            for(r=1;x0-r>=0&&y0+r<m;r++)
            {
                lb=y0;
                rb=y0+r;
                for(y=lb;y<=rb;y++)
                {
                    s+=a[x0-r][y];
                }
                if(s>=k)ans++;
            }
        }
    }
    //角在右下角
    for(x0=0;x0<n;x0++)
    {
        for(y0=0;y0<m;y0++)
        {
            s=a[x0][y0];
            for(r=1;x0+r<n&&y0-r>=0;r++)
            {
                lb=y0-r;
                rb=y0;//计算当前行边界
                for(y=lb;y<=rb;y++)
                {
                    s+=a[x0+r][y];
                }
                if(s>=k) ans++;
            }
        }
    }
    //角在左下方
    for(x0=0;x0<n;x0++)
    {
        for(y0=0;y0<m;y0++)
        {
            s=a[x0][y0];
            for(r=1;x0+r<n&&y0+r<m;r++)
            {
                lb=y0;
                rb=y0+r;//计算当前行边界
                for(y=lb;y<=rb;y++)
                {
                    s+=a[x0+r][y];
                }
                if(s>=k) ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}