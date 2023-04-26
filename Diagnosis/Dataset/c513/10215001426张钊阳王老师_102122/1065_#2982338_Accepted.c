#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int a, n, m, x;
    scanf("%d%d%d%d", &a, &n, &m, &x);
    int up[25], down[25], sum[25];
    up[1] = a, down[1] = 0, sum[1] = a, sum[2] = a;
    for( int t = 0 ; t <= m ; t++)
    {
        up[2] = t, down[2] = t;
        for( int i = 3 ; i <= n ; i++)
        {
            up[i] = up[i-1] + up[i-2];
            down[i] = up[i-1];
            sum[i] = sum[i-1] + up[i] - down[i];
        }
        if( sum[n-1] == m )
        {
            printf("%d", sum[x]);
            break;
        }
    }
}
