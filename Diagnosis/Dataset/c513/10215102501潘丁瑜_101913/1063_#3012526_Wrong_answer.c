#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long int x,y;
    scanf("%ulld %ulld",&x,&y);
    long long int min;
    unsigned long long int res=0;
    while(x > 0 && y > 0)
    {
        min = x < y ? x : y;
        res = res + 4 * min;
        if(min == x)
            y -= x;
        else x -= y;
    }
    printf("%ulld",res);

    return 0;
}