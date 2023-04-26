#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for( int i = 0 ; i < n ; i ++)
        scanf("%d",&a[i]);
    int j, k, temp;
    for( j = 0 ; j < n ; j++)
    {
        for( k = 0 ; k < n - j - 1 ; k++ )
        {
            if( a[n] > a[ n + 1 ] )
            {
                temp = a[n];
                a[n] = a[n+1];
                a[n+1] = temp;
            }
        }
    }

    int sum = 0;
    for ( int cnt = 0 ; cnt < n/2 ; cnt++)
        sum += abs( a[2*cnt] - a[2*cnt + 1]);
    printf("%d\n",sum);
}
