#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    long long int x;
    long long int y;
}point;
int main()
{
   long long int n;
   scanf("%lld",&n);
   if(n==0)
    printf("(0,0)");
   else
   {
       point ans[n+1];
   int flag=0,temp=0,index=1;
   ans[0].x=0;
   ans[0].y=0;
   for(int i=1;;i++)
   {
       for(int k=0;k<2;k++)
       {
       temp++;
     for(int j=0;j<i;j++)
     {
         if(temp%4==1)
         {
             ans[index].y=ans[index-1].y+1;
             ans[index].x=ans[index-1].x;
             if(index==n)
             {
                 flag=1;
                 break;
             }
             index++;
         }
         else if(temp%4==2)
         {
             ans[index].y=ans[index-1].y;
             ans[index].x=ans[index-1].x-1;
             if(index==n)
             {
                 flag=1;
                 break;
             }
             index++;
         }
         else if(temp%4==3)
         {
             ans[index].y=ans[index-1].y-1;
             ans[index].x=ans[index-1].x;
             if(index==n)
             {
                 flag=1;
                 break;
             }
             index++;
         }
         else if(temp%4==0)
         {
             ans[index].y=ans[index-1].y;
             ans[index].x=ans[index-1].x+1;
             if(index==n)
             {
                 flag=1;
                 break;
             }
             index++;
         }

     }
     if(flag==1)break;
   }
   if(flag==1)break;
   }
   printf("(%lld,%lld)",ans[n].x,ans[n].y);
   }

   return 0;

}