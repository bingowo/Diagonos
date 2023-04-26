#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    long long x, y, energy = 0;
    scanf("%lld%lld",&x, &y);
    while(y)
    {
        if( x == y )
        {
            energy = 4 * x;
            break;
        }
        if( y == 1 )
        {
            energy = 4 * x;
            break;
        }

        energy += 4 * y;
        x = ( x - y ) > y ? ( x - y ) : y;
        y = ( x - y ) < y ? ( x - y ) : y;
    }
    printf("%lld",energy);
}
