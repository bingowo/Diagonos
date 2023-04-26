#include<stdio.h>
int main()
{int T,N,i,j,k;
 int d5=0,d25=0,d125=0,d625=0,d;
 scanf("%d",&T);
 for(i=0;i<T;i++)
  {scanf("%d",&N);
     for(j=1;j<=N;j++)
         {if(j%5==0) d5++;}
     for(j=1;j<=N;j++)
         {if(j%25==0) d25++;}
     for(j=1;j<=N;j++)
         {if(j%125==0) d125++;}
     for(j=1;j<=N;j++)
         {if(j%625==0) d625++;}
   d=d5+d25+d125+d625;
   printf("case #%d:\n",i);
   printf("%d",d);
   return 0;
 }






}
