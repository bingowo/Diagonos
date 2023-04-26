#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    if ((x+y)%2==0)
    {
        printf("-1\n");
        return 0;
    }
    int step = 0;
    while (x||y)
    {
        if (!x&&y) {if (y>0) y--; else y++; step++; y /= 2;}
        else if (x&&!y) {if (x>0) x--; else x++; step++; x/=2;}
        else if (!(x&1)&&(y&1))
        {
            long long temp = x/2+(y-1)/2;
            if (temp&1) y--; else y++;
            x /= 2; y /= 2;
            step++;
        }
        else if (!(y&1)&&(x&1))
        {
            long long temp = y/2+(x-1)/2;
            if (temp&1) x--; else x++;
            x /= 2; y /= 2;
            step++;
        }
    }
    printf("%d\n",step);
    return 0;
}