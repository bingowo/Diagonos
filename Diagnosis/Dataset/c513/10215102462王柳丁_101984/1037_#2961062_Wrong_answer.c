#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b);
int main()
{
   int num[100000];
   int sum[100000];
   int n,m,i;
   scanf("%d %d",&n,&m);
   for(i=0;i<n;i++){scanf("%d",&num[i]);}
    qsort(num,n,sizeof(int),cmp);
   sum[0]=num[0];
   for(i=1;i<n;i++){sum[i]=sum[i-1]+num[i];}
   int res=0,mid=0;
   res=(m-1)*num[m-1]-sum[m-2];
   for(i=m;i<n;i++)
   {
       mid=(m-1)*num[i]-sum[i-1]+sum[i-m-1];
       if(res>mid)res=mid;
   }
   printf("%d\n",res);
    return 0;
}
int cmp(const void *a,const void *b)
{
    int a1=*(int *)a;
    int b1=*(int *)b;
    return a1-b1;
}
