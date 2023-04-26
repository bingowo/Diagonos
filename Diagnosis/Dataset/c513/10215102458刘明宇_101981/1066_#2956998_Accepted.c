#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//#define DEBUG
typedef unsigned int U32;
U32 *data, *step;
int n,p,m,t;
U32 size;

void Print ( U32 *p )
{
#ifdef DEBUG
 int i,j;
 char s[1024], *ps = s;
 for ( i = 0; i < n; i++ )
 {
  for ( j = 0; j < n; j++ )
  {
   ps += sprintf ( ps, "%d ", *p++ );
  }
  *ps++ = '\n';
 }
 *ps = 0;
 puts ( s );
#endif
}

void Init ( void )
{
 int i;
 size = sizeof(U32) * n * n;
 data = (U32*) malloc ( size );
 step = (U32*) malloc ( size );
 memset ( step, 0, size );
 for ( i = 0; i < n; i++ )
 {
  int l,r;
  l = i - 1; r = i + 1;
  if ( l >= 0 )
   step[i*n+l] = 1;
  if ( r < n )
   step[i*n+r] = 1;
 }
 memcpy ( data, step, size );
 Print ( data );
}

void End ( void )
{
 free ( data );
 free ( step );
}

void Calc ( void )
{
 int i,j,k;
 U32 *tmp = (U32*) malloc ( sizeof(U32) * n * n );
 while ( --m > 0 )
 {
  memcpy ( tmp, data, size );
  for ( i = 0; i < n; i++ )
  {
   for ( j = 0; j < n; j++ )
   {
    U32 sum = 0;
    for ( k = 0; k < n; k++ )
     sum += tmp[i*n+k] * step[k*n+j];
    data[i*n+j] = sum;
   }
  }
  Print ( data );
 }
 free ( tmp );
}

void Show ( void )
{
 int r,c;
 r = p - 1;
 c = t - 1;
 printf ( "%d\n", data[r*n+c] );
}

int main ( void )
{
 int s;
 scanf ( "%d", &s );
 while ( s-- > 0 )
 {
  scanf ( "%d %d %d %d", &n, &p, &m, &t );
  Init();
  Calc();
  Show();
  End();
 }
}