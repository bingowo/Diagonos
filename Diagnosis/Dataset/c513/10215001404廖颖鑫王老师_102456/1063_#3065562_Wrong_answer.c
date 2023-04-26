#include <stdio.h>
#include <stdlib.h>
int main()
{
  unsigned long long int x,y,ans=0,temp;
   scanf("%d %d",&x,&y);

   while(x%y!=0)
   {
     ans+=(x/y)*4*y;
     temp=y;
      y=x%y;
      x=temp;
      
   }
   if(x%y==0)
   {
       ans+=4*x;
       printf("%d",ans);
   }
   return 0;
}