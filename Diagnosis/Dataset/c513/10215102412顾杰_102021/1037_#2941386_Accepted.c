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
   unsigned long long ans=2*9223372036854775807,t;
   scanf("%d%d",&n,&m);
   for(i=0;i<n;i++)scanf("%lld",p++);
   qsort(p0,n,sizeof(long long),cmp);
   p=p0+m-1;t=(m-1)*(*p);for(long long k=1;k<m;k++)t-=*(p-k);ans=t;
   while(p-p0+1<=n)
    {
        p++;
        t-=*(p-1)-*(p-m);
        t+=(m-1)*(*p-*(p-1));
        if(t<ans)ans=t;
    }
   printf("%llu",ans);
   free(p0);
}
