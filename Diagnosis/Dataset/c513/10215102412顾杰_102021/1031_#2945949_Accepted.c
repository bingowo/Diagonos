#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int cmpa(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int cmpb(const void*a,const void*b)
{
    return -cmpa(a,b);
}
int main()
{
   int n,k,j,i,a[1000],b[1000];
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       int ans=0;
       scanf("%d",&k);
       for(j=0;j<k;j++)scanf("%d",&a[j]);
       for(j=0;j<k;j++)scanf("%d",&b[j]);
       qsort(a,k,sizeof(a[0]),cmpa);
       qsort(b,k,sizeof(a[0]),cmpb);
       for(j=0;j<k;j++)ans+=a[j]*b[j];
       printf("case #%d:\n%d\n",i,ans);
   }
}
