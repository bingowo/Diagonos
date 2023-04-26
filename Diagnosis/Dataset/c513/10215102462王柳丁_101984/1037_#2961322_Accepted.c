#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b);
int main()
{
   long long int num[1000000];
   long long int sum[1000000];
   int n,m,i;
   scanf("%d %d",&n,&m);
   for(i=0;i<n;i++){scanf("%lld",&num[i]);}
    qsort(num,n,sizeof(long long int),cmp);
   sum[0]=num[0];
   for(i=1;i<n;i++){sum[i]=sum[i-1]+num[i];}
   long long int res=0,mid=0;
   if(m==1)res=0;
   else
   {
       res=(m-1)*num[m-1]-sum[m-2];
    for(i=m;i<n;i++)
    {
        mid=(m-1)*num[i]-sum[i-1]+sum[i-m];
        if(res>mid)res=mid;
    }
   }
   printf("%lld\n",res);
    return 0;
}
int cmp(const void *a,const void *b)
{
    long long int a1=*(long long int *)a;
    long long int b1=*(long long int *)b;
    if(a1>b1)return 1;
    else return -1;
}
