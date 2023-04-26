#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

long long int tb(int x)
{
    long long int a[x+1];
        a[0]=0;
        a[1]=1;
        a[2]=1;
        for(int k=3;k<=x;k++)
        
        return a[x];
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        long long int t;
        scanf("%d",&x);
        t=tb(x);
        printf("case #%d:\n",i);
        printf("%lld\n",t);
    }
    
    return 0;
}