#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[10][10];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0; cas<T; cas++)
    {
        int r,c,n,k;
        scanf("%d%d%d%d",&r,&c,&n,&k);
        memset(a,0,sizeof(a));
        for(int i=0; i<n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x-1][y-1]=1;
        }
        int sum=0;
        //枚举每一个矩形
        for(int x1=0; x1<r; x1++)//行数
        {
            for(int y1=0; y1<c; y1++)//列数
            {
                for(int x2=x1; x2<r; x2++)
                {
                    for(int y2=y1; y2<c; y2++)
                    {
                        int ans=0;
                        for(int x=x1; x<=x2; x++)
                        {
                            for(int y=y1; y<=y2; y++)
                            {
                                if(a[x][y]==1)
                                    ans++;
                            }
                        }
                        if(ans>=k) sum++;
                    }
                }
            }
        }
        printf("case #%d:\n",cas);
        printf("%d\n",sum);
    }
    return 0;
}
