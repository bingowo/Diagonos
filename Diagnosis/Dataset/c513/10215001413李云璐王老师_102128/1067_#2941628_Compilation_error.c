#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

long long int tb(x)
{
        long long int a[x];
        a[0]=0;
        a[1]=1;
        a[2]=1;
        a[3]=2;
        a[4]=4；
        if(x>4)  return a[x]=2*tb(x-1)-tb(x-4);
        else return a[x];
        
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        long long int x,t;
        scanf("%lld",&x);
        t=tb(x);
        printf("case #%d:\n",i);
        printf("%lld\n",t);
    }
    return 0;
}