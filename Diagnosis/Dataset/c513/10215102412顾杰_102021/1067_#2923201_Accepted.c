#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int main()
{
   int n,i,k;
   unsigned long long a[75];
   a[0]=0;a[1]=1;a[2]=1;
   for(i=3;i<=74;i++)a[i]=a[i-1]+a[i-2]+a[i-3];
   scanf("%d",&n);
   for(i=0;i<n;i++){scanf("%d",&k);printf("case #%d:\n%llu\n",i,a[k]);}
}
