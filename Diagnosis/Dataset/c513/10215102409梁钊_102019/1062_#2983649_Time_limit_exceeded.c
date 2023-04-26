#include<stdio.h>

long long step = 0 ;

void count(long long n)
{
    if(n == 0)
        step++;
    if(n >= 1){
        count(n-1) ; 
    }
    if(n >= 2){
        count(n-2) ;
    }
    if(n >= 3){
        count(n-3) ;
    }
    if(n >= 4){
        count(n-4) ;
    }
}

int main()
{
    int t ;
    scanf("%d",&t) ;
    for(int i=0; i<t; i++){
        int n ;
        scanf("%d",&n) ;
        count(n) ;
        printf("%lld",step) ;
        step = 0 ;
    }
}