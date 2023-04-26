#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int cmp(const void*a,const void*b)
{
    unsigned pa=*(unsigned*)a,pb=*(unsigned*)b;
    return pa<pb?-1:1;
}
int main()
{
   int n,m,i,j,k;
   unsigned int *p=(unsigned*)malloc(1000000*sizeof(unsigned)),*p0=p;
   long long ans=0,t;
   scanf("%d%d",&n,&m);
   for(i=0;i<n;i++)scanf("%u",p++);
   qsort(p0,n,sizeof(unsigned),cmp);
   p=p0+2;
   for(i=2;i<n;i++){t=*p*2-*(p-1)-*(p-2);if(t>ans)ans=t;}
   printf("%lld",ans);
   free(p0);
}
