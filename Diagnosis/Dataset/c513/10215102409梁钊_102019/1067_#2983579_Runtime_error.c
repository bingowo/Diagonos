#include<stdio.h>

long long fibonacci(int x) 
{
    long long a[x+1] ;
    a[0] = 0 ;
    a[1] = 1 ;
    a[2] = 1 ;
    for(int i=3; i<x+1; i++)
        a[i] = a[i-1] + a[i-2] + a[i-3] ;
    return a[x] ;
}

int main()
{
    int n ;
    scanf("%d",&n) ;
    for(int i=0; i!=n; i++){
        int t ;
        scanf("%lld",&t) ;
        printf("case #%d:\n%lld\n",i,fibonacci(t));
    }
}
