#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int count(int n,int m)
{
    if(m>n) return 0;
    if(m==n) return 1;

    return 2*count(n-1,m)+pow(2,n-m)-count(n-m,m);

}







int main()
{
   int n,m,i,j;
   for(i=0;;i++){
    scanf("%d%d",&n,&m);
    if(m==-1) break;
    j=count(n,m);
    printf("%d\n",j);


   }


   return 0;

}