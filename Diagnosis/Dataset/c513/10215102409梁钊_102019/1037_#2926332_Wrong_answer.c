#include<stdio.h>
#include<stdlib.h>

int cmp(const void* _a , const void* _b)
{
    long long* a = (long long*)_a ; long long* b = (long long*)_b ;
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
    if(m==1) printf("0") ;
    else{
        qsort(nums,n,sizeof(nums[0]),cmp) ;
        long long result = 0 ;
        long long least = 0 ;
        int idx = n-1 ;
        for(int i = idx-1 ; i != idx-m ; i--){
            least += nums[idx] - nums[i] ;
        }
        for(idx-- ; idx >= m - 1 ; idx--){
            result = result + nums[idx] - nums[idx-m-1] - (nums[idx+1] - nums[idx]) * (m - 1) ;
            if(result<least) least = result ;
        }
        printf("%lld",least) ;
    }
}