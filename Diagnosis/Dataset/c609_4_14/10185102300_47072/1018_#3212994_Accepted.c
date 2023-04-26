#include <stdio.h>
#include <stdlib.h>
 int cmp(const void* e1,const void* e2) { return *(int*)e1-*(int*)e2; }
int main()
{ int *x,n,i,ans; scanf("%d",&n);
   x=(int*)malloc(n*sizeof(int));
   for (i=0;i<n;i++) scanf("%d",x+i);
   qsort(x,n,sizeof(x[0]),cmp);
   for(ans=i=0;i<n;i+=2) ans+=x[i+1]-x[i];
   printf("%d\n",ans);

   return 0;
}