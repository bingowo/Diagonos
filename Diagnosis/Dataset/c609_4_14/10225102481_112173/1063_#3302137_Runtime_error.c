#include <stdio.h>
#include <stdlib.h>

long long func(long long a)
{
    long long arr[100];
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    for(int i=4;i<100;i++)
    {
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4];
    }
    return arr[a];
}

int main()
{
   int T;
   scanf("%d",&T);
   while((T--)!=0)
   {
       long long a;
       scanf("%d\n",&a);
       printf("%lld\n",func(a));
   }
}