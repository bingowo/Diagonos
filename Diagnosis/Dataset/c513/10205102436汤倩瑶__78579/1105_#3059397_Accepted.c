#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int map[100][100]= {0};
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&map[i][j]);
        }
    }

    int d[8]={0};
    int ans[100][100]={0};
    for(int i=1;i<m-1;i++){
        for(int j=1;j<n-1;j++)
        {
            int mid=map[i][j];

            d[7]=map[i-1][j-1]>=mid?1:0;
            d[6]=map[i][j-1]>=mid?1:0;
            d[5]=map[i+1][j-1]>=mid?1:0;
            d[4]=map[i+1][j]>=mid?1:0;
            d[3]=map[i+1][j+1]>=mid?1:0;
            d[2]=map[i][j+1]>=mid?1:0;
            d[1]=map[i-1][j+1]>=mid?1:0;
            d[0]=map[i-1][j]>=mid?1:0;
            int min=255;

            for(int k=0;k<8;k++)
            {
                int p=0;
                for(int t=0;t<8;t++)
                {
                    p=p*2+d[(k+t)%8];

                }

                if(p<min)min=p;

            }
            ans[i-1][j-1]=min;

        }
    }
    for(int i=0;i<=m-3;i++)
    {
        for(int j=0;j<n-3;j++)
        {
            printf("%d ",ans[i][j]);

        }

        printf("%d\n",ans[i][n-3]);

    }


}

