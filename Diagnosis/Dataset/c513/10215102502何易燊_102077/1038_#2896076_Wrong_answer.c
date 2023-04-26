#include <stdio.h>
#include <stdlib.h>

int a[200][200] = {};
int cnt = 0;
int k,n,m;
int table[4][2] = {1,1,1,-1,-1,1,-1,-1};

int min(int a,int b)
{return a<=b? a: b;}

void judge(int x,int y,int dir,int len)
{
    if (x+(len-1)*table[dir][0]>n||x+(len-1)*table[dir][0]<1) return ;
    if (y+(len-1)*table[dir][1]>m||y+(len-1)*table[dir][1]<1) return ;
    int sum = 0;
    int len_ = len;
    for (int i=x;i!=x+(len)*table[dir][0];i+=table[dir][0])
    {
        for (int j=y;j!=y+(len_)*table[dir][1];j+=table[dir][1])
        {
            sum += a[i][j];
        }
        len_--;
    }
    if (sum>=k)
    {
        if (dir==0) cnt += min(n-x,m-y);
        else if (dir==1) cnt += min(n-x,m-1);
        else if (dir==2) cnt += min(n-1,m-y);
        else cnt += min(n-1,m-1);
        return ;
    }
    return judge(x,y,dir,len+1);
}

main()
{
    scanf("%d %d %d",&n,&m,&k);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int p=0;p<4;p++) judge(i,j,p,2);
    printf("%d\n",cnt);
    return 0;
}