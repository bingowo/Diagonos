#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    int min;
    int res=0;
    while(x > 0 && y > 0)
    {
        min = x < y ? x : y;
        res = res + 4 * min;
        if(min == x)
            y -= x;
        else x -= y;
    }
    printf("%d",res);

    return 0;
}