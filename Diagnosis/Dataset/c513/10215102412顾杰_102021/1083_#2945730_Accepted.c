#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
   int n,i,j,k,ans=0;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       ans=0;
       scanf("%d",&k);
       for(j=1;j<=k;j++)if(j%10==5){int j0=j;while((j0%10==5)){ans++;j0/=5;};}else if(j%10==0){int j0=j;while(j0%10==0){ans++;j0/=10;};while((j0%10==5)){ans++;j0/=5;};}
       printf("case #%d:\n%d\n",i,ans);
   }
}
