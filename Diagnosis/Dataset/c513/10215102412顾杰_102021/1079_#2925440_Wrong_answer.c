#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int cmp(const void*a,const void*b)
{
    return *(int*)a>*(int*)b?1:-1;
}
int main()
{
   int i,n,k,j,m,l,u,a[1000],a0[500*1001],x,y;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       int z=0;
       scanf("%d%d%d",&k,&m,&a[0]);
       for(j=1;j<k;j++){scanf("%d",&x);a[j]=a[j-1]+x;}
       for(x=0;x<k;x++)
       {
           a0[z++]=a[x];
           for(y=x+1;y<k;y++)a0[z++]=a[y]-a[x];
       }
       qsort(a0,z,sizeof(a0[0]),cmp);
      printf("case #%d:\n",i);
       for(j=0;j<m;j++)
       {
           scanf("%d%d",&l,&u);
           int ans=0;
           for(k=l-1;k<u;k++)ans+=a0[k];
           printf("%d\n",ans);
       }



   }

}
