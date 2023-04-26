#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int s[210][210];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        scanf("%d",&s[i][j]);
    int count=0;
    for(int x0=1;x0<=n;x0++)
        {
            for(int y0=1;y0<=m;y0++)
            {
                long long a=s[x0][y0];
                for(int r=1;x0-r>0&&y0-r>0;r++)
                {
                    int lb=y0-r;
                    int rb=y0;
                    for(int y=lb;y<=rb;y++)
                        a+=s[x0-r][y];
                    if(a>=k) count++;
                }
                a=s[x0][y0];
                for(int r=1;x0+r<=n&&y0-r>0;r++)
                {
                    int lb=y0-r;
                    int rb=y0;
                    for(int y=lb;y<=rb;y++)
                        a+=s[x0+r][y];
                    if(a>=k) count++;
                }
                a=s[x0][y0];
                for(int r=1;x0-r>0&&y0+r<=m;r++)
                {
                    int lb=y0;
                    int rb=y0+r;
                    for(int y=lb;y<=rb;y++)
                        a+=s[x0-r][y];
                    if(a>=k) count++;
                }
                a=s[x0][y0];
                for(int r=1;x0+r<=n&&y0+r<=m;r++)
                {
                    int lb=y0;
                    int rb=y0+r;
                    for(int y=lb;y<=rb;y++)
                        a+=s[x0+r][y];
                    if(a>=k) count++;
                }
            }
        }
        printf("%d",count);

    return 0;
}
