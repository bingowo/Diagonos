#include <stdio.h>
#include <stdlib.h>
int main()
{
   int x,y,ans=0,temp;
   scanf("%d %d",&x,&y);

   while(x%y!=0)
   {
      temp=y;
      y=x%y;
      x=temp;
      ans+=(x/y)*4*y;
   }
   if(x%y==0)
   {
       ans+=4*x;
       printf("%d",ans);
   }
   return 0;
}