#include<stdio.h>

long long fibonacci(long long x) 
{
    if(x==0 ) return 0 ;
    if(x==1 || x==2) return 1;
    else return fibonacci(x-1) + fibonacci(x-2) +fibonacci(x-3) ;
}

int main()
{
    int n ;
    for(int i=0; i!=n; i++){
        int t ;
        scanf("%d",&t) ;
        printf("%lld",fibonacci(t));
    }
}
