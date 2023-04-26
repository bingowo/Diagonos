#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int h=0;h<t;h++)
    {
        int r,c,n,k;
        scanf("%d%d%d%d",&r,&c,&n,&k);
        int a[10][10];
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            a[i][j]=0;
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x-1][y-1]=1;
        }
        int count=0;
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<r;j++)
            {
                for(int x=0;i+x<c;x++)
              {
                for(int y=0;y+j<r;y++)
                {
                    int ans=0;
                    for(int k=i;k<=x+i;k++)
                        for(int l=j;l<=y+j;l++)
                        ans+=a[l][k];
                    if(ans>=k) count++;
                }
              }
            }
        }
        printf("case #%d:\n",h);
        printf("%d\n",count);
    }
    return 0;
}
