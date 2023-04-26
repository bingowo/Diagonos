#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int T,n,m,k;
int mp[205][205];

int get(int x1,int y1,int x2,int y2) //求（x1，y1）到（x2，y2）方块的总和
{
    return mp[x2][y2]-mp[x1-1][y2]-mp[x2][y1-1]+mp[x1-1][y1-1];
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            mp[i][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&mp[i][j]);
            mp[i][j]+=mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1]; //代表从（1，1）到这个（i，j）方块的总和
        }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int res[4];
            for(int p=0;p<4;p++)
                res[p]=get(i,j,i,j); //就是取该位置的值
            for(int p=1;;p++)
            {
                int flg=0;
                //构造等腰直角三角形
                if(i+p<=n&&j+p<=m)
                {
                    res[0]+=get(i+p,j,i+p,j+p); //左下直角
                    if(res[0]>=k)
                        ans++;
                    res[1]+=get(i,j+p,i+p,j+p); //右上直角
                    if(res[1]>=k)
                        ans++;
                    flg=1;
                }
                if(i+p<=n&&j-p>0)
                {
                    res[2]+=get(i+p,j-p,i+p,j); //右下直角
                    if(res[2]>=k)
                        ans++;
                    res[3]+=get(i,j-p,i+p,j-p); //左上直角
                    if(res[3]>=k)
                        ans++;
                    flg=1;
                }
                //只要符合等腰条件就不会结束
                if(!flg)
                    break;
            }
        }
    printf("%d\n",ans);
    return 0;
}
