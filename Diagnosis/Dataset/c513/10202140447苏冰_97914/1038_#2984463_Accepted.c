#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int a[200][200];
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            long long s=a[i][j];
            for(int r=1;i-r>0 && j-r>0;r++)
            {
                int y1=j-r;
                int y2=j;
                for(int k=y1;k<=y2;k++)
                {
                    s+=a[i-r][k];
                }
                if(s>=k) cnt++;
            }
            s=a[i][j];
            for(int r=1;i+r<=n && j-r>0;r++)
            {
                int y1=j-r;
                int y2=j;
                for(int k=y1;k<=y2;k++)
                {
                    s+=a[i+r][k];
                }
                if(s>=k) cnt++;
            }
            s=a[i][j];
            for(int r=1;i-r>0 && j+r<=m;r++)
            {
                int y1=j;
                int y2=j+r;
                for(int k=y1;k<=y2;k++)
                {
                    s+=a[i-r][k];
                }
                if(s>=k) cnt++;
            }
            s=a[i][j];
            for(int r=1;i+r<=n && j+r<=m;r++)
            {
                int y1=j;
                int y2=j+r;
                for(int k=y1;k<=y2;k++)
                {
                    s+=a[i+r][k];
                }
                if(s>=k) cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}

