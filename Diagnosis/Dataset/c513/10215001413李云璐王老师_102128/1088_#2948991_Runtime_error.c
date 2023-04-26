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
       long long int data1=1;
       for(int k=a;k>a-b;k++)
       {data1=data1*k/b;
        b--;}

       printf("case #%d:\n",i);
       printf("%lld\n",data1);
       
   }
   return 0;
}