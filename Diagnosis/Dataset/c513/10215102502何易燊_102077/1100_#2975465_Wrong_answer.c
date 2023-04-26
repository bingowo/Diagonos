#include <stdio.h>

int main()
{
    char s[101]  = {}; scanf("%s",s);
    int n; scanf("%d",&n);
    int block[202][202] = {}; block[101][101] = 1;
    int sign_x = 101, sign_y = 101;
    int dx = 0, dy = 0;
    int xmax = 101, xmin = 101, ymax = 101, ymin = 101;
    for (int i=0;s[i];i++)
    {
        if (s[i]=='U') {sign_y++; dy++;}
        else if (s[i]=='D') {sign_y--; dy--;}
        else if (s[i]=='R') {sign_x++; dx++;}
        else if (s[i]=='L') {sign_x--; dx--;}
        block[sign_x][sign_y] = 1;
        if (sign_x>xmax) xmax = sign_x;
        if (sign_x<xmin) xmin = sign_x;
        if (sign_y>ymax) ymax = sign_y;
        if (sign_y<ymin) ymin = sign_y;
    }
    while (n--)
    {
        int ans = 0;
        int x,y; scanf("%d %d",&x,&y);
        x += 101; y += 101;
        int step = 0;
        if (dx==0&&dy==0)
        {
            if (block[x][y]) {printf("Yes\n"); continue;}
            else {printf("No\n"); continue;}
        }
        else if (dx==0&&dy!=0)
        {
            step = (y-101)/dy;
            y -= step*dy;
            x -= step*dx;
        }
        else if (dx!=0)
        {
            step = (x-101)/dx;
            x -= step*dx;
            y -= step*dy;
        }
        while (x>=xmin&&x<=xmax&&y>=ymin&&y<=ymin)
        {
            if (block[x][y]) ans = 1;
            x += dx, y += dy;
        }
        x -= dx, y -= dy;
        while (x>=xmin&&x<=xmax&&y>=ymin&&y<=ymin)
        {
            if (block[x][y]) ans = 1;
            x -= dx, y -= dy;
        }
        if (ans) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}