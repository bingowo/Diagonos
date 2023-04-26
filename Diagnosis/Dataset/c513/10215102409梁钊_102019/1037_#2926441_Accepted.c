#include<stdio.h>
#include<stdlib.h>

int cmp(const void* _a , const void* _b)
{
    long long* a = (long long*)_a ; long long* b = (long long*)_b ;
    return *b - *a >= 0 ? 1 : -1 ;
}

int main()
{
    int n , m ;
    scanf("%d %d",&n,&m) ;
    long long nums[n] ;
    for(int i = 0 ; i != n ; i++){
        scanf("%lld",&nums[i]) ;
    }
    if(m==1) printf("0") ;
    else{
        qsort(nums,n,sizeof(nums[0]),cmp) ;
        long long result = 0 ;
        long long least = 0 ;

        for(int i = 1 ; i < m ; i++){
            least += nums[0] - nums[i] ;
        }
        result = least ;
        for(int i = 1 ; i <= n - m ; i++){
            result = result + nums[i] - nums[i+m-1] - (nums[i-1] - nums[i]) * (m - 1) ;
            if(result<least) least = result ;
        }
        printf("%lld",least) ;
    }
}