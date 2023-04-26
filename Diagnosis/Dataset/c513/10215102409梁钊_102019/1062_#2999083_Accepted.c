#include<stdio.h>

long long a[51] = {0,1,2,4,8} ;

long long count(long long n)
{
    if(n == 0)
        return 0 ;
    else if(n == 1){
        return 1 ;
    }
    else if(n == 2){
        return 2 ;
    }
    else if(n == 3){
        return 4 ;
    }
    else if(n == 4){
        return 8 ;
    }
    else{
        long long a1 = a[n-1] == 0 ? count(n-1) : a[n-1] ;
        long long a2 = a[n-2] == 0 ? count(n-2) : a[n-2] ;
        long long a3 = a[n-3] == 0 ? count(n-3) : a[n-3] ;
        long long a4 = a[n-4] == 0 ? count(n-4) : a[n-4] ;
        a[n] = a1 + a2 + a3 + a4 ;
        return a[n] ;
    }
}

int main()
{
    int t ;
    scanf("%d",&t) ;
    for(int i=0; i<t; i++){
        int n ;
        scanf("%d",&n) ;
        printf("case #%d:\n%lld\n",i,count(n)) ;
    }
}