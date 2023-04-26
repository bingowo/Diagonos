#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int x0;
int y0;

struct point{
        int x;
        int y;
};



int distance(struct point ten)
{
    int xd=abs(ten.x-x0);
    int yd=abs(ten.y-y0);
    return xd>yd? xd:yd;
}

int main()
{
    scanf("%d %d",&x0,&y0);
    struct point goal[1000001];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&goal[i].x, &goal[i].y);
    int resd=distance(goal[0]);

    return 0;
}
