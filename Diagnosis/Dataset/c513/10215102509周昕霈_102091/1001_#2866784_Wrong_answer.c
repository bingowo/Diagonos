#include <stdio.h>
#include <stdlib.h>

int main()
{
   char table[]="012345678ABCDEFGHIJKLMNOPQRSTUVWXYZ";


   int t,i,j,k,n,r,ans[32],sign;
   scanf("&d",&t);
   for(i=0,sign=1;i<t;i++)
   {

       j=0;
       scanf("%d%d",&n,&r);
       if(n<0)
       {
           n=-n;
           sign=-1;

       }


      do{
      ans[j++]=n%r;

      n=n/r;

      }
     while(n); //n!=0
     if(sign==-1)
        printf("-");
     for(k=j-1;k>=0;k--)
        printf("%c",table[ans[k]]);
        printf("\n");

   }
 return 0;
 }
