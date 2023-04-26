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
       int a,b,c;
       scanf("%d%d",&a,&b);
       c=b;
       long long int data1=1;
       for(int k=1;k<=b;k++)
       {data1=data1/k*a;
       a--;}
        

       printf("case #%d:\n",i);
       printf("%lld\n",data1);
       
   }
   return 0;
}