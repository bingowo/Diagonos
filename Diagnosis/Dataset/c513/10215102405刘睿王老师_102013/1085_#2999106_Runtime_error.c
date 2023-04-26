#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1002
char a[max] ; 
char b[max] ; 
void reserve_string( char t[max] )  
{
	int l = strlen( t ) , i ; 
	char tt ; 
	for ( i = 0 ; i <= l / 2 ; ++ i ) 
	{
		tt = t[i] ;
		t[i] = t[ l - 1 - i ] ;
		t[ l - 1 - i ] = tt ; 
	}
}
int main()
{
	int i = 0 ; 
	while( scanf("%s %s", a ,b )!= EOF ) 
	{
		reserve_string( a ) ; 
		reserve_string( b ) ; 
		for ( i = 0 ; a[i] != '/0' || b[i] != '/0' ; ++ i ) 
		{
			if( b[i] == '/0' ) 
			{
				b[i+1] = '/0' ;
				b[i] = '0' ; 
			}
			if ( a[i] == '/0' ) 
			{
				a[i+1] = '/0' ; 
				a[i] = '0';  
			}
			a[i] = a[i] + b[i] - '0' ; 
			if ( a[i] > '9' ) 
			{
				if ( a[i+1] == '/0' )  
				{
					a[i+2] = '/0' ; 
					a[i+1] = '0' ; 
				}
				a[i+1] += (int)(a[i] - '0') / 10 ; 
				a[i] = (int)(a[i] - '0') % 10 + '0' ; 
			}
		}
		reserve_string( a ) ; 
		printf("%s/n", a) ; 
	}
	return 0 ;
}

//Error code 
