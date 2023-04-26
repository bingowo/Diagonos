#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int count(int n,int m)
{
    if(n < m) return 0;
    if(n == m) return 1;

    return 2 * count(n - 1,m) + pow(2, n-m-1) - count(n - m - 1,m);
}







int main()
{
   int n,m,i,j;
   for(i=0;;i++){
    scanf("%d%d",&n,&m);
    if(n<0) break;
    j=count(n,m);
    printf("%d\n",j);


   }


   return 0;

}