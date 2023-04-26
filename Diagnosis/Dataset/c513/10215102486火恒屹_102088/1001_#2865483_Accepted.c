#include<stdio.h>
#include<string.h>
int n,r,count;
void print( int x )
{
     if( x <= 9 )
         printf( "%d",x );
     else
         printf( "%c",x - 10 + 'A' );
 }
void change( int n,int r )
{
     if( n )
     {
         change( n / r, r );
         print( n % r );
     }
 }
int main( )
{   int a;
    scanf("%d",&a);
    while( scanf( "%d%d",&n,&r ) != EOF )
    {
           if( n < 0 )
               printf( "-" ),n = -n;
           change( n,r );puts( "" );
           }
    return 0;
}
