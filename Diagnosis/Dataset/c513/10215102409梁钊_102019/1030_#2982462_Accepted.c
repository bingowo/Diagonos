#include<stdio.h>
#include<stdlib.h>

int highest(long long x)
{
    int t=0;
    long long num=x;
    if(num<0) num=-num;
    while(num!=0)
    {
        t=num%10;
        num/=10;
    }
    return t;
}

int cmp(const void *_a , const void *_b)
{
    long long *a = (long long*)_a ; long long *b = (long long*)_b ;
    long long a_h = highest(*a) , b_h = highest(*b) ;
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
            printf("\n") ;
    }
}