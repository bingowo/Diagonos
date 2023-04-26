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
        if( ! x%y )
        {
            energy = 4 * x;
            break;
        }

        energy += 4 * y;
        long long a = x, b = y;
        x = ( a - b ) >= b ? ( a - b ) : b;
        y = ( a - b ) < b ? ( a - b ) : b;
    }
    printf("%lld",energy);
}
