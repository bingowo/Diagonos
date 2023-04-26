#include <stdio.h>
#include <stdlib.h>

int main()
{
    long x = 0, y = 0;
    scanf("%ld %ld", &x, &y);
    x = x<0?(-1)*x:x;
    y = y<0?(-1)*y:y;
    if(x == 0 &&y == 0)
    {
        printf("0\n");
    }
    else if(x%2 == y%2)
    {
        printf("-1\n");
    }
    else
    {
        long p = 1;
        for(int i = 1; i<=41; i++)
        {
            p *= 2;
            if(p>=(x+y+1))
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
