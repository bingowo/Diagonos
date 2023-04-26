#include<stdio.h>
#include<stdlib.h>

int cmp(const void* _a , const void* _b)
{
    long* a = (long*)_a ; long* b = (long*)_b ;
    return *a - *b >= 0 ? 1 : -1 ;
}

int main()
{
    int n , m ;
    scanf("%d %d",&n,&m) ;
    long long nums[n] ;
    for(int i = 0 ; i != n ; i++){
        scanf("%lld",&nums[i]) ;
    }
    qsort(nums,n,sizeof(nums[0]),cmp) ;
    long long sel[m] ;
    for(int i = 0 ; i != m ; i++){
        sel[i] = nums[i] ;
    }
    long long result = 0 ;
    for(int i = m-2 ; i != -1 ; i--){
        result += sel[m-1] - sel[i] ;
    }
    printf("%lld",result) ;
}