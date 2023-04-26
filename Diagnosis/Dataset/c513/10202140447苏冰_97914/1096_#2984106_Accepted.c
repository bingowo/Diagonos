#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int a[101];//起点
int b[101];//终点
int s[101][101];
int main()
{
    int T;
    scanf("%d",&T);
    int n;
    for(int cas=0;cas<T;cas++)
    {
        scanf("%d",&n);
        int flag=1;
        int x,y;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(s,0,sizeof(s));
        for(int i=0;i<n;i++)
        {
           scanf("%d %d",&x,&y);
           if(x==y || s[x][y]) continue;
           s[x][y]=1;
           if(b[x] || a[y] || a[x]) flag=0;
           a[x]=1;b[y]=1;
        }
        if(flag) printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;
}

