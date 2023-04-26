#include <stdio.h>
#include <stdlib.h>
long long int count(int n)
{
    long long int a[51];
    a[0]=1;
    a[1]=2;
    a[2]=4;
    a[3]=8;
    for(int i=4;i<n;i++)
        a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
    return a[n-1];
}
int main()
{
   int T;
   scanf("%d",&T);
   for(int i=0;i<T;i++)
   {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,count(n));
   }
}
