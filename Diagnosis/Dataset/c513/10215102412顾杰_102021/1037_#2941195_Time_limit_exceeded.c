#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int cmp(const void*a,const void*b)
{
    long long pa=*(long long*)a,pb=*(long long*)b;
    return pa<pb?-1:1;
}
int main()
{
   int n,m,i,j;
   long long  *p=(long long*)malloc(1000000*sizeof(long long)),*p0=p;
   long long ans=9223372036854775807,t,l=ans;
   scanf("%d%d",&n,&m);
   for(i=0;i<n;i++)scanf("%lld",p++);
   qsort(p0,n,sizeof(long long),cmp);
   p=p0+m-1;
   for(i=m-1;i<n;i++)
    {
        if((*(p)-*(p-m+1))<=ans)
        {l=*(p)-*(p-m+1);t=0;for(long long k=1;k<m;k++)t+=*p-*(p-k);if(t<ans)ans=t;}
        p++;
   }
   printf("%lld",ans);
   free(p0);
}
