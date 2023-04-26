#include <stdio.h>

int main()
{
    char s[101] = {}; scanf("%s",s);
    int n; scanf("%d",&n);
    int dx=0, dy=0;
    for (int i=0;s[i];i++)
    {
        if (s[i]=='U') dy++;
        else if (s[i]=='D') dy--;
        else if (s[i]=='L') dx--;
        else if (s[i]=='R') dx++;
    }
    for (int i=0;i<n;i++)
    {
        int x,y; scanf("%d %d",&x,&y);
        int flag = 0;
        int x0 = 0, y0 = 0;
        if (!x&&!y) {printf("Yes\n"); continue;} 
        for (int i=0;s[i];i++)
        {
            if (s[i]=='U') y0++;
            else if (s[i]=='D') y0--;
            else if (s[i]=='L') x0--;
            else if (s[i]=='R') x0++;
            if (!dx&&!dy)
                {if (x0==x&&y0==y) {flag = 1; break;}}
            else if (dx!=0&&dy==0)
                {if ((x-x0)%dx==0&&y==y0&&(x-x0)/dx>=0) {flag = 1; break;}}
            else if (dx==0&&dy!=0) 
                {if (x==x0&&(y-y0)%dy==0&&(y-y0)/dy>=0) {flag = 1; break;}}
            else
                {if ((x-x0)%dx==0&&(y-y0)%dy==0&&(x-x0)/dx==(y-y0)/dy&&(x-x0)/dx>=0) {flag = 1; break;}}
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}