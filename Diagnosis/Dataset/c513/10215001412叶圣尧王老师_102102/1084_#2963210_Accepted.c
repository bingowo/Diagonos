#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

long long f(long long a,long long n)
{
    if(n==0)return 1;
    else if(n==1)return a;
    else if(!(n%2)) return f(a*a,n/2);
    return f(a*a,n/2)*a;
}

int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        long long a,n;
        printf("case #%d:\n",t);
        scanf("%lld",&n);
        
        printf("%lld\n",f(2,n));
    }
}