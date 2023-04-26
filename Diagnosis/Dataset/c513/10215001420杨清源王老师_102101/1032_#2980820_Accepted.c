#include <stdio.h>
#include <stdlib.h>

#define N 1003
#define L 53

int num[N][L];

int cmp( const void *a, const void *b )
{
    int *x = (int*)a;
    int *y = (int*)b;
    int i;
    for ( i=0; (-1!=x[i])&&(-1!=y[i]); ++i )
    {
        if ( x[i] > y[i])
        {
            return -1;
        }
        if ( x[i] < y[i])
        {
            return 1;
        }
    }
    if ( (-1 == x[i]) && (-1 == y[i]))
    {
        return 0;
    }
    if ( -1 == y[i])
    {
        return -1;
    }
    return 1;
}

int main()
{
    int t,n,a,i,j;
    scanf("%d",&t);
    while (t-- > 0)
    {
        scanf( "%d", &n );
        for ( i = 0; i < n; ++i )
        {
            a = 1;
            for ( j = 0; -1 != a; ++j )
            {
                scanf( "%d", &a );
                num[ i ][ j ] = a;
            }
        }

        qsort( num, n, sizeof(num[0]), cmp );

        for ( i = 0; i < n; ++i )
        {
            if ( -1 != num[ i ][ 0 ] )
            {
                printf( "%d", num[ i ][ 0 ] );
                for ( j = 1; num[ i ][ j ] != -1; ++j )
                {
                    printf( " %d", num[ i ][ j ] );
                }
            }
            printf( "\n" );
        }
    }
    return 0;
}
