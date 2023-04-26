#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int r,c,n,k;
        scanf("%d %d %d %d",&r,&c,&n,&k);
        int a[r][c];
        for(int x=0;x<r;x++)
            for(int y=0;y<c;y++)
            a[x][y]=0;
        for(int k=0;k<n;k++)
        {
            int m,l;
            scanf("%d %d",&m,&l);
            a[m-1][l-1]=1;
        }
        printf("case #%d:\n",i);
        if(n<k)printf("0\n");
        else
        {
            int sum=0;
            for(int x1=0;x1<r;x1++)
                for(int y1=0;y1<c;y1++)
            {
                for(int x2=x1;x2<r;x2++)
                    for(int y2=y1;y2<c;y2++)
                {
                    int ans=0;
                    for(int x=x1;x<=x2;x++)
                        for(int y=y1;y<=y2;y++)
                    {
                        if(a[x][y]==1)ans++;
                    }
                    if(ans>=k)sum++;
                }
            }
            printf("%d\n",sum);
        }

    }
    return 0;
}
