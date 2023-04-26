#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cas, n, p, m, t, cnt;

void haozi(int level, int min)
{
    if(min<=0)
    {
        if(level==t)
            cnt++;
        return;
    }
    if(level==1)
        haozi(2, min-1);
    else if(level==n)
        haozi(n-1, min-1);
    else
    {
        haozi(level-1, min-1);
        haozi(level+1, min-1);
    }
}

int main()
{
    scanf("%d",&cas);
    for(int i=0; i<cas; i++)
    {
        cnt=0;
        scanf("%d%d%d%d",&n, &p, &m, &t);
        haozi(p, m);
        printf("%d\n", cnt);
    }
}
