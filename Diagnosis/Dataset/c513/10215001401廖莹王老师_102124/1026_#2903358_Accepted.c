#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
   int n,i;
   int a[100005]={0};
   long long sum=0;
   scanf("%d",&n);
   for(i=0;i<n;i++)
    scanf("%d",&a[i]);
   qsort(a,n,sizeof(a[0]),cmp);
   for(i=0;i<n;i=i+2)
    sum=sum+abs(a[i]-a[i+1]);
   printf("%lld",sum);
    return 0;
}
