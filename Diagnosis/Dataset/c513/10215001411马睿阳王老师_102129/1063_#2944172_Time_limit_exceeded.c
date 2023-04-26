#include <stdio.h>




int main()
{ long long int x,y,v=0;
  scanf("%lld %lld",&x,&y);
   if(x%y==0) v=x*4;
   while(x%y!=0)
   {v+=x*4;
    x=x%y;}
 printf("%lld",v);
 return 0;

}
