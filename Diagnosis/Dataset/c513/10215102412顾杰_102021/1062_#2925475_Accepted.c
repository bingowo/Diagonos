#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int main()
{
   int i,n,k,j;
   long long a[50];
   a[0]=1;a[1]=2;a[2]=4;a[3]=8;
   for(i=4;i<=50;i++)a[i]=a[i-4]+a[i-3]+a[i-2]+a[i-1];
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       scanf("%d",&k);
        printf("case #%d:\n%lld\n",i,a[k-1]);

   }

}
