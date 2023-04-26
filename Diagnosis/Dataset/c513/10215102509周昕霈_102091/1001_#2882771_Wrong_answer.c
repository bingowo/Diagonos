#include <stdio.h>
#include <stdlib.h>

int main()
{
   char table[]="012345678ABCDEFGHIJKLMNOPQRSTUVWXYZ";


   int t,i,j,k,n,r,a[33],sign;
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
       scanf("%d%d",&n,&r);
       k=0;
       sign=1;
       if(n<0)
       {
           n=-n;
           sign=-1;

       }


      do{
          j=n%r;
          a[k++]=table[j];
          n=n/r;

        }
     while(n); //n!=0
     if(sign<0)
        printf("-");
     for(k=k-1;k>=0;k--)
        printf("%c",a[k]);
    printf("\n");

   }
 return 0;
 }

