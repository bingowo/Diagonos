#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int x;
int y;

struct point{
        int x;
        int y;
};



int distance(struct point ten)
{
    int xd=abs(ten.x-x);
    int yd=abs(ten.y-y);
    return xd>yd? xd:yd;
}

int main()
{
    scanf("%d %d",&x,&y);
    struct point goal[1000001];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&goal[i].x, &goal[i].y);
    int resd=distance(goal[0]);
    int resx=goal[0].x;
    int resy=goal[0].y;
    for(int i=1;i<n;i++)
    {
        if(distance(goal[i])<resd)
        {
            resd=distance(goal[i]);
            resx=goal[i].x;
            resy=goal[i].y;
        }
        else if(distance(goal[i])==resd&&goal[i].x<resx)
        {
            resx=goal[i].x;
            resy=goal[i].y;
        }
        else if(distance(goal[i])==resd&&goal[i].x==resx&&goal[i].y<resy)
        {
            resx=goal[i].x;
            resy=goal[i].y;
        }
    }
    printf("%d\n",resd);
    printf("%d %d",resx,resy);
    return 0;
}
