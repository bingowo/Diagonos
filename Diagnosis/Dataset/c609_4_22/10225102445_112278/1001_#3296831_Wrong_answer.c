#include <stdio.h>
#include <string.h>
#define N 100010
char str [ N ];
char get ( int x ) {
    if ( x < 10 ) return x + '0' ;
    else return x - 10 + 'A' ;
}
int main () {
    int T ;
    scanf ( "%d" , & T );
    while ( T -- ) {
        int n , r ;
        scanf ( "%d%d" , & n , & r );
        int cnt = 0 ;
        if ( n == 0 ) str [ cnt ++ ] = '0' ;
        while ( n ) {
            str [ cnt ++ ] = get ( n % r );
            n /= r ;
        }
        if ( cnt > N ) cnt = N ;
        for ( int i = cnt - 1 ; i >= 0 ; i -- )
            printf ( "%c" , str [ i ]);
        printf ( " \n " );
    }
    return 0 ;
}