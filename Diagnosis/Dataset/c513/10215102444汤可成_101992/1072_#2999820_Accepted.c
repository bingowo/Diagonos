#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int path(long x, long y)
{
    x = x<0?(-1)*x:x;
    y = y<0?(-1)*y:y;
    if(x == 0 &&y == 0)
    {
        return 0;
    }
    else if(x%2 == y%2)
    {
        return -1;
    }
    else
    {
        long p = 1;
        for(int i = 1; i<=41; i++)
        {
            p *= 2;
            if(p>=(x+y+1))
            {
                return i;
                break;
            }
        }
    }
}

void ShowPath(long x, long y, int p)
{
    char dir[41] = {0};
    int cnt = 0;
    while(x!=0 || y!= 0)
    {
        if(labs(x) > labs(y))
        {
            if(x>0)
            {
                dir[cnt++] = 'E';
                x -= (1l<<(--p));
            }
            else
            {
                dir[cnt++] = 'W';
                x += (1l<<(--p));
            }
        }
        else
        {
            if(y>0)
            {
                dir[cnt++] = 'N';
                y -= (1l<<(--p));
            }
            else
            {
                dir[cnt++] = 'S';
                y += (1l<<(--p));
            }
        }
    }
    for(cnt--; cnt>=0; cnt--)
    {
        printf("%c", dir[cnt]);
    }
}

int main()
{
    long x = 0, y = 0;
    scanf("%ld %ld", &x, &y);
    int p = path(x,y);
    printf("%d\n", p);
    if(p>0) ShowPath(x, y, p);
    return 0;
}
