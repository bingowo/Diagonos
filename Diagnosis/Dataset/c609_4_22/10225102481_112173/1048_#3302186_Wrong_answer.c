#include <stdio.h>
#include <stdlib.h>

long long int func(long long int a)
{
    long long int arr[200];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=a;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[a];
}

int main()
{
   int T;
   scanf("%d",&T);
   for(int i=0;i<T;i++)
   {
       long long int a;
       scanf("%lld\n",&a);
       printf("case #%d:\n",i);
       printf("%lld\n",func(a));
   }
}
