#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void tran(int n , int digit)
{
 int i = 0 , a[digit] , j = 0;
 while( n > 0 )
 {
  a[i++] = n % 2;
  n /= 2;
 } 
 
 for( j = i ; j < digit ; j++)
  printf("0");
 for(; i > 0 ; i--)
  printf("%d",a[i - 1]);
}


int main()
{
 
 int a[500];
 int i = 0;
  
 char s[500];
 scanf("%s",s); 
 int len = strlen(s);
 
 printf("0001");
 
 tran(len , 10);

 for( i = 0 ; i < len ; i++)
  a[i] = s[i] - 48;
  
 int p = len / 3 , q = len % 3 , tmp;
 
 for( i = 0 ; i < p ; i++)
 {
  tmp = 100 * a[ 3 * i ] + 10 * a[3 * i + 1] + a[3 * i + 2];
  tran(tmp , 10);
  }
 
 
 if ( q == 1 )
 {
  tmp = a[len - 1];
  tran(tmp , 4);
 }  
 
 if ( q == 2 )
 {
  tmp = a[len - 1] + 10 * a[len - 2];
  tran(tmp , 7);
 }  
 
 
 return 0;
}