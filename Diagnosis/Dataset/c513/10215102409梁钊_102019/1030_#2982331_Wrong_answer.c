#include<stdio.h>
#include<stdlib.h>

int cmp(const void *_a , const void *_b)
{
    long long *a = (long long*)_a ; long long *b = (long long*)_b ;
    int a_h = 0 , b_h = 0 ;
    long long tmp = *a * 10 ;
    tmp = tmp > 0 ? tmp : -1 * tmp ; 
    while(tmp>=10){
        a_h = tmp / 10 ;
        tmp /= 10 ;
    }
    tmp = *b * 10 ;
    tmp = tmp > 0 ? tmp : -1 * tmp ; 
    while(tmp>=10){
        b_h = tmp / 10 ;
        tmp /= 10 ;
    }
    if(a_h == b_h)
        return *a - *b > 0 ? 1 : -1 ;
    return b_h - a_h > 0 ? 1 : -1 ;
}

int main()
{
    int t = 0 , n = 0 ;
    scanf("%d",&t) ;
    for(int i=0; i<t; i++){
        scanf("%d",&n) ;
        long long a[n] ;
        for(int j=0;j<n; j++)
            scanf("%lld",&a[j]) ;
        qsort(a,n,sizeof(a[0]),cmp) ;
        printf("case #%d:\n",i) ;
        for(int k=0; k<n; k++)
            printf("%lld ",a[k]) ;
    }
}