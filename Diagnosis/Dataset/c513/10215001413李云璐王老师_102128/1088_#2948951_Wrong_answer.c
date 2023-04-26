#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
       int a,b;
       scanf("%d%d",&a,&b);
       unsigned long long int data1=1,data2=1,ans;
       for(int k=1;k<=b;k++)
       {data1=data1*a;
       a--;
       data2=data2*k;}
       ans=data1/data2;
       printf("case #%d:\n",i);
       printf("%u\n",ans);
       
   }
   return 0;
}