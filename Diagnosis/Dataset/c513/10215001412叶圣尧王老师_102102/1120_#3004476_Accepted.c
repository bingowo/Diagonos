#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int r,c,n,k,i,j;
        scanf("%d %d %d %d",&r,&c,&n,&k);
        int a[10][10]={0},x,y;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            x--;y--;
            a[x][y]=1;
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(i==0&&j==0)continue;
                if(i==0)a[i][j]+=a[i][j-1];
                else if(j==0)continue;
                else a[i][j]+=a[i][j-1];
            }
        }
        int sum=0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                for(int k1=i;k1<r;k1++)
                {
                    for(int k2=j;k2<c;k2++)
                    {
                        int d=0;
                        for(int m=i;m<=k1;m++)
                        {
                            if(j==0)d=d+a[m][k2];
                            else d=d+a[m][k2]-a[m][j-1];
                        }
                        if(d>=k)sum++;
                    }
                }

            }
        }
        printf("%d\n",sum);
    }
}
