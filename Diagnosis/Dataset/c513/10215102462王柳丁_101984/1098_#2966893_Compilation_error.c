#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int T,i;
   scanf("%d",&T);
   char a[101];
   for(i=0;i<T;i++)
   {
       scanf("%s",a);
       int n=strlen(a)/4*4,j;
       int R=n/4,B=n/4,Y=n/4,G=n/4;
       for(j=0;j<n;j++)
       {
           switch case(a[j])
           {
               case 'R':R--;break;
               case 'B':B--;break;
               case 'Y':Y--;break;
               case 'G':G--;break;
               default:break;
           }
       }
       if(n%4==0){printf("case #%d:\n%d %d %d %d\n",i,R,B,Y,G);}
   }
    return 0;
}
