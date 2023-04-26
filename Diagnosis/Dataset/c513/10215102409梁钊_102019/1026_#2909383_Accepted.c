#include<stdio.h>
#include<stdlib.h>
#define N 100000

int cmp(const void* _a,const void*_b)
{
    long* a = (long*) _a ; long* b = (long*) _b ;
    return *a - *b >= 0 ? 1 : -1 ;
}

int main()
{
    int t ;
    scanf("%d",&t) ;
    long n[N] ; int i = 0 ;
    while(scanf("%ld",&n[i])!=EOF && getchar()!='\n') i++;
    qsort(n,t,sizeof(n[0]),cmp) ;
    long long result = 0 ;
    for(i=0;i<t;i+=2){
        long tmp = n[i] - n[i+1] ;
        if(tmp>0) result += tmp ;
        else result += -1 * tmp ;
    }
    printf("%lld",result) ;
}