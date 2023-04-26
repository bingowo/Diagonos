#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define N 10007

long long int find_xi(long long int a,long long int b,long long int k,long long int n,long long int m)
{
    if(m == 0)return ((long long int)(pow(a,k)))%N;
    else if(n == 0)return ((long long int)(pow(b,k)))%N;
    else return (((find_xi(a,b,k,m,n-1)%N)*(((k-n+1)*a)%N))/(n*b))%N;
}

int main()
{
    int cas,i;
    long long int a,b,k,m,n;
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&m,&n);
        printf("case #%d:\n",i);
        printf("%lld\n",find_xi(a,b,k,m,n));
        //printf("%lld\n",find_xi(a,b,k,m,n));
    }
    return 0;
}
